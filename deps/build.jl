using BinDeps 
@BinDeps.setup

@linux_only run(`make`)
@osx_only run(`make`)
@windows_only error("windows not yet supported, tested, try `make`")
