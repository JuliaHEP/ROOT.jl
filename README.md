# ROOT.jl: ROOT bindings for julia

Provides basic access to the [CERN ROOT Framework](https://root.cern.ch/)
for the Julia language.


## Requirements

* Julia v0.5
* The current master branch of [CXX.jl](https://github.com/Keno/Cxx.jl) (until
  Cxx.jl v0.1.1 or so is released).
* ROOT-6 (ROOT-5 may work, but is no longer recommended)


## Usage

Enable RTTI for Cxx.jl:

```shell
export JULIA_CXX_RTTI="1"
```

Install ROOT.jl:

```
julia> Pkg.add("ROOT")
```

ROOT.jl will install a special Julia executable that initializes ROOT
before starting Julia. This avoids conflicts between Cling's LLVM instance
and Julia's LLVM instance. The ROOT-compatible Julia binary resides at:
`joinpath(Pkg.dir("ROOT"), "deps", "usr", "bin", "julia")`.

You can directly use the standard ROOT API via Cxx.jl:

```julia
using ROOT, Cxx
cxxinclude("TCanvas.h")
cxxinclude("TH1D.h")

canvas = icxx"new TCanvas();"
hist = icxx"""new TH1D("hist", "Hist", 20, -4, 4);"""
for i in 1:100000
    @cxx hist->Fill(randn())
end
@cxx hist->Draw()
@cxx canvas->SaveAs(pointer("myhist.png"))
```

Julia API wrappers for specific ROOT functionalities are left to more
specialized packages.


## Thread-safety

During startup, ROOT.jl will also enable basic thread-safety for ROOT
(via `TThread::Initialize()`).

It is possible to run certain ROOT operations in multi-threaded Julia code
(e.g. TTree I/O, provided each thread uses a separate `TFile`/`TTree` resp.
`TChain` instance.). However, certain operations (e.g. creating and deleting
a `TChain`) are not thread-safe. Use

```julia
lock(gROOTMutex()) do
    # ... non thread-safe code ...
end
```

for non-thread-safe code blocks within multi-threaded code.
