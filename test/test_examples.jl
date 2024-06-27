#Beware this method will delete the file with path tmpfilename
function test_fileproducer(testname, tmpfilename, minsize = 50)
    @testset "$testname" begin
        script = joinpath(@__DIR__, "../examples", testname * ".jl")
        isfile(script) || error("File $script required for test $testname not found")
        rm(tmpfilename, force=true)
        run(`$(Base.Sys.BINDIR)/julia "$script"`)
        @test filesize(tmpfilename) > minsize
    end
end
#     demo_fit_with_jl_func_2.png  demo_fit_with_jl_func.png    

    
test_fileproducer("demo_ROOT", "demo_ROOT.png")
test_fileproducer("demo_TGraph", "demo_TGraph.png")
test_fileproducer("demo_fit_with_jl_func", "demo_fit_with_jl_func.png")
test_fileproducer("demo_fit_with_jl_func_2", "demo_fit_with_jl_func_2.png") 
test_fileproducer("TTree_examples/write_tree1", "test1.root")
@testset "read_tree1" test_nothrow(joinpath(@__DIR__, "../examples/TTree_examples/read_tree1.jl"))
test_fileproducer("TTree_examples/write_tree2", "test2.root")
@testset "read_tree2" test_nothrow(joinpath(@__DIR__, "../examples/TTree_examples/read_tree2.jl"))
test_fileproducer("TTree_examples/write_tree3", "test3.root")
@testset "read_tree3" test_nothrow(joinpath(@__DIR__, "../examples/TTree_examples/read_tree3.jl"))
@testset "string_branch_example" test_nothrow(joinpath(@__DIR__, "../examples/TTree_examples/string_branch_example.jl"))
@testset "ROOT.demo()" begin
    @test begin
        try
            ROOT.demo()
            true
        catch
            false
        end
    end
end

