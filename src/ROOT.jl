module ROOT

println("loading Cxx.jl")
using Cxx

const root_config = strip(readstring(`which root-config`))
isfile(root_config) || error("could not find ROOT")

println("loading root libraries from $(root_config)")
const ROOT_INCDIR = strip(readstring(`$root_config --incdir`))
const ROOT_LIBDIR = strip(readstring(`$root_config --libdir`))

addHeaderDir(ROOT_INCDIR, kind=C_System)

function loadlib(lib)
    libpath = "$ROOT_LIBDIR/lib$lib.so"
    isfile(libpath) || error("could not find ROOT library $lib: $libpath")
    Libdl.dlopen(libpath, Libdl.RTLD_GLOBAL)
end

for lib in [
    "Core", "RIO", "Net", "Hist", "Graf",
    "Graf3d", "Gpad", "Tree", "Rint", "Postscript",
    "Matrix", "Physics", "MathCore", "Thread", "MultiProc"
    ]
    loadlib(lib)
end

export loadlib

end #module ROOT
