depsdir = dirname(@__FILE__)

@static if is_apple()
    OS="Darwin"
end
@static if is_linux()
    OS="Linux"
end

bindir = joinpath(depsdir, "usr/bin")
if !isdir(bindir)
    info("making $bindir")
    mkpath(bindir)
end
    
info("compiling exe")
readstring(`make OS=$OS JULIA_HOME=$JULIA_HOME/../../`) |> println

info("symlinking libraries")
libdir = joinpath(depsdir, "usr/lib")
if !isdir(libdir)
    symlink("$JULIA_HOME/../lib", libdir)
end

exepath = joinpath(bindir, "julia")
isfile(exepath) || error("could not find final exe: $exepath, something went wrong in the compilation")

println("ROOT-enabled julia now exists at $exepath")
