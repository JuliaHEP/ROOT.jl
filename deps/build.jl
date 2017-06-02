depsdir = dirname(@__FILE__)

@static if is_apple()
    OS="Darwin"
    SHEXT="dylib"
end
@static if is_linux()
    OS="Linux"
    SHEXT="so"
end

bindir = joinpath(depsdir, "usr", "bin")
if !isdir(bindir)
    info("making $bindir")
    mkpath(bindir)
end


JULIA_BASE_PATH = JULIA_HOME
while !isfile(joinpath(JULIA_BASE_PATH, "LICENSE.md"))
    JULIA_BASE_PATH = dirname(JULIA_BASE_PATH)
end
@show JULIA_BASE_PATH

function find_file(basepath, file)
    ret = split(readstring(`find $basepath -name $file`))
    ret = sort(ret, by=x->length(x))
    length(ret) > 0 || error("Could not find any matches")
    return first(ret) 
end

const INCDIR_JULIA_H = dirname(find_file(JULIA_BASE_PATH, "julia.h"))
const INCDIR_UV_H = dirname(find_file(JULIA_BASE_PATH, "uv.h"))
const INCDIR_SUPPORT_H = dirname(find_file(JULIA_BASE_PATH, "libsupport.h"))

const LIBJULIA_PATH = find_file(JULIA_BASE_PATH, "libjulia.$SHEXT")
isfile(LIBJULIA_PATH) || error("Could not find libjulia at $LIBJULIA_PATH")
JULIA_LIBDIR = dirname(LIBJULIA_PATH)

const ROOT_INCDIR = strip(readstring(`root-config --incdir`))
const ROOT_LIBDIR = strip(readstring(`root-config --libdir`))

@show INCDIR_JULIA_H 
@show INCDIR_UV_H
@show INCDIR_SUPPORT_H
@show LIBJULIA_PATH
@show JULIA_LIBDIR
@show ROOT_INCDIR
@show ROOT_LIBDIR

info("compiling ROOT-compatible julia executable")
readstring(`make OS=$OS SHLIB_EXT=$SHEXT ROOT_LIBDIR=$ROOT_LIBDIR JULIA_LIBDIR=$JULIA_LIBDIR LIBJULIA_PATH=$LIBJULIA_PATH INCDIR_JULIA_H=$INCDIR_JULIA_H INCDIR_UV_H=$INCDIR_UV_H INCDIR_SUPPORT_H=$INCDIR_SUPPORT_H`) |> println

exepath = joinpath(bindir, "julia")
isfile(exepath) || error("could not find final exe: $exepath, something went wrong in the compilation")

depsfile_location = joinpath(splitdir(Base.source_path())[1],"deps.jl")

open(depsfile_location, "w") do depsfile
    print(depsfile,
        """
        const SHEXT = "$SHEXT"
        const ROOT_INCDIR = "$ROOT_INCDIR"
        const ROOT_LIBDIR = "$ROOT_LIBDIR"
        const JULIA_EXE = "$exepath"
        """
    )
end

info("ROOT-enabled julia now exists at $exepath")
