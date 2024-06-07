######################################################################
# Provides a transparent support of fit of TGraph with a Julia function.  See
# demo_fit_with_jl_func.jl for an example of such a fit without this module.
#

export TF1W, TGraphW

import Base.convert

#---TGraph extensions------------------------------------------------------------------------------
function TGraph(x::AbstractVector{T}, y::AbstractVector{T}) where T
    TGraph(Base.length(x), 
           x isa AbstractRange ? collect(x) : x,
           y isa AbstractRange ? collect(y) : y)
end

#----Global vector (GC) ---------------------------------------------------------------------------
callbacks = Vector{CxxWrap.SafeCFunction}()

function TF1(func::Function, fname::String, xmin::Number, xmax::Number, npar::Int, ndim::Int = 1,  addToGlobList = TF1!kDefault)
    i_callback = Symbol(:_callback_, gensym("func"))
    eval(
        quote
            function $i_callback(x::ConstCxxPtr{Float64}, p::ConstCxxPtr{Float64})
                        $(func)(Base.unsafe_wrap(Vector{Float64}, x.cpp_object, $ndim),
                                Base.unsafe_wrap(Vector{Float64}, p.cpp_object, $npar))
            end
        end
    )
    cb = eval(
        quote
            CxxWrap.@safe_cfunction($i_callback,  Float64, (ConstCxxPtr{Float64}, ConstCxxPtr{Float64}))
        end
    )
    push!(callbacks, cb)
    TF1(fname, cb, xmin, xmax, npar, ndim, addToGlobList)
end

function Fit(func::Function, g::TGraph, option::String, goption::String, xmin::Number, xmax::Number, npar::Int, ndim::Int = 1, addToGlobList = 0#=TF1!kDefault=#)
    tf1 = TF1(func, string(gensym("func")), xmin, xmax, npar, ndim)
    Fit(g, CxxPtr(tf1), option, goption)
end

function Fit(g::TGraph, tf1::TF1, option::String = "", goption::String = "", rxmin::Number = 0, rxmax::Number = 0)
    Fit(g, CxxPtr(tf1), option, goption, rxmin, rxmax)
end


# Wrapper for TF1 that holds references to julia objects
struct TF1W <: TF1
    allocated::TF1Allocated
    safe_cfunc::CxxWrap.SafeCFunction
    jlfunc
    TF1W(x::TF1Allocated, y::CxxWrap.SafeCFunction, jlfunc) = new(x, y, jlfunc)
end

# Wrapper for TGraph that holds references to Julia objects
struct TGraphW <: TGraph
    allocated::TGraphAllocated
    funcs::Vector{TF1}
    TGraphW(x::TGraphAllocated) = new(x, TF1[])
end

function Base.getproperty(obj::Union{TF1W, TGraphW}, sym::Symbol)
    if sym === :cpp_object
        return obj.allocated.cpp_object
    else # fallback to getfield
        return getfield(obj, sym)
    end
end

TGraphW(args...) = TGraphW(TGraph(args...))

convert(::Type{TGraph}, x::TGraphW) = x
convert(::Type{TF1}, x::TF1W) = x

# cloures not supported on ARM architecture
#function TF1(func, fname::String, xmin::Number, xmax::Number, npar::Int, ndim::Int = 1,  addToGlobList = TF1!kDefault)
#    wrap = (x, p) -> func(Base.unsafe_wrap(Vector{Float64}, x.cpp_object, ndim),
#                          Base.unsafe_wrap(Vector{Float64}, p.cpp_object, npar))
#    safe_cfunc = CxxWrap.@safe_cfunction($wrap,  Float64, (ConstCxxPtr{Float64}, ConstCxxPtr{Float64}))
#    TF1W(TF1(fname, safe_cfunc, xmin, xmax, npar, ndim, addToGlobList), safe_cfunc, wrap)
#end

function Fit(g::TGraphW, tf1::TF1, option::String = "", goption::String = "", rxmin::Number = 0, rxmax::Number = 0)
    if contains(option, "+")
        if !(tf1 in g.funcs)
            push!(g.funcs, tf1)
        end
    else
        resize!(g.funcs, 1)
        g.funcs[1] = tf1
    end
    Fit(g, CxxPtr(tf1), option, goption, rxmin, rxmax)
end

function Fit(func, g::TGraphW, option::String, goption::String, xmin::Number, xmax::Number, npar::Int, ndim::Int = 1, addToGlobList = 0#=TF1!kDefault=#)
    tf1 = TF1(func, string(gensym("func")), xmin, xmax, npar, ndim)
    Fit(g, tf1, option, goption)
end
#
######################################################################

