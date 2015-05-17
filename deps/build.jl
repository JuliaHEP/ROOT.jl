using BinDeps
@BinDeps.setup

haskey(ENV, "ROOTSYS") ||
    error("could not find environment variable ROOT, run `source /path/to/root/bin/thisroot.sh`")

haskey(ENV, "JULIA_HOME") ||
    error("could not find environment variable JULIA_HOME")

cd(joinpath(dirname(Base.source_path()), ".."))

@linux_only run(`make lib-linux`)
@osx_only run(`make lib-osx`)
@windows_only error("windows not yet supported, tested, try `make`")
