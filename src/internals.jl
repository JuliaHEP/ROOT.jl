module Internals

import Libdl
import ROOT_jll


include("CxxBuild.jl")

function loadlibdeps()
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libCore"), Libdl.RTLD_GLOBAL)
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libImt"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libHist"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libGraf"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libGraf3d"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libROOTVecOps.so"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libTree.so"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libTreePlayer.so"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libRint.so"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libPostscript.so"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libPhysics.so"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libROOTDataFrame.so"))
    Libdl.dlopen(joinpath(ROOT_jll.find_artifact_dir(), "lib", "libGeom.so"))
end
end
