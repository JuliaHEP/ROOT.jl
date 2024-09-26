# Submodule of ROOT providing support to build
# the C++ code of the ROOT library wrapper.
#
# This is an internal module to be used by the ROOT module
# code. The API can change from release to release.

module CxxBuild

using ROOTprefs

import CxxWrap
import Libdl
import TOML
import ROOT_jll
import libroot_julia_jll
import Artifacts
import SHA

using UUIDs
using Scratch


import ....ROOT: supported_root_versions

_English_or_list(v) = join(v, ", ", " or ")

function is_jll_supported()
    root_jll = Base.find_package("ROOT_jll")
    isnothing(root_jll) && error("Package ROOT_jll not found. Please try to add it with 'import Pkg; Pkg.add(\"ROOT_jll\").")
    ROOT_jll_dir = dirname(dirname(Base.find_package("ROOT_jll")))
    artifacts = Artifacts.select_downloadable_artifacts(joinpath(ROOT_jll_dir, "Artifacts.toml"))
    length(artifacts) > 0
end

#
# `build_root_wrapper(rootsys; recompile = false, cleanafterbuild=true)`
#
# Build the libroot_julia library for the ROOT libraries installed under rootsys directory.
# Return the full path to libroot_julia or an empty string in case of failure.
#
function build_root_wrapper(rootsys = ROOTprefs.get_ROOTSYS())

    rootconfig = joinpath(rootsys, "bin", "root-config")
    used_root_version = readchomp(`$rootconfig --version`)
    
    # Directory to store the generated library
    pkg_uuid = UUID(TOML.parsefile(joinpath(dirname(@__DIR__), "Project.toml"))["uuid"])
    pkg_version = VersionNumber(TOML.parsefile(joinpath(dirname(@__DIR__), "Project.toml"))["version"])    
    scratch = joinpath(get_scratch!(pkg_uuid, "lib"), string(pkg_version), "Julia-v" * string(Base.VERSION), "ROOT-v" * used_root_version)
    mkpath(scratch)
    buildpath = joinpath(scratch, "build")
    
    #Command to build the library
    CXXWRAP_PREFIX = CxxWrap.prefix_path()
    JL_SHARE = joinpath(Sys.BINDIR, Base.DATAROOTDIR, "julia")
    JULIA = joinpath(Sys.BINDIR, "julia")
    depsdir = joinpath(dirname(@__DIR__), "deps")
    cmd=`make -C "$depsdir" BUILD_DIR="$buildpath" CXXWRAP_PREFIX="$CXXWRAP_PREFIX" JL_SHARE="$JL_SHARE" JULIA="$JULIA" ROOT_CONFIG="$rootconfig" -j $(Sys.CPU_THREADS)`
    cmd_clean = Cmd([collect(cmd)...,  "clean"]) #append clean to the command arguments
    cmd_file_list = Cmd([collect(cmd)..., "echo_WRAPPER_CXX"]) #command to list .cxx files
    
    @info "Build command: " * string(cmd)[2:end-1] * " executed in " * pwd() * " directory."
    
    #julia needs to be in the PATH for julia-config.jl, invoked by the Makefile, to run
    PATH=Sys.BINDIR * ":" * ENV["PATH"]

    #Library name and path
    libname="libroot_julia." * Libdl.dlext
    libpath = joinpath(scratch, libname)

    #source files:
    srcfiles = []
    out = readchomp(cmd_file_list)
    for l in split(out, "\n")
        m = match(r"^WRAPPER_CXX[[:space:]]*=[[:space:]]*(.*)[[:space:]]*", l)
        if !isnothing(m)
            srcfiles = split(m[1], " ")
            break
        end
    end

    build = true
    
    #Check if library is alredy built and up-to-date. Returns if it's the case.
    sigfile = joinpath(scratch, "sig")
    if isfile(libpath) && isfile(sigfile)
        newsig = libsignature(joinpath(depsdir, "src"), srcfiles, libpath)
        oldsig = readline(sigfile)
        if newsig == oldsig
            @info "Library $libpath is already up-to-date."
            build = false
        end
    end

    if build
        #Call make to build the library
        cmd = Cmd(cmd, env = ["PATH" => PATH], ignorestatus=true)
        cmd_clean = Cmd(cmd_clean, env = ["PATH" => PATH], ignorestatus=true)
        pipe = Pipe()
        srcfiles = []
        try
            run(pipeline(`tee "$scratch/build.log"`, stdin=pipe, stdout=stdout, stderr=stderr), wait=false)            
            
            ncxx = length(srcfiles)
            if ncxx > 0
                warntime = if ncxx > 10
                    " This will take some time. Be patient."
                else
                    ""
                end
                println("\n>>> Making $ncxx XYZ.o object files.$warntime <<<\n")
            end
            
            run(pipeline(cmd, stderr=pipe, stdout=pipe))
        finally
            close(pipe)
        end
        
        #Check build result
        if !isfile(joinpath(buildpath, libname))
            @error("Failed to compile the ROOT C++ library wrapper required by the Julia ROOT package. Logs can be found in $scratch/build.log")
            libpath = ""
        else
        mv(joinpath(buildpath, libname), libpath, force=true)
            sig = libsignature(joinpath(depsdir, "src"), srcfiles, libpath)
            open(joinpath(scratch, "sig"), "w") do f
                write(f, sig)
            end
        end
    end
    
    #Clean-up build area
    if is_clean_after_build_enabled()
        try
            splitpath(buildpath)[end-1] != "build" || error("Bug foud. buildpath must end with /build") #protect against wrong directory deletion after introduction of a bug
            rm(buildpath, recursive=true, force=true)
        catch e
            @warn "Failed to clean-up directory after dependency build. " * string(e)
        end
    end

    libpath
end

function libsignature(srcdir, srcfiles, libpath)
    ctx = SHA.SHA2_256_CTX()
    files = vcat([libpath], joinpath.(srcdir, srcfiles))
    for fname in files
        #try
        open(fname) do f
            while !eof(f)
                SHA.update!(ctx, read(f, 2^20))
            end
        end
        #catch
        #    @warn "Error while computing library signature. This may trigger unecessary recompilation of the C++ code when the module is precompiled." 
        #end
    end
    bytes2hex(SHA.digest!(ctx))
end

function check_rootsys()
    rootsys = get_ROOTSYS()

    try
        length(rootsys) == 0 && set_ROOTSYS!()

        vers_numbers = parse.(Int, split(readchomp(`"$rootsys/bin/root-config" --version`), "."))
        vers = VersionNumber(vers_numbers...)
        
        if is_root_version_checked() && vers ∉ supported_root_versions
            error("Found ROOT version $vers is not supported.")
        end
    catch e
        rethrow(ErrorException(e.msg * ". " * "Please install C++ ROOT (http://cern/root) version $(_English_or_list(supported_root_versions)). If it is already installed, either set your shell environment to make ROOT binaries available e.g., by sourcing thisroot.(c)sh file, or set ROOTSYS in Julia by executing 'import ROOTprefs; ROOTprefs.set_ROOTSYS(..).'"))
    end
    rootsys
end


function get_or_build_libroot_julia()

    if is_root_jll_used() && is_jll_supported()
        #prebuilt wrapper used, no build to perform
        return libroot_julia_jll.get_libroot_julia_path()
    end

    if !is_root_jll_used() && is_jll_supported()
        @info "The plaform supports ROOT_jll. You can use ROOT libraries from the ROOT_jll package to skip the long compilation step. To do so, interrupt the import, run 'using ROOTprefs; use_root_jll!() to enable the ROOT_jll mode, restart Julia, and execute 'import ROOT' again."
    end

    rootsys = ""

    #Below, we process differently if root_jll mode is enabled or not
    #in order to adapt the error message.
    if is_root_jll_used() #jll mode but platform not supported.
        use_root_jll!()
        try
            rootsys = check_rootsys()
            @error("ROOT binaries not found in ROOT_jll for this platform. The wrapper will be compiled to use the ROOT libraries installed in $rootsys. The mode 'use_root_jll' has been disabled (can be reenabled with use_root_jll!()).")
        catch
            @error("ROOT binaries not found in ROOT_jll for pthis platform. You need to install ROOT version $supported_root_versions on the host and restart Julia. If the ROOT binaries are not in the system executable search path, you need to provide to the ROOT installation by calling 'using ROOTprefs; set_ROOTSYS(path)'.  The mode 'use_root_jll' has been disabled (can be reenabled with use_root_jll!()).")
            return ""
        end
    else #rootsys mode
        try
            rootsys = check_rootsys()
        catch e
            if e isa ErrorException && hasfield(e, :msg)
                @error(e.msg)
                return ""
            else
                rethrow()
            end
        end
    end

    libpath =  build_root_wrapper(rootsys)

    if(isempty(libpath))
        @error("Failed to build the Julia wrapper for the ROOT C++ framework installed in $(get_ROOTSYS()).")
    end
    
    return libpath
end
end
