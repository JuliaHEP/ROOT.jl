using ROOT
ROOT.gROOT.process_line("gErrorIgnoreLevel = 3001;")

function test_hist1()
    hi = TH1D("my_hist", "My Hist", Int32(10), -30.0, 30.0)
    n=100000000
    @inbounds for i=1:n
    	Fill(hi, randn())
    end
end

function test_hist2()
    hm = Dict{Int64, TH1D}()
    for j=1:100
        hm[j] = TH1D("my_hist_$j", "My Hist", Int32(10*j), -30.0, 30.0)
    end
    hi = TH1D("my_hist", "My Hist", Int32(10), -30.0, 30.0)
    n=100000
    @inbounds for i=1:n
    	for j=1:100
            Fill(hm[j], rand())
        end
    end
end


function test_hist3()
    hi = TH1D("my_hist", "My Hist", Int32(10), -30.0, 30.0)
    n=10000000
    ih = 0.0
    @inbounds for i=1:n
    	Fill(hi, randn())
        ih += Integral(hi)
        ih += GetMean(hi)
        ih += GetRMS(hi)
    end
end


function test_ttree1()
    tf = TFile("test.root", "RECREATE")
    ttree = TTree("my_tree", "My Tree")

    #branch variable should be array with length 1
    p1 = Float64[0.0]
    p2 = Int32[0]
    p3 = Float32[0.0]

    Branch(ttree, "p1", convert(Ptr{Void}, pointer(p1)), "p1/D")
    Branch(ttree, "p2", convert(Ptr{Void}, pointer(p1)), "p2/I")
    Branch(ttree, "p3", convert(Ptr{Void}, pointer(p1)), "p3/F")

    sum_entries = 0.0
    for i=1:10000000
        p1[1] = i
        p2[1] = i*2
        p3[1] = i*3
        Fill(ttree)
    end
    Write(tf)
    Close(tf)
end

function test_ttree2()
    tf = TFile("test.root")
    ttree = root_cast(TTree, Get(tf, "my_tree"))

    #branch variable should be array with length 1
    p1 = Float64[0.0]
    p2 = Int32[0]
    p3 = Float32[0.0]

    SetBranchAddress(ttree, "p1", convert(Ptr{Void}, pointer(p1)))
    SetBranchAddress(ttree, "p2", convert(Ptr{Void}, pointer(p1)))
    SetBranchAddress(ttree, "p3", convert(Ptr{Void}, pointer(p1)))

    s = 0.0
    for i=1:GetEntries(ttree)
        GetEntry(ttree, i)
        s += p1[1] + p2[1] + p3[1]
    end
    Close(tf)
end

function best(f)
    f()
    vs = Float64[]
    for i=1:5
        push!(vs, (@timed f())[2])
    end
    return round(mean(vs), 4)
end

println("hist1: ", best(test_hist1))
println("hist2: ", best(test_hist2))
println("hist3: ", best(test_hist3))
println("ttree1: ", best(test_ttree1))
println("ttree2: ", best(test_ttree2))
