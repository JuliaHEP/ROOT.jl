using ROOT, CxxWrap
using Test
import Pkg

Base.ENV["JULIA_PROJECT"] = dirname(Pkg.project().path)

const RUNTESTS = @__FILE__

function test_nothrow(script)
    @test begin
        try
            run(`$(Base.Sys.BINDIR)/julia $script`)
            true
        catch
            false
        end
    end
end

@testset verbose=true begin
    if Sys.MACHINE == "x86_64-linux-gnu"
        @testset verbose=true "ROOT install" begin
            include("$(@__DIR__)/test_install.jl")
        end
    end
    
    @testset verbose=true "TTree" begin
        include("$(@__DIR__)/test_ttree.jl")
    end
    
    @testset verbose=true "Examples" begin
        include("$(@__DIR__)/test_examples.jl")
    end

    @testset verbose=true "TObjArray" begin
        include("test_objarray.jl")
    end
end
