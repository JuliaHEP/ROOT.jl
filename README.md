# ROOT.jl

[![Linux](https://github.com/JuliaHEP/ROOT.jl/actions/workflows/test-linux.yml/badge.svg)](https://github.com/JuliaHEP/ROOT.jl/actions/workflows/test-linux.yml) [![macOS](https://github.com/JuliaHEP/ROOT.jl/actions/workflows/test-macos.yml/badge.svg)](https://github.com/JuliaHEP/ROOT.jl/actions/workflows/test-macos.yml)


## 📣 New: use of the built-in Julia package manager to install ROOT libraries on Linux.

Release 0.3.4 bring interactive help to all types and methods of ROOT.jl.

## 📣 New: use of the built-in Julia package manager to install ROOT libraries on Linux.

Starting from release 0.3.3, the built-in Julia package manager is used to install the C++ ROOT framework. This mechansim replace the Conda one, which was introduced as an interim solution and rapidly showed its limits. The ROOT libraries (and also also executables) are package in the `ROOT_jll` [JLL](https://docs.binarybuilder.org/stable/jll/#JLL-packages) package. 

📝 Automatic installation of the ROOT libraries is currently not supported for MacOS. It was supported for a short time by the Conda mechanism, before an update of the Conda forge repository broke the dependencies. On MacOS, the C++ ROOT framework must be installed separately using one of the [method supported by ROOT](https://root.cern/install/).

## Introduction

ROOT.jl is a Julia interface to the C++ [ROOT Data analysis framework](https://root.cern/) used in the high energy physics community.

It is a work-in-progress package. It targets persons used to the ROOT framework and wishing to access it from Julia.

The project aims to provide access to the complete ROOT C++ API with a one-to-one mapping. Several ROOT classes are currently supported. Simplification of the API is not in the scope of the package. The API is already very convenient for some functionalities, like histogramming, histogram fit and plotting. The C++ interface to read and write `TTree` does not map well in Julia. A simplification of the API for I/O with a better Julia integration will be provided by a front end package in the contact of the [ROOTIO](https://github.com/JuliaHEP/ROOTIO) project.

Function documentation for the Julia help command is not available yet. Please refer to the [C++ ROOT reference guide](https://root.cern/doc/master/) for API documentation.

Since release 0.3.0, ROOT.jl uses [CxxWrap](https://github.com/JuliaInterop/CxxWrap.jl) to interface to the C++ libraries and the wrappers were generated using [WrapIt!](https://github.com/grasph/wrapit). Releases 0.1.0 and 0.2.0 were based on [Cxx.jl](https://github.com/JuliaInterop/Cxx.jl), providing an access to the full ROOT C++ API, while release 0.3.0+ covers a subset of classes, but requiring use of the outdated Julia version 1.3.

## Supported platforms

Linux and MacOS.

## Installation

To install the latest release, type from the Julia REPL, type `]` to enter in the package manager and then,

```
add ROOT
```

If you are on MacOS, read the MacOS part of the next section.

The development version (github HEAD) can be installed using,

```
dev https://github.com/JuliaHEP/ROOT.jl
build ROOT
```

## C++ ROOT backend installation

### Linux

On Linux, the C++ ROOT framework used as backend is bundled in the `ROOT_jll` Julia package that is installed automatically. This is the default and recommended option on Linux.

Use of C++ ROOT framework software installed outside of Julia is also possible. For this, the [`ROOTprefs.jl`](https://github.com/JuliaHEP/ROOTprefs.jl) should be used to change the default backend installation mode. This has to be done before the `ROOT` module is imported. Each `ROOT.jl` package is tight to one or few C++ ROOT versions: see the list in section [Backend versions](#versions).

### MacOS

The `ROOT_jll` package does not include yet the libraries for MacOS ([*](#footnote1)). Therefore, the user needs to take care of installing the C++ `ROOT` framework of the proper release: see next section for the required or do `import ROOT`, which will show a message specifying the required release if not accessible yet.

Once the C++ `ROOT` framework installed, first run `root-config --version` to make sure it is accessible from the shell environment and the release is correct, then start Julia and import the `ROOT` module. The library providing the Julia bindings will be compiled.

If after an upgrade of `ROOT.jl`, you needed to also upgrade the C++ framework installation and the installation path changed, then run `using ROOTprefs; set_ROOTSYS()` in Julia before importing the `ROOT` module in order to update the path.

<a name="footnote1"></a>(*)The package `ROOT.jl` will still be installed, but be essentially empty on this platform.

## <a name="versions"></a>Backend versions

| Julia package<br>version | Default ROOT <br>version | Other supported<br> version(s) |
|---------------|---------|----------|
| 0.4.0         | 6.32.08 | 6.32.06 |
| 0.3.1—0.3.2   | 6.32.02 |         |
| 0.3.0         | 6.30.04 |         |

  
<br>
The Julia ROOT package  version uses ROOT release 6.32.08. If a ROOT installation is found in the default binary search paths (PATH environment variable) with this version, then it will be used. Otherwise, ROOT will be installed using [Conda](https://github.com/JuliaPy/Conda.jl) into `$HOME/.julia/Conda/3`.

## C++ / Julia mapping and symbol export

C++ classes are mapped to Julia struct with the same name. Non-static class methods are mapped to Julia methods, with the same name, taking the class instance as first argument followed by the arguments of the C++ methods. The double column `::` used for C++ namespace and for static fields in C++ is mapped to the `!` symbol: static function `f` of class `A`, `A::f()` becomes `A!f()` in Julia.

Non-static methods of C++ classes are exported, the other symbols (classes, global functions, etc) are not.

## Use Example

### Short demo

```julia
import ROOT

ROOT.demo()
```

### Simple example

```julia

#Import the module.
using ROOT

# An alias for ROOT
const R = ROOT

# Create a ROOT histogram, fill it with random events, and fit it.
h = R.TH1D("h", "Normal distribution", 100, -5., 5.)
R.FillRandom(h, "gaus")

#Draw the histogram on screen
c = R.TCanvas()
R.Draw(h)

#Fit the histogram wih a normal distribution
R.Fit(h, "gaus")

#Save the Canvas in an image file
R.SaveAs(c, "demo_ROOT.png")

#Save the histogram and the graphic canvas in the demo_ROOT_out.root file.
f = R.TFile!Open("demo_ROOT_out.root", "RECREATE")
R.Write(h)
R.Write(c)
Close(f)
```

### More examples

More examples can be found in the `examples` directory.

## Supported ROOT classes

### Classes, whose methods are bound

*See `input` list in [misc/ROOT.wit](misc/ROOT.wit)*

  - I/O and general classes:
  
     `TROOT`, `TBrowser`, `TSystem`, `TApplication`, `Rtypes`, `TNamed`, `TObject`, `TTree`, `TBranchPtr`, `TLeaf`, `TBranch`, `TTreeReader`, `TTreeReaderValue`, `TTreeReaderArray`, `TCanvas`, `TRandom`,  `TDirectory`, `TDirectoryFile`, `TFile`, `TEntryList`, `TKey`, `TObjArray`, `TVectorD`, `TVectorF`

   - The complete set of classes of the Histogram library (except `TMultiGraph`):
   
    `Foption`, `HFitInterface`, `TAxis`, `TAxisModLab`,, `TBackCompFitter`, `TBinomialEfficiencyFitter`, `TConfidenceLevel`, `TEfficiency`, `TF12`, `TF1AbsComposition`, `TF1Convolution`, `TF1`, `TF1NormSum`, `TF2`, `TF3`, `TFitResult`, `TFitResultPtr`, `TFormula`, `TFractionFitter`, `TGraph2DAsymmErrors`, `TGraph2DErrors`, `TGraph2D`, `TGraphAsymmErrors`, `TGraphBentErrors`, `TGraphDelaunay2D`, `TGraphDelaunay`, `TGraphErrors`, `TGraph`, `TGraphMultiErrors`, `TGraphSmooth`, `TGraphTime`, `TH1C`, `TH1D`, `TH1F`, `TH1`, `TH1I`, `TH1K`, `TH1S`, `TH2C`, `TH2D`, `TH2F`, `TH2`, `TH2I`, `TH2Poly`, `TH2S`, `TH3C`, `TH3D`, `TH3F`, `TH3`, `TH3I`, `TH3S`, `THistRange`, `THLimitsFinder`, `THnBase`,, `THnChain`, `THn`, `THnSparse`, `THnSparse_Internal`, `THStack`,, `TKDE`, `TLimitDataSource`, `TLimit`, `TMultiDimFit`, `TMultiGraph`, `TNDArray`, `TPolyMarker`, `TPrincipal`, `TProfile2D`,, `TProfile2Poly`, `TProfile3D`, `TProfile`, `TScatter`, `TSpline`, `TSVDUnfold`, `TVirtualFitter`, `TVirtualGraphPainter`, `TVirtualHistPainter`, `TVirtualPaveStats`
    
   - The classes from the Geometry library:
    
    `TGDMLMatrix`, `TGeant4PhysicalConstants`, `TGeant4SystemOfUnits`, `TGeoArb8`, `TGeoAtt`, `TGeoBBox`, `TGeoBoolNode`, `TGeoBranchArray`, `TGeoBuilder`, `TGeoCache`, `TGeoCompositeShape`, `TGeoCone`, `TGeoElement`, `TGeoEltu`, `TGeoExtension`, `TGeoGlobalMagField`, `TGeoHalfSpace`, `TGeoHelix`, `TGeoHype`, `TGeoManager`, `TGeoMaterial`, `TGeoMatrix`, `TGeoMedium`, `TGeoNavigator`, `TGeoNode`, `TGeoOpticalSurface`, `TGeoParaboloid`, `TGeoPara`, `TGeoParallelWorld`, `TGeoPatternFinder`, `TGeoPcon`, `TGeoPgon`, `TGeoPhysicalConstants`, `TGeoPhysicalNode`, `TGeoPolygon`, `TGeoRCPtr`, `TGeoRegion`, `TGeoScaledShape`, `TGeoShapeAssembly`, `TGeoShape`, `TGeoSphere`, `TGeoStateInfo`, `TGeoSystemOfUnits`, `TGeoTessellated`, `TGeoTorus`, `TGeoTrd1`, `TGeoTrd2`, `TGeoTube`, `TGeoTypedefs`, `TGeoUniformMagField`, `TGeoVector3`, `TGeoVolume`, `TGeoVoxelFinder`, `TGeoXtru`, `TVirtualGeoConverter`, `TVirtualGeoPainter`, `TVirtualGeoTrack`, `TVirtualMagField`
    
   
### Complete list of bound ROOT types, including classes whose methods are not exposed to Julia and list of wrapped methods

*See list in [misc/jlROOT-report.txt](misc/jlROOT-report.txt).*



## Missing a ROOT class?

If you miss a ROOT class and have a minimum of programming skills, we invite you to check out the code from the [ROOTjl-generator](https://github.com/JuliaHEP/ROOTjl-generator) repository. The `generate.jl` script of `ROOTjl-generator` is used to generate the contents of the `src` directory, `deps` directory and `Project.toml` file of the `ROOT.jl` package.

The class should be added in the list defined by the `input` parameter of the `src/ROOT.wit.in` configuration file. **At best, it will work out of the box.** With a bit less luck, it will fail but it can be fixed by adding few methods in the  `src/jlROOT-veto.h` to exclude them from the Julia binding. At worst, it will require changes in the [Wrapit!](https://github.com/grasph/wrapit) wrapper generator.

A wish list will also be added in the [ROOTjl-generator](https://github.com/JuliaHEP/ROOTjl-generator) to prioritize the ROOT classes to add.

## How to contribute?

New contribution is welcome. Here is a list of contributions ideas:

   1. Add support for a not-yet-supported ROOT class: see previous section.
   2. Develop a Julia script that converts the ROOT  [Doxygen](https://www.doxygen.nl/) API documentation into Julia documentation ([docstring](https://docs.julialang.org/en/v1/manual/documentation/#Advanced-Usage). The xml output format of Doxygen, designed to be parsed by a program, will be used. Contact @grasph if you are interested in this project or send a message to [Julia discourse  - HEP category](https://discourse.julialang.org/c/domain/high-energy-physics/61)
   3. Contribute to [WrapIt!](https://github.com/grasph/wrapit), the engine that generates the wrapping code needed by [CxxWrap](https://github.com/JuliaInterop/CxxWrap.jl) C++/Julia interface.
   4. Port a [ROOT tutorial](https://root.cern/doc/master/group__Tutorials.html) into Julia to be be added to the examples.
   
