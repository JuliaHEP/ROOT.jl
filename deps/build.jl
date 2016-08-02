depsdir = dirname(@__FILE__)

@static if is_apple()
    OS="Darwin"
    SHEXT="dylib"
end
@static if is_linux()
    OS="Linux"
    SHEXT="so"
end

bindir = joinpath(depsdir, "usr/bin")
if !isdir(bindir)
    info("making $bindir")
    mkpath(bindir)
end


const JULIA_BASE_PATH = dirname(dirname(JULIA_HOME))
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

@show INCDIR_JULIA_H 
@show INCDIR_UV_H
@show INCDIR_SUPPORT_H
@show LIBJULIA_PATH

info("compiling exe")
readstring(`make OS=$OS SHLIB_EXT=$SHEXT LIBJULIA_PATH=$LIBJULIA_PATH INCDIR_JULIA_H=$INCDIR_JULIA_H INCDIR_UV_H=$INCDIR_UV_H INCDIR_SUPPORT_H=$INCDIR_SUPPORT_H`) |> println

info("symlinking libraries")
libdir = joinpath(depsdir, "usr/lib")
if !isdir(libdir)
    symlink("$JULIA_HOME/../lib", libdir)
end

exepath = joinpath(bindir, "julia")
isfile(exepath) || error("could not find final exe: $exepath, something went wrong in the compilation")

println("ROOT-enabled julia now exists at $exepath")
