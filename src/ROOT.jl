module ROOT
import Base.getindex
import Base.setindex!

import Pkg
using CxxWrap
using ROOTprefs

include("root_versions.jl")

"""
    `get_supported_root_versions() -> Vector<Version>`

Return the list of supported C++ ROOT framework versions.

"""
get_supported_root_versions() = supported_root_versions;

#precompile_error::String = ""

# utility code not exposed to the user
include("internals.jl")

"""
  `libroot_julia_path`

Path of the shared library containing the C++ code interfacing the Julia ROOT package with the C++ ROOT libraries. This library is provided by the package libroot_julia_jll included in the dependency, when the C++ ROOT libraries are installed by the Julia package manager from the ROOT_jll package, or built on the fly (at first ROOT module import), if they are installed by another mean. 
"""
const libroot_julia_path = Internals.CxxBuild.get_or_build_libroot_julia()

"""
  `libroot_julia_from_jll`

Flag telling if the package was precompiled with the C++ wrapper library from the jll package (true) or built for an external C++ ROOT installation (false).
"""
const libroot_julia_from_jll = is_root_jll_used() && Internals.CxxBuild.is_jll_supported()

# Display libroot_julia_path value on precompilation
@info "ROOT wrapper library: $libroot_julia_path"

export cxxcompile

"""
  `cxxcompile() -> Bool`

Check that the C+ code of the package is compiled and compile it if needed. Returns true if the code is compiled, false if it wasn't and the compilation failed. Experimental, function name/API may still change.
"""
cxxcompile() = !isempty(Internals.CxxBuild.get_or_build_libroot_julia())


if(isempty(libroot_julia_path))
    ok() = false
else
    ok() = true
    
    include_dependency(libroot_julia_path)

    libroot_julia_from_jll && Internals.loadlibdeps()
    @wrapmodule(()->libroot_julia_path)
    
    include("iROOT.jl")
    
    TF1!kDefault = 0
    
    export gROOT, gSystem
    include("ROOT-export.jl")
    
    #export global function(s) taking a class instance as first parameter
    #and missing from generated file ROOT-export.jl
    export SetAddress
    export move!
    
    include("def_args.jl")
    include("move.jl")
    
    include("ROOTex.jl")
    include("demo.jl")
end

function __init__()
    if isempty(libroot_julia_path)
        @error "Failed to load or build C++ librairies and no function imported. See above error message to fix the issue.\nBEWARE: Julia needs to be restarted for the fix to take effect."
    else
        libroot_julia_from_jll && Internals.loadlibdeps()
        @initcxx
        global gROOT = ROOT!GetROOT()
        isinteractive() && _init_event_loop()
    end
end

end #module
