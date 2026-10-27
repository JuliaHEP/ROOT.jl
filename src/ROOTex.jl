#I#####################################################################
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
@cxxdereference function _GetHelper(file::TDirectoryFile, name; throwexcept = true)
    function may_throw(msg)
        throwexcept && error(msg)
        (Nothing, C_NULL)
    end

    #using directory is required for GetKey, used afterwards, if name is a path containing directories
    #Get_ would work directly on file and using the path
    path = rsplit(name, "/", limit=2) #split directory part and tree name
    if length(path) > 1
        #convert SubString to String, as wrapped ROOT functions do not accept SubString
        name = string(path[2])
        file = GetDirectory(file, string(path[1]))
        file == C_NULL && return may_throw("No directory $(path[1:(end-1)]) in file $GetName(file)")
    end
    
    obj = Get_(file, name)               # Get object from file (TObject*)
    obj == C_NULL && return may_throw("No object with name $name found in file $(GetName(file))")

    #Gets the type from the key, which works for any object including
    #for class that does not derive from a TObject.
    #Note: we used above Get_ to retrieve the object instead of ReadObj(key)
    #because it handles cases, where the object is already in memory.
    k = GetKey(file, TDirectory!DecodeNameCycle(name)...)
    k == C_NULL && return may_throw("Object $name was not found in file $(GetName(file))")
    typename = GetClassName(k)
    type = getproperty(ROOT, Symbol(typename))
    (type, obj)
end

#--TObject derefence extension-------------------------------------------------------------------
"""
    unsafe_getindex(p::CxxWrap.CxxBaseRef{ROOT.TObject})

Dereference a TObject reference (a `CxxPtr` or `CxxRef`) that resolves the dynamce type of the object. If p is a pointer to an instance of a class `C` (e.g. `TH1D`) cast into a`TObject` pointer, then a `C` class instance is returned, and the same for a `CxxRef`.

This function should not be called for a null reference/pointer: it will crash or corrupt the memory. User will typically call the safe version [`getindex(::CxxWrap.CxxBaseRef{ROOT.TObject})`](@ref), or equivalently the `[]` dereference operator.
"""
function unsafe_getindex(p::CxxWrap.CxxBaseRef{TObject})
    type = getproperty(ROOT, Symbol(ClassName(p)))
    CxxWrap.CxxPtr{type}(p)[]
end    

"""
    getindex(p::CxxWrap.CxxBaseRef{ROOT.TObject})

Dereference a TObject reference (a `CxxPtr` or `CxxRef`) that resolves the dynamce type of the object. If p is a pointer to an instance of a class `C` (e.g. `TH1D`) cast into a`TObject` pointer, then a `C` class instance is returned, and the same for a `CxxRef`.
"""
function Base.getindex(p::CxxWrap.CxxBaseRef{TObject})
    if p == C_NULL
        throw(UndefRefError())
    else
        unsafe_getindex(p)
    end
end
#-------------------------------------------------------------------------------------------------

@inline Base.iterate(a::TSeqCollection, state=TIter(CxxPtr(a))) = Base.iterate(CxxPtr(a), state)

@inline function Base.iterate(a::CxxWrap.CxxWrapCore.CxxBaseRef{<:TSeqCollection}, state=TIter(a))
    obj = Next(state)
    CxxWrap.isnull(obj) ? nothing : (unsafe_getindex(obj), state)
end


Base.IndexStyle(a::Union{TSeqCollection, CxxWrap.CxxWrapCore.CxxBaseRef{<:TSeqCollection}}) = IndexLinear()
# eachindex support

"""
    TSparseObjIndexIter{T<:ROOT.TSeqCollection}

Index iterator for sparce TSeqCollection. The
[`eachindex(::TSeqCollection)`](@ref) function will return an object of this
type is the collection is sparse following to an element removal (see
[`RemoveAt()`](@ref)).
"""
struct TSparseObjIndexIter{T<:ROOT.TSeqCollection}
    arr::T
end


function Base.iterate(iter::TSparseObjIndexIter, state = LowerBound(iter.arr))
    @inline
    #Look for first non-null entry in the array starting from the index `state`.
    while state <= GetLast(iter.arr) && CxxWrap.isnull(At(iter.arr, state))
        state += 1
    end
    julia_index_offset = 1
    next_elt_offset = 1
    state > GetLast(iter.arr) ? nothing : (state + julia_index_offset, state + next_elt_offset)
end

Base.length(iter::TSparseObjIndexIter) = length(iter.arr)
Base.size(iter::TSparseObjIndexIter) = (length(iter),)

CxxWrap.@cxxdereference function Base.eachindex(::IndexLinear, arr::TSeqCollection)
    @inline
    #first non-null entry in the collection:
    lb = LowerBound(arr)
    while lb <= GetLast(arr) && CxxWrap.isnull(At(arr, lb))
        lb += 1
    end
    
    dense_size = GetLast(arr) + 1 - lb
    if dense_size == GetEntries(arr)
        if lb == 0
            return Base.OneTo(dense_size)
        else
            return (lb+1):(lb + dense_size)
        end
    else
        return TSparseObjIndexIter(arr)
    end
end

# Documentation for the **two** getindex methods defined below.
"""
    getindex(a::TSeqCollection, inds...)

Julia indexing support for TSeqCollection. Returns the object at index `i` in the collection. Throws a `BoundsError` exception if the index is out of bounds or if the object at that index is null (e.g. removed from the collection).

Each index argument `inds` can be single integer, a integer range, a vector of integers, or a vector of booleans. See [`Base.getindex(::AbstractArray, inds...)`](@ref) for more details on the supported indexing types.

BEWARE: indexing is 1-based in Julia, while it is 0-based in ROOT. The function will automatically convert the index to 0-based before calling the underlying ROOT function. It differs from the `At()` function, which is 0-based and will return a null pointer if the index is out of bounds or if the object at that index is null.
    """
function Base.getindex(a::TSeqCollection, i::Integer)
    p = At(a, i - 1)
    if p == C_NULL
        throw(BoundsError(a, i))
    else
        unsafe_getindex(p)
    end
end

function Base.getindex(a::TSeqCollection, i1::Integer, i2::Integer, is::Integer...)
    @boundscheck (i2 == 1 && all(is .== 1)) || throw(BoundsError(a, i1, i2, is...))
    Base.getindex(a, i1)
end
Base.getindex(a::CxxWrap.CxxWrapCore.CxxBaseRef{<:TSeqCollection}, i1::Integer, i2::Integer, is::Integer...) = Base.getindex(a[], i1, i2, is...)


# Since TSeqCollection does not derive from AbstractArray, we need to implement
# ourselves the advance getindex methods, if we want them to be supported.
Base.getindex(a::TSeqCollection) = Base.getindex(a, 1)
function Base.getindex(a::TSeqCollection, I1, Is...)

    @boundscheck all(Is .== 1) || throw(BoundsError(a, (I1, Is...)))

    #convert possible boolean vector to integer indices:
    indices = Base.to_indices(a, (I1,))[1]
    
    #allocate a new TObjArray with the same type as the original collection, and fill it with the objects at the specified indices:
    arr = ROOT.TObjArray(length(indices))
    Add.(Ref(arr), CxxPtr.(a[indices]))

    arr
end
Base.getindex(x::CxxWrap.CxxWrapCore.CxxBaseRef{<:TSeqCollection}, i::Int64) = Base.getindex(x[], i)
Base.getindex(a::CxxWrap.CxxWrapCore.CxxBaseRef{<:TSeqCollection}, I1, Is...) = Base.getindex(a[], I1, Is...)

# This will provide both `key(::ROOT.TObjArray)` and `eachindex(::ROOT.TObjArray)` methods, as
# the Base package implements `eachindex` in terms of `keys`.
@cxxdereference Base.keys(arr::TSeqCollection) = eachindex(IndexLinear(), arr)

Base.length(a::Union{TSeqCollection, CxxWrap.CxxWrapCore.CxxBaseRef{<:TSeqCollection}}) = GetEntries(a)
Base.size(a::Union{TSeqCollection, CxxWrap.CxxWrapCore.CxxBaseRef{<:TSeqCollection}}) = (length(a),)
Base.lastindex(a::Union{TSeqCollection, CxxWrap.CxxWrapCore.CxxBaseRef{<:TSeqCollection}}) = (GetLast(a) + 1)

#following definition required as CxxWrap define the eltype as TSeqCollection
#while it needs to be the type of the elements generated by the iterator
Base.eltype(a::Union{Type{<:TSeqCollection},
                     Type{<:CxxWrap.CxxWrapCore.CxxBaseRef{<:TSeqCollection}}}) = Any

#definition of IteratorSize required because for Ref. it defaults to HasShape{0}
Base.IteratorSize(::Union{Type{ROOT.TSeqCollection},
                          Type{<:CxxWrap.CxxWrapCore.CxxBaseRef{<:ROOT.TSeqCollection}}})= Base.HasLength()

Base.length(a::Union{ROOT.TTreeReaderArray,
                     CxxWrap.CxxWrapCore.CxxBaseRef{<:ROOT.TTreeReaderArray}}) = convert(Int, GetSize(a))

Base.IteratorSize(::Union{Type{ROOT.TTreeReaderArray},
                          Type{<:CxxWrap.CxxWrapCore.CxxBaseRef{<:ROOT.TTreeReaderArray}}}) = Base.HasLength();

#following definition required as CxxWrap define the eltype as TObjArray (rep. TRefArray)
#while it needs to be the type of the elements generated by the iterator
Base.eltype(::Union{Type{<:ROOT.TTreeReaderArray{T}},
                    Type{<:CxxWrap.CxxWrapCore.CxxBaseRef{<:ROOT.TTreeReaderArray{T}}}}) where {T} = T

function Base.iterate(a::TTreeReaderArray{T}, state=0) where{T}
    state >= GetSize(a) && return nothing
    (At(a,state)[], state+1) #using At() and 0-indexing instead of getindex, saves the computation time of one-to-zero indexing conversion.
    
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
const TDirectory!kMaxLen = 2056

function TDirectory!DecodeNameCycle(name)
    cycle = zeros(Int16)
    basename_ = Base.Vector{Int8}(undef, ROOT.TDirectory!kMaxLen)
    TDirectory!DecodeNameCycle(name, basename_, cycle, ROOT.TDirectory!kMaxLen)
    GC.@preserve basename_ basename = unsafe_string(pointer(basename_))
    (basename, cycle[])
end

"""
   `getindex(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name)`

   Retrieves an object named `name` from a `TFile`. It is usually called with the syntax file[name].
   Throws an `KeyError` exception is the object is not found.

    See also [`Get(file, name)`](@ref), [`Get(file, name)`](@ref)  and [`Get(file, name, type)`](@ref)
"""
#@inline _getindex(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, name::AbstractString) = Get(file, name)
#@inline _getindex(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, idx::Integer) = Base.getindex(GetListOfKeys(file), idx)
#Base.getindex(file::Union{TDirectoryFile, CxxPtr{<:TDirectoryFile}}, idx) = _getindex(file, idx)

Base.getindex(file::TDirectoryFile, name::AbstractString) = Get(file, name)
Base.getindex(file::TDirectoryFile, idx::Integer) = Base.getindex(GetListOfKeys(file), idx)

Base.length(file::Union{TDirectoryFile, CxxWrap.CxxWrapCore.CxxBaseRef{<:TDirectoryFile}}) = GetNkeys(file)

function Base.iterate(file::Union{TDirectoryFile, CxxWrap.CxxWrapCore.CxxBaseRef{<:TDirectoryFile}},
                      state = TIter(GetListOfKeys(file)))
    key = Next(state)
    CxxWrap.isnull(key) && return nothing
    obj = ReadObj(unsafe_getindex(key))
    CxxWrap.isnull(obj) ? nothing : (unsafe_getindex(obj), state)
end

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

# closures not supported on ARM architecture
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

