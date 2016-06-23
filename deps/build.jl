using BinDeps
@BinDeps.setup

function install_root()
    error("could not find a ROOT6 installation")
end


function compile_libs()
    is_linux() && compile_libs_linux()
    is_apple() && compile_libs_osx()
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
const ROOTPATH = readstring(`which root-config`)|>split|>first|>dirname
@show ROOTPATH

println("Compiling support libs")
compile_libs()
print_with_color(:green, STDOUT, "ROOT.jl compiled!\n")
