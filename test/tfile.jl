using ROOT
using Base.Test

println("creating test.root")
tf = ROOT.TFile("test.root", "RECREATE")
println("creating test.root:/a/b/c")
p = mkpath(tf, "a/b/c")
println("creating test.root:/a/b/c")
p2 = mkpath(tf, "a/b/c")
Write(tf)
x = Close(tf)

@test isfile("test.root") == true
tf = ROOT.TFile("test.root", "READ")
d = root_cast(TDirectory, Get(tf, "a/b/c"))
@test is_null(d) == false

println("removing test.root")
rm("test.root")
