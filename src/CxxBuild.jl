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
import ROOT_julia_jll
import VDT_jll
import Artifacts
import SHA

using Scratch

import ....ROOT: supported_root_versions

_English_or_list(v) = join(v, ", ", " or ")

function is_jll_supported()
    #root_jll = Base.find_package("ROOT_julia_jll")
    root_julia_jll = pathof(ROOT_julia_jll)
    isnothing(root_julia_jll) && error("Package ROOT_julia_jll not found. Please try to add it with 'import Pkg; Pkg.add(\"ROOT_julia_jll\").")
    root_julia_jll_dir = dirname(dirname(Base.find_package("ROOT_julia_jll")))
    artifacts = Artifacts.select_downloadable_artifacts(joinpath(root_julia_jll_dir, "Artifacts.toml"))
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
    pkg_uuid = Base.UUID(TOML.parsefile(joinpath(dirname(@__DIR__), "Project.toml"))["uuid"])
    pkg_version = VersionNumber(TOML.parsefile(joinpath(dirname(@__DIR__), "Project.toml"))["version"])    
    scratch = joinpath(get_scratch!(pkg_uuid, "lib"), string(pkg_version), "Julia-v" * string(Base.VERSION), "ROOT-v" * used_root_version)
    mkpath(scratch)
    buildpath = joinpath(scratch, "build")
    
    #Command to build the library
    CXXWRAP_PREFIX = CxxWrap.prefix_path()
    JL_SHARE = joinpath(Sys.BINDIR, Base.DATAROOTDIR, "julia")
    JULIA = joinpath(Sys.BINDIR, "julia")
    depsdir = joinpath(dirname(@__DIR__), "deps")
    srcdir = joinpath(depsdir, "src")
    cmd=`make -C "$depsdir" BUILD_DIR="$buildpath" CXXWRAP_PREFIX="$CXXWRAP_PREFIX" JL_SHARE="$JL_SHARE" JULIA="$JULIA" ROOT_CONFIG="$rootconfig" -j $(Sys.CPU_THREADS) VDT_DIR="$(VDT_jll.artifact_dir)"`
    extra_make_options = ROOTprefs._load_preference("extra_make_options", "")
    if !isempty(extra_make_options)
        cmd = Cmd([collect(cmd)..., extra_make_options])
    end
    cmd_clean = Cmd([collect(cmd)...,  "clean"]) #append clean to the command arguments
    cmd_file_list = Cmd([collect(cmd)..., "echo_WRAPPER_CXX"]) #command to list .cxx files
    
    #julia needs to be in the PATH for julia-config.jl, invoked by the Makefile, to run
    build_env = copy(ENV)
    build_env["PATH"] = Sys.BINDIR * ":" * ENV["PATH"]

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
    
    #Check if library is already built and up-to-date. Returns if it's the case.
    sigfile = joinpath(scratch, "sig")
    if isfile(libpath) && isfile(sigfile)
        t0 = time()
        newsig = libsignature(joinpath(depsdir, "src"), srcfiles, libpath)
        oldsig = readline(sigfile)
        if newsig == oldsig
            @info "Library $libpath is already up-to-date."
            build = false
        end
        t1 = time()
        @info "Time spent to check for modifications in the ROOT-julia library source code that would require a compilation: $(round(t1-t0, digits=2)) s"
    end

    if build
        @info "Build command: " * string(cmd)[2:end-1] * " executed in " * pwd() * " directory."
    
        #Call make to build the library
        cmd = Cmd(cmd, env = build_env, ignorestatus=true)
        cmd_clean = Cmd(cmd_clean, env = build_env, ignorestatus=true)
        pipe = Pipe()
#            run(pipeline(`tee "$scratch/build.log"`, stdin=pipe, stdout=stdout, stderr=stderr), wait=false)            

        #check if f1 is newer than f2. f1 considered very old (epoch timestamp) if it does not exist.
        isfilenewerthan(f1, f2) = stat(f1).mtime > stat(f2).mtime 
        objofsrc(srcfile) = joinpath(buildpath, replace(srcfile, r"\.[^.]*$" => ".o"))
        println(join(objofsrc.(srcfiles), "\n"))
        ntobuild = count(map(x -> isfilenewerthan(joinpath(srcdir, x), objofsrc(x)), srcfiles))
        
        if ntobuild > 0
            warntimemsg = if ntobuild > 10
                ", which will take some time. Be patient."
            else
                "."
            end
            println("\n>>> Making $ntobuild XYZ.o object files$warntimemsg <<<\n")
        end

        if ntobuild > 0
            #if at least one object must be compiled,
            #then there is also the .so to build
            ntobuild += 1
        end

        # Run the build command `cmd`, add progress information to output,
        # and send the output to both a log file and stdout
        w = length(string(ntobuild))
        try
            pipe = Pipe()
            proc = run(pipeline(cmd, stdout=pipe, stderr=pipe), wait=false)
            t0 = time()
            @async open("$scratch/build.log", "w") do io
                i = 0
                for l in eachline(pipe)
                    # insert [xxxx/yyyy] to the "Make xyz.o" lines: 
                    pref = if startswith(l, "Make")
                        i += 1
                        "[" * lpad(i, w) * "/" * lpad(ntobuild, w) * "] "
                    else
                        ""
                    end
                    #print to stdout and file:
                    println(pref, l)
                    flush(stdout)
                    println(io, pref, l)
                end
            end
            wait(proc)
            t1 = time()
            @info "Time spent in building the library: $(round(t1-t0, digits=2)) s"
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
    if get_clean_after_build()
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

    function get_vers(bindir)::Union{VersionNumber, Nothing}
        try
            rootconfig = joinpath(bindir, "root-config")
            vers_numbers = parse.(Int, split(readchomp(`"$rootconfig" --version`), "."))
            VersionNumber(vers_numbers...)
        catch
            nothing
        end
    end
    
    rootsys = strip(ROOTprefs.get_ROOTSYS())
    binpaths = String[]
    
    if length(rootsys) > 0
        p = joinpath(rootsys, "bin")
        vers_from_rootsys = get_vers(p)
        push!(binpaths, p)
    else
        vers_from_rootsys = nothing
    end

    append!(binpaths, split(ENV["PATH"], ":")) 

    i = findfirst(rootconfig->get_vers(rootconfig) ∈ supported_root_versions, binpaths)

    if (   isnothing(i) && !ROOTprefs.get_check_root_version() 
        && length(binpaths) > 0 && !isnothing(vers_from_rootsys))
       i = 1
    end

    if isnothing(i) || basename(rstrip(binpaths[i], '/')) != "bin"
        if !isnothing(vers_from_rootsys)
            msg1 = "Version $vers_from_rootsys of ROOT installed under ROOTSYS ($rootsys) is not supported."
        elseif length(rootsys) > 0
            msg1 = "No ROOT installation found under $rootsys."
        else
            msg1 = "No supported ROOT version installation."
        end
        error("$msg1 Please install ROOT (https://root.cern/install) version $(_English_or_list(supported_root_versions)), and call ROOTpres.setROOTSYS(path) to set the path to the installation base directory (i.e containting bin/root and bin/root-config).")
    end

    validrootsys = dirname(rstrip(binpaths[i], '/'))

    (validrootsys, rootsys)
end


function get_or_build_libroot_julia()

    if get_use_root_jll() && is_jll_supported()
        #prebuilt wrapper used, no build to perform
        return ROOT_julia_jll.get_libroot_julia_path()
    end

    if !get_use_root_jll() && is_jll_supported()
        @info "The plaform supports ROOT_jll. You can use ROOT libraries from the ROOT_jll package to skip the long compilation step. To switch to ROOT_jll, interrupt the import, run 'using ROOTprefs; set_use_root_jll() to enable the ROOT_jll mode, restart Julia, and execute 'import ROOT' again."
    end

    #Below, we process differently if root_jll mode is enabled or not
    #in order to adapt the error message.
    rootsys, pref_rootsys = if get_use_root_jll() #jll mode but platform not supported.
        set_use_root_jll(false, nowarn = true)
        intro = "Platform not supported by the prebuilt wrapper ROOT_julia_jll package." 
        postface = "The mode 'use_root_jll' has been disabled (can be reenabled by executing `using ROOTprefs; set_use_root_jll()`)." 
        try
            @warn("$intro $postface")
            rootsys, pref_rootsys = check_rootsys()
        catch
            @error("$intro You need to install ROOT version $(_English_or_list(supported_root_versions)) on the host and restart Julia. Ensure that after installation the ROOT commands, especially root-config, can be executed from the shell prompt before restarting Julia. $postface")
            return ""
        end
    else #rootsys mode
        try
            check_rootsys()
        catch e
            if e isa ErrorException
                @error(e.msg)
                return ""
            else
                rethrow()
            end
        end
    end

    libpath =  build_root_wrapper(rootsys)
   
    if !isempty(libpath) && rootsys != pref_rootsys
      #If build succeeded and ROOTSYS was modified, update LocalPreference.toml
      set_ROOTSYS(rootsys, nocheck=true)
    end
    
    return libpath
end
end
