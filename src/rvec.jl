@inline function Base.getindex(v::ROOT!VecOps!RVec{T}, i::Integer) where {T}
    @boundscheck checkbounds(v, i)
    ROOT._unsafe_getindex(v, i)[]
end

function Base.getindex(a::ROOT!VecOps!RVec{T}, i1::Integer, i2::Integer, is::Integer...) where {T}
    @boundscheck (i2 == 1 && all(is .== 1)) || throw(BoundsError(a, i1, i2, is...))
    Base.getindex(a, i1)
end

# Since RVec does not derive from AbstractArray, we need to implement
# ourselves the advance getindex methods, if we want to support advanced
# indexing.
Base.getindex(a::ROOT!VecOps!RVec{T}) where {T} = throw(BoundsError(a, ()))
function Base.getindex(a::ROOT!VecOps!RVec{T}, I1, Is...) where {T}

    @boundscheck all(Is .== 1) || throw(BoundsError(a, (I1, Is...)))

    #convert possible boolen vector to integer indices:
    indices = Base.to_indices(a, (I1,))[1]
    
    #allocate a new TObjArray with the same type as the original collection, and fill it with the objects at the specified indices:
    arr = ROOT!VecOps!RVec{T}(length(indices))
    ROOT._push!.(Ref(arr), getindex.(Ref(a), indices))
    
    arr
end

@inline function Base.setindex!(v::ByRef1{ROOT!VecOps!RVec{T}}, x, i::Int) where {T}
    @boundscheck checkbounds(v, i)
    ROOT._unsafe_setindex!(v, convert(T, x), i-1)[]
end

@inline function Base.push!(v::ByRef1{ROOT!VecOps!RVec{T}}, x) where {T}
    ROOT._push!(v, convert(T, x))[]
end

Base.size(v::Union{ROOT!VecOps!RVec, CxxWrap.CxxWrapCore.CxxBaseRef{<:ROOT!VecOps!RVec}}) = (length(v),)
