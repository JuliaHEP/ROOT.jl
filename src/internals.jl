module Internals

import Libdl
import ROOT_jll

include("CxxBuild.jl")

function loadlibdeps()
    rootsys_ = @static if isdefined(ROOT_jll, :find_artifact_dir) #not defined on platforms not supported by the jll
        ROOT_jll.find_artifact_dir()
    else
        rootsys
    end
    
    Libdl.dlopen(joinpath(rootsys_, "lib", "libCore"), Libdl.RTLD_GLOBAL)
    Libdl.dlopen(joinpath(rootsys_, "lib", "libImt"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libHist"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libGraf"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libGraf3d"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libROOTVecOps.so"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libTree.so"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libTreePlayer.so"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libRint.so"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libPostscript.so"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libPhysics.so"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libROOTDataFrame.so"))
    Libdl.dlopen(joinpath(rootsys_, "lib", "libGeom.so"))
end
end
