import CxxWrap
import Libdl
import Conda
import TOML
using UUIDs
using Scratch 
const CXXWRAP_PREFIX = CxxWrap.prefix_path()
const JL_SHARE = joinpath(Sys.BINDIR, Base.DATAROOTDIR, "julia")
const JULIA = joinpath(Sys.BINDIR, "julia")
const libname="libjlROOT2." * Libdl.dlext

const conda_root_version = "6.30.04"
const supported_root_versions = [ conda_root_version ]

used_root_version = ""
root_libdir = ""
root_bindir = ""
rootconfig = "root-config"

const pkg_uuid = UUID(TOML.parsefile(joinpath(dirname(@__DIR__), "Project.toml"))["uuid"])
const pkg_version = VersionNumber(TOML.parsefile(joinpath(dirname(@__DIR__), "Project.toml"))["version"])


#Test root installation
try
    global used_root_version = readchomp(`$rootconfig --version`)
    global rootlibdir = readchomp(`$rootconfig --libdir`)
    global root_found = true
catch
    global root_found = false
end

const scratch = joinpath(get_scratch!(pkg_uuid, "lib"), string(pkg_version), "ROOT-v" * used_root_version)

found_root_ok = root_found && (used_root_version ∈ supported_root_versions)

if found_root_ok
    @info "ROOT libraries from $root_libdir will be used."
else
    if !root_found
        @info "Executable root-config not found. We will try to install ROOT from conda-forge."
    elseif !found_root_ok
        @info "Release of the found root installation is not compatible. Release " * join(supported_root_versions) * " required.  We will try to install root from conda-forge."
    end
    try
        cmd=:(Conda.add("root=$conda_root_version", args=`--strict-channel-priority --override-channels -c conda-forge`, satisfied_skip_solve=true))
        @info "Conda command: $cmd"
        eval(cmd)
        global rootlibdir = Conda.LIBDIR
        global rootconfig = joinpath(Conda.BINDIR, "root-config")
        global found_root_ok = true
    catch
        @error "Failed to install ROOT release $conda_root_version from conda-forge. Check you network connection or install ROOT yourself and restart julia with the path to the ROOT executables included in the shell exectable path list (PATH)."
        #no-op
    end
end

found_root_ok || exit(1)

const buildpath = joinpath(scratch, "build")

cmd=`make BUILD_DIR=$buildpath CXXWRAP_PREFIX="$CXXWRAP_PREFIX" JL_SHARE="$JL_SHARE" JULIA="$JULIA" ROOT_CONFIG="$rootconfig" -j $(Sys.CPU_THREADS)`
@info "Build command: " * string(cmd)[2:end-1] * " executed in " * pwd() * " directory."

#julia needs to be in the PATH for julia-config.jl, invoked by the Makefile, to run
PATH=Sys.BINDIR * ":" * ENV["PATH"]

build_rc = run(Cmd(cmd, env = ["PATH" => PATH], ignorestatus=true)).exitcode
libpath = joinpath(scratch, libname)
try
    mv(joinpath(buildpath, libname), libpath, force=true) 
    splitpath(buildpath)[end-1] != "build" || error("Bug foud. buildpath must end with /build") #protection against deleted bad directory after introduciton of a bug
    rm(buildpath, recursive=true, force=true)
catch e
    @warn "Failed to clean-up directory after dependency build. " * string(e)
end

if build_rc == 0
    rootbindir = readchomp(`$rootconfig --bindir`)
    open("deps.jl", "w") do f
        println(f, "const rootlibdir = \"", escape_string(rootlibdir), "\"")
        println(f, "const rootbindir = \"", escape_string(rootbindir), "\"")
        println(f, "const libpath = \"", escape_string(libpath), "\"")
    end
end

exit(build_rc)
