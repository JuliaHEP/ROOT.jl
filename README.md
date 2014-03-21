# ROOT.jl

Wraps ROOT (http://root.cern.ch) using Clang.jl in a semi-automatic way. Currently supports a subset of the most commonly used ROOT classes and methods, among them

* TTree, TBranch
* TFile, TDirectory, TDirectoryFile
* TH1D, TH2D
* TCollection, TList, TKey

This wrapper is a very thin C layer on top of the ROOT C++ library and no runtime interpreter (e.g. CINT or Cling) is called for the core functions. Therefore, this is theoretically the fastest possible wrapper one can use short of using C++ directly.

One can access the full ROOT framework though the ``process_line(cmd::ASCIIString)`` wrapper.

# Installation

Make sure you have ROOT set up, then simply do

> make

to create `libroot.{so/dylib}`.

# Usage

Short examples are given under the `example` directory. In general, the use pattern is very similar to PyROOT. One should keep in mind that every `TObject` in julia is a pointer to an object allocated on the heap (using `new` in C++).

## TTrees

These are the main workhorse of ROOT, which supports fast row-based and disk-backed data storage.

~~~
#file: example/ttree.jl
#run as: julia example/ttree.jl
using ROOT

tf = TFile("test.root", "RECREATE")
ttree = TTree("my_tree", "My Tree")

#branch variable should be array with length 1
x = Float64[0.0]
px = convert(Ptr{Void}, x)
br = Branch(ttree, "x", px, "x/D")

for i=1:10000
    x[1] = randn()
    Fill(ttree)
end

Write(tf)
Close(tf)
~~~
