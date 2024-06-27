@testset "StdVector tree branch" begin
    t = ROOT.TTree("tree", "")
    
    v_init = [1. 2.; 3. 4.]
    
    v1 = StdVector(v_init[1,:])
    br = Branch(t, "v", v1, 32000, 99)

    GC.@preserve v1 Fill(t) #First fill v1

    v2 = StdVector(v_init[2, :])
    SetObject(br, v2)
    GC.@preserve v2 Fill(t)  #Second fill v2
    
    #Check Fill() is safe wrt garbage collection
    GC.gc()
    GC.gc()
    GC.gc()
    GC.@preserve v2 Fill(t)  #Third fill v2

    va = fill(CxxPtr(v1))
    SetBranchAddress(t, "v", va)
    GC.gc()
    GC.gc()
    GC.gc()
    GC.@preserve va Fill(t) #Fourth fill v1

    vref = Ref(CxxPtr(v2))
    SetBranchAddress(t, "v", vref)
    GC.gc()
    GC.gc()
    GC.gc()
    GC.@preserve vref Fill(t) #Fifth fill v2
    
    Scan(t)
    
    #Read back values and test
    SetObject(br, v1)
    v1 .= [0., 0.]
    
    #First entry was filled with v1_init:
    GC.@preserve v1 GetEntry(t, 0)
    @test v1 == v_init[1, :]
    
    #Second entry was filled with v2_init:
    GC.@preserve v1 GetEntry(t, 1)
    @test v1 == v_init[2, :]

    #Third entry was filled with v2_init:
    GC.@preserve v1 GetEntry(t, 2)
    @test v1 == v_init[2, :]

    #Fourth entry was filled with v1_init:
    GC.@preserve v1 GetEntry(t, 3)
    @test v1 == v_init[1, :]

    #Fith entry was filled with v2_init:
    GC.@preserve v1 GetEntry(t, 4)
    @test v1 == v_init[2, :]
end

nentries::Int = 0

@testset "POD tree branch" begin
    t = ROOT.TTree("tree", "")
    i = fill(Int32(1))
    j = Ref(Int32(2))
    #Branch set using a 0-dim array:
    br1 = Branch(t, "i", i, 32000, 99)
    #Branch set using a RefValue:
    br2 = Branch(t, "j", j, 32000, 99)
    Fill(t)
    i[] +=1
    j[] +=2
    @GC.preserve i j Fill(t)

    #Test of SetAddress()
    #swap i and j
    SetAddress(br1, j)
    SetAddress(br2, i)
    tmp = i[]
    i[] = j[] + 2
    j[] = tmp + 1
    @GC.preserve i j Fill(t)

    #Check Fill() is safe wrt garbage collection
    i[] = i[] + 2
    j[] = j[] + 1
    GC.gc()
    GC.gc()
    GC.gc()
    @GC.preserve i j Fill(t)
    
    #Display tree contents
    @GC.preserve i j Scan(t)
    
    #Read back and check. Remember i and j are swapped.
    iref, jref = Int32(2), Int32(1)
    for ientry in 1:GetEntries(t)
        @GC.preserve i j GetEntry(t, ientry - 1)
        @test i[] == iref
        @test j[] == jref
        iref += 2
        jref += 1
    end
    
    #Test of SetBranchAddress()
    #Swap back i and j
    SetBranchAddress(t, "i", i)
    SetBranchAddress(t, "j", j)
    iref, jref = Int32(1), Int32(2)
    for ientry in 1:GetEntries(t)
        @GC.preserve i j GetEntry(t, ientry - 1)
        @test i[] == iref
        @test j[] == jref
        iref += 1
        jref += 2
    end

    nentries = GetEntries(t)
    
    f = ROOT.TFile("ttree_test.root", "recreate")
    Write(t)
    Close(f)
end

@testset "Write, append and read TFile" begin
    f = ROOT.TFile("ttree_test.root", "recreate")
    t = ROOT.TTree("tree", "tree")
    x = fill(Float32(π))
    Branch(t, "x", x)
    GC.@preserve x Fill(t)
    Write(t)
    Close(f)
    
    f = ROOT.TFile("ttree_test.root", "update")
    h = ROOT.TH1F("h", "h", 100, -5., 5.)
    SetDirectory(h, CxxPtr{ROOT.TDirectory}(C_NULL))
    FillRandom(h, "gaus", 100)
    Write(h)
    Close(f)

    f = ROOT.TFile("ttree_test.root")

    tree = Get(f, "tree")
    @test isa(tree, ROOT.TTree)
    @test GetEntries(tree) == 1

    tree = f.tree
    @test isa(tree, ROOT.TTree)
    @test GetEntries(tree) == 1

    tree = f["tree"]
    @test isa(tree, ROOT.TTree)
    @test GetEntries(tree) == 1
    
    h = Get(f, "h")
    @test isa(h, ROOT.TH1)
    @test GetEntries(h) == 100

    #type-stable Get versions:
    h = Get(f, "h", ROOT.TH1)
    @test isa(h, ROOT.TH1)
    h = Get(f, "h", ROOT.TH1, nothing)
    @test isa(h, ROOT.TH1)
    @test_throws TypeError Get(f, "tree", ROOT.TH1)
    @test_throws TypeError Get(f, "tree", ROOT.TH1, ROOT.TTree())
    
    @test_throws KeyError Get(f, "foo")
    @test_throws KeyError f.foo
    @test_throws KeyError f["foo"]    
end
