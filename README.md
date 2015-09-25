# ROOT.jl

Wraps ROOT (http://root.cern.ch) using Clang.jl in a semi-automatic way. Currently supports a subset of the most commonly used ROOT classes and methods, among them:

* TTree, TChain, TBranch
* TFile, TDirectory, TDirectoryFile
* TH1D, TH2D
* TCollection, TList, TKey

This wrapper is a very thin C layer on top of the ROOT C++ library and no runtime interpreter (e.g. CINT or Cling) is called for the core functions. Therefore, this is theoretically the fastest possible wrapper one can use short of using C++ directly.

One can access the full ROOT framework though the ``process_line(cmd::ASCIIString)`` wrapper.

See also https://github.com/jpata/ROOTDataFrames.jl for an interface between TTrees and DataFrames.
See also https://github.com/jpata/ROOTHistograms.jl for an interface between https://github.com/JuliaStats/StatsBase.jl histograms and julia histograms.

# Installation

You need ROOT v6 and julia v0.4. After configuring ROOT using `thisroot.sh`, execute the following in a julia prompt
~~~
> Pkg.clone("https://github.com/jpata/ROOT.jl.git")
> Pkg.build("ROOT")
ROOT.jl compiled!
Add the following to your ~/.bashrc or ~/.bash_profile:
alias rjulia="/Users/joosep/.julia/v0.4/ROOT/julia"
~~~

Now run the ROOT-enabled julia interpreter using `/Users/joosep/.julia/v0.4/ROOT/julia`
~~~
> using ROOT
> Pkg.test("ROOT")
> h = TH1D("hist", "My Hist", Int32(10), 0.0, 100.0)
~~~

This will create a new executable `julia` in the ROOT.jl package directory. This must be used as the julia interpreter if you want to simultaneously use ROOT.
# Usage

Short examples are given under the `example` directory. In general, the use pattern is very similar to PyROOT. One should keep in mind that every `TObject` in julia is a pointer to an object allocated on the heap (using `new` in C++).

## example TTrees

These are the main workhorse of ROOT, which support fast row-based and disk-backed data storage for simple data types.

~~~
#file: example/ttree.jl
#run as: rjulia example/ttree.jl
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

# Known issues

1. ROOT.jl supports only ROOT 6
2. When calling `using ROOT` from the standard julia REPL that comes with julia (without having recompiled as in this module), Cling crashes/segfaults: **always use rjulia with ROOT.jl**
