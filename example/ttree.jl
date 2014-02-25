using ROOT

#FIXME: currently, default args from Clang are not supported, so they have to be explicitly specified
#ROOT relies quite heavily on them, so it would be nice to fix

tf = TFile("test.root", "RECREATE")
ttree = TTree("my_tree", "My Tree")

#branch variable should be array
x = Float64[0]

#TTree::Branch function expects void*
px = convert(Ptr{Void}, x)

br = Branch(ttree, "x", px, "x/D")

for i=1:10000
	x[1] = randn()
	Fill(ttree)
end

branches = GetListOfBranches(ttree)
for i=1:length(branches)
	println(root_cast(TBranch, branches[i]))
end
Write(tf)
Close(tf)
