# ROOT

Wraps ROOT (http://root.cern.ch) using Clang.jl.

# Installation

Make sure you have ROOT set up, then simply do (on OSX)

> make;make lib-osx

or on linux

> make;make lib-linux

To regenerate the wrappers using Clang.jl, do

> julia src/wrap_root.jl

For this, a modified branch of Clang.jl is needed

> https://github.com/jpata/Clang.jl/tree/jp/cpp_fixes

# Usage

~~~
using ROOT

#FIXME: currently, default args from Clang are not supported, so they have to be explicitly specified
#ROOT relies quite heavily on them, so it would be nice to fix

tf = TFile("test.root", "RECREATE", "my file", 6)
ttree = TTree("my_tree", "My Tree", 99)

#branch variable should be array
x = Float64[0]
px = convert(Ptr{Void}, x)
br = Branch(ttree, "x", px, "x/D", 99)

for i=1:10000
	x[1] = randn()
	Fill(ttree)
end

Write(tf, "", 1, 100)
Close(tf, "")
~~~