#file: example/ttree.jl
#run as: julia example/ttree.jl

using ROOT
using Base.Test

tf = TFile("test.root", "RECREATE")
ttree = TTree("my_tree", "My Tree")
@test bytestring(GetName(ttree)) == "my_tree"

#branch variable should be array with length 1
x = Float64[0]
px = convert(Ptr{Void}, x)
#println(methods(Branch))
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
@test bytestring(ClassName(ttree)) == "TTree"

ttree = root_cast(TTree, ttree)

@test GetEntries(ttree) == n

br = GetBranch(ttree, "x")
SetAddress(br, convert(Ptr{Void}, x))

sum_entries2 = 0.0
for i=1:n
    GetEntry(ttree, i-1)
    sum_entries2 += x[1]
end

@test sum_entries == sum_entries2

Close(tf)
