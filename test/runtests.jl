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

@testset "Examples" begin
    @testset "demo_ROOT" test_nothrow("../examples/demo_ROOT.jl")
    @testset "demo_TGraph" test_nothrow("../examples/demo_TGraph.jl")
    @testset "demo_fit_with_jl_func" test_nothrow("../examples/demo_fit_with_jl_func.jl")
    @testset "demo_fit_with_jl_func_2" test_nothrow("../examples/demo_fit_with_jl_func_2.jl")
    @testset "write_tree1" test_nothrow("../examples/TTree_examples/write_tree1.jl")
    @testset "read_tree1" test_nothrow("../examples/TTree_examples/read_tree1.jl")
    @testset "write_tree2" test_nothrow("../examples/TTree_examples/write_tree2.jl")
    @testset "read_tree2" test_nothrow("../examples/TTree_examples/read_tree2.jl")
    @testset "write_tree3" test_nothrow("../examples/TTree_examples/write_tree3.jl")
    @testset "read_tree3" test_nothrow("../examples/TTree_examples/read_tree3.jl")
    @testset "string_branch_example" test_nothrow("../examples/TTree_examples/string_branch_example.jl")
end
