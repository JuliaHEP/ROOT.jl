using ROOT
using Cxx
using Base.Test

cxx"""#include <TFile.h> """
cxx"""#include <TH1D.h> """

const npoints = 100000

function fill_hist(path)
    tf = @cxxnew TFile(pointer(path), pointer("RECREATE"))
    th = @cxxnew TH1D(pointer("h"), pointer("h"), 100, -1.0, 1.0)
    
    for i=1:npoints
        @cxx th->Fill(randn())
    end
    @test @cxx(th->GetEntries()) == npoints 
    println(typeof(th)) 
    @cxx tf->Write()
    @cxx tf->Close()
end

#function open_file(path)
#    tf = @cxx TFile::Open(pointer(path))
#    th = cast(@cxx(tf->Get(pointer("h"))), Cxx.CppPtr{Cxx.CppValue{Cxx.CxxQualType{Cxx.CppBaseType{:TH1D},(false,false,false)},N},(false,false,false)})
#    @test @cxx(th->GetEntries()) == npoints 
#end

@time fill_hist("test.root")
#@time open_file("test.root")
