# ROOT.jl: ROOT bindings for julia

Provides basic access to the [CERN ROOT Framework](https://root.cern.ch/)
for the Julia language.

**Note:** This is work in progress, expect bugs and crashes.


## Requirements

* [Julia v1.3](https://julialang.org/downloads/oldreleases/).
* [CXX.jl](https://github.com/Keno/Cxx.jl) - note that Cxx.jl currently
  (v0.3.4) doesn't support Julia v1.4 or newer.
* ROOT v6.24.02 or newer (`root-config` must be on your `$PATH`).


## Usage

Enable RTTI for Cxx.jl:

```shell
export JULIA_CXX_RTTI="1"
```

Install ROOT.jl:

```
julia> import Pkg;
julia> Pkg.add(Pkg.PackageSpec(url="https://github.com/JuliaHEP/ROOT.jl.git"))
```

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


## ROOT's graphical user interface

If you want to use ROOT's GUI, run `rootgui()` to start a Julia timer that
runs ROOT GUI loop. To open a `TBrowser`, for example, run

```julia
cxxinclude("TBrowser.h")
rootgui()

icxx"new TBrowser();"
```

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
