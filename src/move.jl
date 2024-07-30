"""
    `move!(x)`

     Transfers ownership of a C++ object. `x` and all instances of the C++
     object wrappers (`x` copies) are invalidated (Cxx.isnull(x) == true). The
     responsability to delete the object is transfered to the the caller, who
     will typically tranfer it to the underlying C++ library. The name of the
     function is inspired of the std::move C++ standard library function.

     The function is meant to be used in a call of a C++ function that takes
     ownwership of an object in order to prevent double deletion that would lead
     to a segmenation fault.

     ```
     f(move(x))
     # x should not be used anymore
     ```

     CxxRefs and CxxPtrs of x can still be used, but the user must make sure
     that the C++ objet is not deleted when using them. In the above example,
     to access to x after the function call, we can store a reference:

     ```
     xref = CxxRef(x)
     f(move(x))
     # x should not be used anymore
     # xref[] can be used until the C++ library delete x.
     ```
"""
function move!(x)
    p = CxxPtr(x)
    try
        x.cpp_object = C_NULL
    catch
        throw(ArgumentError("Argument x of move(x) must be C++ Object defined by CxxWrap"))
    end
    p
end
