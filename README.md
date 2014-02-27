# ROOT

Wraps ROOT (http://root.cern.ch) using Clang.jl in a semi-automatic way. Currently supports a subset of the most commonly used ROOT classes and methods, among them

* TTree, TBranch
* TFile, TDirectory, TDirectoryFile
* TH1D
* TCollection, TList, TKey

# Installation

Make sure you have ROOT set up, then simply do

> make

# Usage


## TTrees
Support tabular data storage.
~~~
#file: example/ttree.jl
#run as: julia example/ttree.jl
using ROOT

tf = TFile("test.root", "RECREATE")
ttree = TTree("my_tree", "My Tree")

#branch variable should be array with length 1
x = Float64[0]
px = convert(Ptr{Void}, x)
br = Branch(ttree, "x", px, "x/D")

for i=1:10000
    x[1] = randn()
    Fill(ttree)
end

Write(tf)
Close(tf)
~~~
