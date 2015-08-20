using BinDeps
@BinDeps.setup

function install_root()
    println("could not find a ROOT6 installation, trying to install...")
    @osx_only install_root_osx()
    @linux_only install_root_linux()
end

function install_root_osx()
    run(`brew install root6`)
    error("downloaded ROOT, now re-run setup after calling `. \$(brew --prefix root6)/libexec/thisroot.sh`")
end

function install_root_linux()
    dir = joinpath(dirname(Base.source_path()), "../deps")
    cd(dir)
    if !isdir("$dir/root")
        download("http://root.cern.ch/download/root_v6.02.08.Linux-slc6-x86_64-gcc4.9.tar.gz", "root.tgz")
        run(`tar xf root.tgz`)
    end
    error("downloaded ROOT, now re-run setup after calling `source $dir/root/bin/thisroot.sh`")
end


function compile_libs()
    @linux_only compile_libs_linux()
    @osx_only compile_libs_osx()
    println("support libraries compiled")
end

function compile_libs_linux()
    run(`make clean lib-linux ui-linux`)
end

function compile_libs_osx()
    run(`make clean lib-osx ui-osx`)
end

#go to $JULIA_PACKAGES/ROOT
cd(joinpath(dirname(Base.source_path()), ".."))

haskey(ENV, "ROOTSYS") || install_root()

haskey(ENV, "MY_JULIA_HOME") ||
    error("could not find environment variable JULIA_HOME, please point it to the directory where the julia binary resides: /path/to/julia/")

compile_libs()
