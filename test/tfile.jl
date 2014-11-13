using ROOT
using Base.Test

println("creating TFile")
tf = ROOT.TFile("test.root", "RECREATE")
println("mkpath1")
p = mkpath(tf, "a/b/c")
println("mkpath2")
p2 = mkpath(tf, "a/b/c")
println("TFile::Write")
Write(tf)
println("TFile::Close $tf")
println(methods(Close))
println(methods(GetEntries))
x = Close(tf)
println("closed $tf $x")

println("file exist?")
@test isfile("test.root") == true
println("open file")
tf = ROOT.TFile("test.root", "READ")
println("check dir")
d = root_cast(TDirectory, Get(tf, "a/b/c"))
@test is_null(d) == false

rm("test.root")
