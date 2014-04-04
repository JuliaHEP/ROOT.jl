using BinDeps
@BinDeps.setup

haskey(ENV, "ROOTSYS") ||
    error("could not find ROOT, run `source /path/to/root/bin/thisroot.sh`")
cd(joinpath(dirname(Base.source_path()), ".."))

@linux_only run(`make`)
@osx_only run(`make`)
@windows_only error("windows not yet supported, tested, try `make`")
