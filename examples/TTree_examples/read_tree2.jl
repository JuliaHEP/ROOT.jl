import Pkg

const installedpkgs = getfield.(filter(p->p.is_direct_dep, [p.second for p in Pkg.dependencies()]), :name)
"UnROOT" ∈ installedpkgs || Pkg.add("UnROOT")

using UnROOT

println("Reading back the file created with write_tree2.jl using LazyTree of UnROOT.\n")

t = LazyTree("test2.root", "tree")
display(t)
