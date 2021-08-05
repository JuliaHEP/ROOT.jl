# This file is a part of ROOT.jl, licensed under the MIT License (MIT).

__precompile__(false)

"""
    ROOT

Basic Julia/C++ interface to the CERN ROOT system.
"""
module ROOT


using Cxx
using Libdl: Libdl

const ROOT_PKG_DIR = dirname(dirname(@__FILE__))

const deps_jl = joinpath(ROOT_PKG_DIR, "deps", "deps.jl")
if isfile(deps_jl)
    include(deps_jl)
else
    error("ROOT is not properly installed. Run Pkg.build(\"ROOT\").")
end


function load_rootlib(libname)
    for ext in ("so", "dylib")
        libpath = joinpath(ROOT_LIBDIR, "lib$libname.$ext")
        if isfile(libpath)
            Libdl.dlopen(libpath, Libdl.RTLD_GLOBAL)
            return
        end
    end
    error("could not find ROOT library $libname at \"$libpath\"")
end

addHeaderDir(ROOT_INCDIR, kind=C_System)


load_rootlib.([
    "Core", "Gpad", "Graf", "Graf3d", "Hist", "MathCore", "Matrix", "MultiProc", "Net",
    "Physics", "Postscript", "Rint", "RIO", "Thread", "Tree"
])


cxxinclude("TROOT.h")
cxxinclude("TThread.h")
cxxinclude("TVirtualMutex.h")

Base.lock(mutex::pcpp"TVirtualMutex") = @cxx mutex->Lock();
Base.unlock(mutex::pcpp"TVirtualMutex") = @cxx mutex->UnLock();

function Base.lock(f, mutex::pcpp"TVirtualMutex")
    lock(mutex)
    try
        f()
    finally
        unlock(mutex)
    end
end

export gROOTMutex
gROOTMutex() = icxx"gROOTMutex;"

export gGlobalMutex
gGlobalMutex() = icxx"gGlobalMutex;"


if gROOTMutex() == C_NULL
    icxx"TThread::Initialize();"
end



end # module
