# ROOT.jl

[![Linux](https://github.com/JuliaHEP/ROOT.jl/actions/workflows/test-linux.yml/badge.svg)](https://github.com/JuliaHEP/ROOT.jl/actions/workflows/test-linux.yml) [![macOS](https://github.com/JuliaHEP/ROOT.jl/actions/workflows/test-macos.yml/badge.svg)](https://github.com/JuliaHEP/ROOT.jl/actions/workflows/test-macos.yml)

## 📣 New: Support of recent Julia releases!

ROOT.jl was not working with Julia version beyond 1.3 due to limitation of the [Cxx.jl](https://github.com/JuliaInterop/Cxx.jl) C++/Julia interface. Release 0.3.0 brings a new implementation based on the [CxxWrap](https://github.com/JuliaInterop/CxxWrap.jl) interface that supports recent Julia versions. The counterpart is a smaller coverage of ROOT classes: see Section C++/Julia interface.

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

The developement version (github HEAD) can be installed using,

```
dev https://github.com/JuliaHEP/ROOT.jl
build ROOT
```

⚠ Installation can stay several minutes (ten of minutes on macOS) on the following message.


```
Building ROOT → `.../build.log`
  Progress [=                  ]1/2
```

This is due to the installation of ROOT and compilation of the wrapper library. **Be patient**. You can open the indicated `build.log` file to see the progress.

💡 Sometimes the `build.jl` script is not launched by the package manager. It is for instance the case in the development mode (package added with the `dev` command). In case of the command `add ...` command fail, try first to run `build ROOT` from the package manager prompt before investigating further.

## ROOT version

Current ROOT version uses ROOT release 6.30.04. If a ROOT installation is found in the default binary search paths (PATH environment variable) with this version, then it will be used. Otherwise, ROOT will be installed using [Conda](https://github.com/JuliaPy/Conda.jl) into `$HOME/.julia/Conda/3`.

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

### Principal supported ROOT classes:

  - `TSystem`
  - `TROOT`
  - `TTree`
  - `TBranch`
  - `TCanvas`
  - `TH1`
  - `TRandom`
  - `TAxis`
  - `TGraph`
  - `TF1`
  - `TApplication`
  - `TFile`, `TDirectoryFile`
  - `TTreeReader`, `TTreeReaderValue`, `TTreeReaderArray`
  - `TVectorD`, `TVectorF`
  - `TObject`, `TNamed`

### Complete list of suppported ROOT class and types

   - CpuInfo_t
   - FileStat_t
   - Foption_t
   - _IO_FILE
   - MemInfo_t
   - ProcInfo_t
   - RedirectHandle_t
   - ROOT::Internal::GetFunctorType
   - ROOT::Internal::TF1Builder
   - ROOT::Internal::TParBranchProcessingRAII
   - ROOT::Internal::TStringView
   - ROOT::Internal::TTreeReaderArrayBase
   - ROOT::Internal::TTreeReaderValueBase
   - ROOT::TIOFeatures
   - SysInfo_t
   - TApplication
   - TApplicationImp
   - TArrayC
   - TArrayD
   - TAxis
   - TBranch
   - TBranchPtr
   - TBuffer
   - TCanvas
   - TClass
   - TCollection
   - TDataType
   - TDatime
   - TDictionary
   - TDirectory
   - TDirectoryFile
   - TEntryList
   - TF1
   - TF1Parameters
   - TF1::TF1FunctorPointer
   - TFile
   - TFileHandler
   - TFileOpenHandle
   - TFitResultPtr
   - TFormula
   - TGraph
   - TH1
   - TH1C
   - TH1D
   - TH1F
   - TH1I
   - TH1S
   - TInetAddress
   - TInterpreter
   - TIterator
   - TLeaf
   - TList
   - TMethodCall
   - TNamed
   - TObjArray
   - TObject
   - TObjLink
   - TPad
   - TProcessEventTimer
   - TRandom
   - TROOT
   - TSeqCollection
   - TSignalHandler
   - TStdExceptionHandler
   - TStreamerInfo
   - TString
   - TSystem
   - TTime
   - TTimer
   - TTreeFriendLeafIter
   - TTreeReader
   - TTreeReaderArray
   - TTreeReader::Iterator_t
   - TTreeReaderValue
   - TTree, TTree::TClusterIterator
   - TUrl
   - TVectorT
   - TVirtualMutex
   - TVirtualPad
   - TVirtualTreePlayer
   - UserGroup_t

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
   
