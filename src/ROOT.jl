module ROOT
import Base.getindex
import Base.setindex!

using CxxWrap
import ROOTprefs
import Preferences

include("root_versions.jl")

"""
    `get_supported_root_versions() -> Vector<Version>`

Return the list of supported C++ ROOT framework versions.

"""
get_supported_root_versions() = supported_root_versions;

# utility code not exposed to the user
include("internals.jl")

"""
   `root_jll_preferred`

Value of `set_use_root_jll` preference when this module was precompiled.

"""
const root_jll_preferred = ROOTprefs.get_use_root_jll()

"""
   `rootsys`

Value of ROOTSYS preference when this module was precompiled.
"""
const rootsys = ROOTprefs.get_ROOTSYS()

"""
  `libroot_julia_path`

Path of the shared library containing the C++ code interfacing the Julia ROOT package with the C++ ROOT libraries. This library is provided by the package ROOT_julia_jll included in the dependency, when the C++ ROOT libraries are installed by the Julia package manager from the ROOT_jll package, or built on the fly (at first ROOT module import), if they are installed by another mean. 
"""
const libroot_julia_path =  Internals.CxxBuild.get_or_build_libroot_julia() 

const _libroot_compilation_failed = if isempty(libroot_julia_path) #precompilation failed
   # trick to invalidate the precompilation cache
   # and force precompilation after Julia session is restarted
   ROOTprefs._set_preference("internal_compilation_failed", true)
   ROOTprefs._load_preference("internal_compilation_failed", true)
end


"""
  `libroot_julia_from_jll`

Flag telling if the package was precompiled with the C++ wrapper library from the jll package (true) or built for an external C++ ROOT installation (false).
"""
const libroot_julia_from_jll = root_jll_preferred && Internals.CxxBuild.is_jll_supported()

# Display libroot_julia_path value on precompilation
isempty(libroot_julia_path) || (@info "ROOT wrapper library: $libroot_julia_path")

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

    @doc """
    ROOT.TVectorD

Alias for [ROOT.TVectorT{Float64}](@ref)
"""
    const TVectorD = TVectorT{Float64}
    
    include("ROOTex.jl")
    include("demo.jl")
    include("ROOTdoc.jl")
end

function __init__()
    if !ok()
        ROOTprefs._set_preference("internal_compilation_failed", nothing)
        @warn "The imported ROOT module is empty because of the error mentioned above. To import the module again after resolving the issue, a restart of Julia is required."
    else
        libroot_julia_from_jll && Internals.loadlibdeps()
        @initcxx
        global gROOT = ROOT!GetROOT()
        isinteractive() && _init_event_loop()
    end
end

@doc """
    `ok()`

Check that binding library is available and the package is functionnal.

When using C++ ROOT libraries installed externally to the Julia packager, a binding library is compiled during the ROOT package precompilation. If the library compilation fails, an error message is displayed, but the user will still be able to import the ROOT module. Use this ok() function to check after an import e.g., in a script, that the ROOT module is usable.
""" ok 

end #module
