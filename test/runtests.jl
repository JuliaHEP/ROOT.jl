using ROOT, CxxWrap
using Test
import Pkg

Base.ENV["JULIA_PROJECT"] = dirname(Pkg.project().path)

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
    @testset verbose=true "TTree" begin
        include("test_ttree.jl")
    end   
    @testset verbose=true "Examples" begin
        include("test_examples.jl")
    end
end
