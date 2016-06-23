#file: example/ttree.jl
#run as: julia example/ttree.jl

using ROOT
using Base.Test

println("creating file")
tf = TFile("test.root", "RECREATE")
ttree = TTree("my_tree", "My Tree")
@test unsafe_string(GetName(ttree)) == "my_tree"

#branch variable should be array with length 1
x = Float64[0]
px = convert(Ptr{Void}, pointer(x))
br = Branch(ttree, "x", px, "x/D")

n = 100
sum_entries = 0.0
for i=1:n
    x[1] = i
    sum_entries += x[1]
    Fill(ttree)
end

@test GetEntries(ttree) == n

Write(tf)
Close(tf)

tf = TFile("test.root")
ttree = Get(tf, "my_tree")
@test unsafe_string(ClassName(ttree)) == "TTree"

ttree = root_cast(TTree, ttree)

@test GetEntries(ttree) == n

br = GetBranch(ttree, "x")
SetAddress(br, convert(Ptr{Void}, px))

sum_entries2 = 0.0
for i=1:n
    GetEntry(ttree, i-1)
    sum_entries2 += x[1]
end

@test sum_entries == sum_entries2

keylist = GetListOfKeys(tf)
@test length(keylist) == 1
iter = TListIter(keylist.p)

x = TObject(Next(iter))
@test x.p != C_NULL
@test GetName(x)|>unsafe_string == "my_tree"
classname(x) == "TTree"

@test Next(iter) == C_NULL
println("closing file")
Close(tf)
#rm("test.root")
