using Cxx
const ROOT_INCDIR = strip(readstring(`root-config --incdir`))
const ROOT_LIBDIR = strip(readstring(`root-config --libdir`))
addHeaderDir(ROOT_INCDIR, kind=C_System)
for lib in ["Core", "RIO", "Hist"]
    Libdl.dlopen("$ROOT_LIBDIR/lib$lib.so", Libdl.RTLD_LAZY)
end

cxx"""#include <TFile.h> """
cxx"""#include <TH1D.h> """

tf = @cxxnew TFile(pointer("asd.root"), pointer("RECREATE"))
th = @cxxnew TH1D(pointer("h"), pointer("h"), 100, -1.0, 1.0)

for i=1:100000
    @cxx th->Fill(randn())
end

@cxx tf->Write()
@cxx tf->Close()

tf2 = @cxx TFile::Open(pointer("asd.root"))
th2 = cast(@cxx(tf2->Get(pointer("h"))), typeof(th))
