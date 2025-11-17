#
# Test of plain ROOT.TTree
#

if !isdefined(Main, :RUNTESTS)
    using ROOT
    using Test
end

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

@testset "POD tree branch 1" begin
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
end    

@testset "POD tree branch 2" begin
    t2 = ROOT.TTree("tree2", "")

    s0 = "From α to Ω"
    nt = (i8 = fill(Int8(1) <<7), i16 = fill(Int16(1) <<15), i32 = fill(Int32(1) <<31), i64 = fill(Int64(1) <<63),
          ui8 = fill(UInt8(1) <<7), ui16 = fill(UInt16(1) <<15), ui32 = fill(UInt32(1) <<31), ui64 = fill(UInt64(1) <<63),
          b = fill(false),
          f32 = fill(floatmax(Float32)), f64 = fill(floatmax(Float64)))

    nt0 = deepcopy(nt)

    @GC.preserve nt begin

        # The method Branch(tree, branchname, dataarray) is not supported
        # for c-string. We need to use Branch(branchname, address, leaflist).
        #
        # While the first returns a TBranchPtr, a wrapper that saves the need of
        # type cast when calling Set(Branch)Adress function, the second returns
        # a plain Ptr{TBranch}.
        br_s = Branch(t2, "s", convert(Ptr{Nothing}, pointer(s0)), "s/C")
        
        Branch(t2, "i8", nt.i8)
        Branch(t2, "i16", nt.i16)
        Branch(t2, "i32", nt.i32)
        Branch(t2, "i64", nt.i64)
        Branch(t2, "ui8", nt.ui8)
        Branch(t2, "ui16", nt.ui16)
        Branch(t2, "ui32", nt.ui32)
        Branch(t2, "ui64", nt.ui64)    
        Branch(t2, "f32", nt.f32)
        Branch(t2, "f64", nt.f64)

        # Boolean is in the same situation as c-strings
        Branch(t2, "b", convert(Ptr{Int8}, pointer(nt.b)), "b/O")
        
        #Store the values in the tree:
        Fill(t2)

        #Reset all values
        for i in 1:lastindex(nt)
            nt[i][] = zero(nt[i][])
        end
        
        #read back values

        # When reading a character string from a TTree, usually we don't know in
        # advance the string length. In such case we need to retrieve the
        # maximum length over the tree entries first. Let's test the procedure.
        maxstringlen = GetLenStatic(GetLeaf(t2, "s"))
        s = zeros(Int8, maxstringlen)
        SetAddress(br_s, Ptr{Nothing}(pointer(s)))
        
        GetEntry(t2, 0)

        #check the read back values
        @test unsafe_string(pointer(s)) == s0
        @test nt == nt0
        
    end
end
