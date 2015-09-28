using BinDeps
@BinDeps.setup

const LIBJULIA = first(Libdl.dllist()[find(x->contains(x, "libjulia"), Libdl.dllist())])
println("libjulia in $LIBJULIA")
const SUFFIX = split(LIBJULIA, '.')[end]
const LIBSYS = first(Libdl.dllist()[find(x->contains(x, "sys.$SUFFIX"), Libdl.dllist())])
println("sys.ji in $LIBSYS")
const ROOTJL = Pkg.dir() * "/ROOT"
JL_INSTALL_DIR = dirname(LIBSYS)

dir = JL_INSTALL_DIR
while !isfile("$dir/LICENSE.md")
    println("looking for julia base dir in $dir")
    dir = dirname(dir)
    if !contains(dir, "julia")
        error("$dir seems no longer valid, could not find julia base dir")
    end
end
JL_INSTALL_DIR = dir

@show JL_INSTALL_DIR
const incdir_uv = readall(`find $JL_INSTALL_DIR -name "uv.h"`)|>split|>first|>dirname
const incdir_julia = readall(`find $JL_INSTALL_DIR -name "julia.h"`)|>split|>first|>dirname
const incdir_support = readall(`find $JL_INSTALL_DIR -name "libsupport.h"`)|>split|>first|>dirname
const libdir_julia = dirname(LIBJULIA)

@show incdir_uv
@show incdir_julia
@show incdir_support
@show libdir_julia

depf = open("../src/deps.h", "w+")
write(depf, "#define LIBJULIA \"$LIBJULIA\"\n")
write(depf, "#define LIBREPL \"$ROOTJL/librepl.$SUFFIX\"\n")
write(depf, "#define ROOTJL_HOME \"$ROOTJL\"\n")
write(depf, "#define SYSIMG \"$LIBSYS\"\n")
close(depf)

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
    run(`make clean lib-linux ui-linux INCDIR_UV=$incdir_uv INCDIR_JULIA=$incdir_julia LIBDIR_JULIA=$libdir_julia INCDIR_SUPPORT=$incdir_support`)
end

function compile_libs_osx()
    run(`make clean lib-osx ui-osx INCDIR_UV=$incdir_uv INCDIR_JULIA=$incdir_julia LIBDIR_JULIA=$libdir_julia INCDIR_SUPPORT=$incdir_support`)
end

#go to $JULIA_PACKAGES/ROOT
cd(joinpath(dirname(Base.source_path()), ".."))
haskey(ENV, "ROOTSYS") || install_root()
const ROOTPATH = readall(`which root-config`)|>split|>first|>dirname
@show ROOTPATH

println("Compiling support libs")
compile_libs()

print_with_color(:green, STDOUT, "ROOT.jl compiled!\n")
println("Add the following to your ~/.bashrc or ~/.bash_profile:")
println("alias rjulia=\"$ROOTJL/julia\"")
