using BinDeps
@BinDeps.setup

haskey(ENV, "ROOTSYS") ||
    error("could not find ROOT, run `source /path/to/root/bin/thisroot.sh`")
cd(joinpath(dirname(Base.source_path()), ".."))

@linux_only run(`make lib-linux`)
@osx_only run(`make lib-osx`)
@windows_only error("windows not yet supported, tested, try `make`")
