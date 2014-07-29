using ROOT
using Base.Test

tf = ROOT.TFile("test.root", "RECREATE")
p = mkpath(tf, "a/b/c")
p2 = mkpath(tf, "a/b/c")
Write(tf)
Close(tf)

@test isfile("test.root") == true
tf = ROOT.TFile("asd.root", "READ")
d = root_cast(TDirectory, Get(tf, "a/b/c"))
@test is_null(d) == false

rm("test.root")
