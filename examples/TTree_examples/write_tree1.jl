using ROOT

println("Creating a ROOT file with a TTree filled with scalars.\n")

nevts = 10
f = ROOT.TFile!Open("test1.root", "RECREATE")
t = ROOT.TTree("tree", "tree")
a = Ref{Int32}(0)
Branch(t, "a", a, Int32(32000), Int32(99))
for i in 1:nevts
    a[] = i
    println("Writing value ", a[])
    Fill(t)
end
Write(t)
Close(f)
