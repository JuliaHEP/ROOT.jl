@testset "Test install"  begin

    using ROOTprefs

    saved_project = Pkg.project().path
    saved_loadpath = LOAD_PATH
    Pkg.activate(temp=true)
    
    #empty LOAD_PATHL
    #keepat!(LOAD_PATH, fill(false, size(LOAD_PATH)))
    #add tested project in LOAD_PATH to import it
    push!(LOAD_PATH, dirname(@__DIR__))

    println("LOAD_PATH: ", LOAD_PATH)
    
    @test begin
        import ROOT
        isdefined(ROOT, :TH1D)
    end
    
    #test external ROOT installation mode
    #we mimic this mode using the contents of ROOT_jll
    import ROOT_jll
    using ROOTprefs
    
    set_use_root_jll(false)
    set_ROOTSYS(ROOT_jll.artifact_dir)
    project_path = Pkg.project().path
    
    rc = withenv("JULIA_LOAD_PATH" => join(LOAD_PATH, ":"),
                 "JULIA_PROJECT" => project_path) do
                     mktemp() do path, io
                         write(io, raw"""
import ROOT
using ROOTprefs
println(stderr, get_use_root_jll())
                exit(isdefined(ROOT, :TH1D) ? 0 : 1)
                """)
                         close(io)
                         run(Cmd(`"$(Sys.BINDIR)/julia" --startup-file=no "$path"`, ignorestatus=true)).exitcode
                     end
                 end
    @test rc == 0
    
    LOAD_PATH .= saved_loadpath
    Pkg.activate(saved_project)
end

