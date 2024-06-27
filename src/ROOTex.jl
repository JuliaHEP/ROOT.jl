######################################################################
# Provides a transparent support of fit of TGraph with a Julia function.  See
# demo_fit_with_jl_func.jl for an example of such a fit without this module.
#

export TF1W, TGraphW, Get

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

# helper function used by the Get methods
function _GetHelper(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name; throwexcept = true)
    obj = Get_(file, name)               # Get object from file (TObject*)
    if obj == C_NULL
        if throwexcept
            fname = GetName(file)
            throw(KeyError("No object with name $name found in file $fname"))
        else
            return (Nothing, C_NULL)
        end
    end

    #Gets the type from the key, which works for any object including
    #for class that does not derive from a TObject.
    #Note: we used above Get_ to retrieve the object instead of ReadObj(key)
    #because it handles cases, where the object is already in memory.
    k = GetKey(file, TDirectory!DecodeNameCycle(name)...)
    typename = GetClassName(k)
    type = getproperty(ROOT, Symbol(typename))
    (type, obj)
end

#---TFile extensions-------------------------------------------------------------------------------
"""
   `Get(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name)`

    Retrieves an object from a `TFile`. If the object is not found, an `KeyError` exception is thrown.

    Note that this function is type instable. Use instead `Get(file, name, type)` is type stability is required.

    See also [`Get(file, name, type)`](@ref) and [`Get(file, name, default)`](@ref)
"""
function Get(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name)
    (type, obj) = _GetHelper(file, name)
    return CxxWrap.CxxPtr{type}(obj)[]  # Cast to the proper type
end

"""
   `Get(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name, type)`

    Retrieves an object of type `type` from a `TFile`. If the object is not found,
    an `KeyError` exception is thrown. The object data type is specified to
    ensure type stability and can be omitted if type stability is not required.

    See also [`Get(file, name)`](@ref) and [`Get(file, name, default)`](@ref)
"""
function Get(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name, type)
    (actualtype, obj) = _GetHelper(file, name)

    if ! (actualtype <: type)
        fname = GetName(file)
        #throw(ArgumentError("Type of the object $name found in $fname, $actualtype, does not match with the type argument, $type."))
        throw(TypeError(:get, "Type mismatch between retrieved object and provided type information.", type, actualtype))
    end

    return CxxWrap.CxxPtr{type}(obj)[]
end

"""
   `Get(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name, type::DataType, default::T)`

   Retrieves an object named `name` from a `TFile`. Returns `default` is the object is not found. The type of the object needs to be of the `type` specified in the 4th argument. If it is not, an `TypeError` exception is thrown.

   The function type stability can be ensured by providing as `default` the value `nothing` or another value of type `type`.

    See also [`Get(file, name)`](@ref) and [`Get(file, name)`](@ref)
"""
function Get(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name, type, default::T)::Union{type, T} where {T}
    (actualtype, obj) = _GetHelper(file, name; throwexcept = false)
    if obj == C_NULL
        return default
    elseif !(actualtype <: type)
        fname = GetName(file)
        #throw(ArgumentError("Type mismatch between the object $name found in $fname and the passed default value")
        throw(TypeError(:get, "Type mismatch between retrieved object and default value", type, T))
    else
        return CxxWrap.CxxPtr{actualtype}(obj)[]
    end
end

#See https://root.cern/doc/v632/TDirectory_8cxx.html#a942917eb21a84f137c08b7d4185f1b44
global const ROOT.TDirectory!kMaxLen = 2056

function ROOT.TDirectory!DecodeNameCycle(name)
    cycle = zeros(Int16)
    basename_ = Base.Vector{Int8}(undef, ROOT.TDirectory!kMaxLen)
    ROOT.TDirectory!DecodeNameCycle(name, basename_, cycle, ROOT.TDirectory!kMaxLen)
    GC.@preserve basename = unsafe_string(pointer(basename_))
    (basename, cycle[])
end

"""
   `getindex(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name)`

   Retrieves an object named `name` from a `TFile`. It is usually called with the syntax file[name].
   Throws an `KeyError` exception is the object is not found.

    See also [`Get(file, name)`](@ref), [`Get(file, name)`](@ref)  and [`Get(file, name, type)`](@ref)
"""
Base.getindex(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name) = Get(file, name)

"""
   `getproperty(file::T, sym::Symbol)

   Retrieves an object named `sym` (provided as a symbol) from a `TFile`. It is usually called with the syntax file.name.
   Throws an `KeyError` exception is the object is not found.

    See also [`getindex(file, name)`](), [`Get(file, name)`](@ref), [`Get(file, name)`](@ref)  and [`Get(file, name, type)`](@ref)
"""
function Base.getproperty(file::T, sym::Symbol) where {T<:Union{ROOT.TDirectoryFile, CxxPtr{<:ROOT.TDirectoryFile}}}
    if sym ∈ fieldnames(T)
        return getfield(file, sym)
    else
        return Get(file, String(sym)) 
    end
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

