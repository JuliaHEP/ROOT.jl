import CxxWrap: CxxRef, ConstCxxRef, CxxPtr, ConstCxxPtr

######################################################################
# Type aliases used in the documentation and extra julia code
#
"""
    ByCopy{T}

Alias for Union{T, ConstCxxRef{T}, CxxRef{T}}. This type is used in the Julia wrappers of C++ functions for arguments of C++ class type passed by copy. It allows to pass an object allocated with a contructor (e.g., T()) or an object reference returnes by another C++ function wrapper.
"""
const ByCopy{T} = Union{T, CxxRef{T}, ConstCxxRef{T}}

"""
    ByConstRef1{T}

Alias for Union{T, ConstCxxRef{<:T}, CxxRef{<:T}}. This type is used in the Julia wrappers of C++ functions for arguments of C++ class type passed by reference. It allows to pass an object allocated with a contructor (e.g., T()) or an object reference returnes by another C++ function wrapper.
"""
const ByConstRef1{T} = Union{T, CxxRef{<:T}, ConstCxxRef{<:T}}


"""
    ByRef1{T}

Alias for `Union{T, ConstCxxRef{<:T}, CxxRef{<:T}}`. This type is used in the Julia wrappers of C++ functions for arguments of C++ class type passed by reference. It allows to pass an object allocated with a contructor (e.g., T()) or an object reference returnes by another C++ function wrapper.
"""
const ByRef1{T} = Union{T, ConstCxxRef{<:T}, CxxRef{<:T}}

"""
    ByConstPtr1{T}

Alias for `Union{Ptr{Nothing}, ConstCxxPtr{<:T}, CxxPtr{<:T}}`. This type is used in the Julia wrappers of C++ functions for arguments of C++ class type  passed by pointer. It allows to pass `C_NULL` or an object pointer, returned by another C++ function wrapper created with `ConstCxxPtr(obj)` with `obj::T`.
"""
const ByConstPtr1{T} = Union{Ptr{Nothing}, ConstCxxPtr{<:T}, CxxPtr{<:T}}

"""
    ByPtr1{T}

Alias for `Union{CxxPtr{<:T}, Ptr{Nothing}}`. This type is used in the Julia wrappers of C++ functions for arguments passed by pointer. It allows to pass C_NULL or an object pointer, returned by another C++ function wrapper created with `CxxPtr(obj)` with obj::T..
"""
const ByPtr1{T} = Union{CxxPtr{<:T}, Ptr{Nothing}}

"""
    ByConstRef2{T}

Alias for Union{T, Ref{T}}, with `ConstCxxRef` and `CxxRef` defined in the `CxxWrap` module. This type is used in the Julia wrappers of C++ functions for arguments of isbit type passed by reference.
"""
const ByConstRef2{T} = Union{T, Ref{T}}

"""
    ByRef2{T}

Alias for Union{T, Ptr{T}, CxxPtr{T}, CxxRef{T}, Base.RefValue{T}, Array{T}}, with `ConstCxxRef` and `CxxRef` defined in the `CxxWrap` module. This type is used in the Julia wrappers of C++ functions for arguments of isbit type passed by reference.
"""
const ByRef2{T} = Union{T, Ptr{T}, CxxPtr{T}, CxxRef{T}, Base.RefValue{T}, Array{T}}


"""
    ByConstPtr2{T}

Alias for  Union{Ptr{Nothing}, Ref{T}, Array{T}}, with ConstCxxPtr and CxxPtr defined in the CxxWrap module. This type is used in the Julia wrappers of C++ functions for arguments of C++ class type  passed by pointer. It allows to pass an object allocated with a contructor (e.g., T()) or an object reference returnes by another C++ function wrapper.
"""
const ByConstPtr2{T} = Union{Ptr{Nothing}, Ref{T}, Array{T}}

"""
    ByPtr2{T}

Alias for `Union{T, Ptr{T}, Ptr{Nothing}, CxxPtr{T}, CxxRef{T}, Base.RefValue{T}, Array{T}}`. This type is used in the Julia wrappers of C++ functions for arguments passed by pointer. It allows to pass an object pointer returned by another C++ function wrapper or C_NULL. To pass an object instance obj, uses `CxxWrap.CxxPtr(obj)`.
"""
const ByPtr2{T} = Union{T, Ptr{T}, Ptr{Nothing}, CxxPtr{T}, CxxRef{T}, Base.RefValue{T}, Array{T}}

#
######################################################################
