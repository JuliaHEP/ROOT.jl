//c++ `root-config --cflags --libs` -shared -fPIC gen/tfile.cc -o gen/tfile
#include <TFile.h>
extern "C" {
TFile* TFile_TFile2() {
  return new TFile();
}
TFile* TFile_TFile3(char* fname, Option_t* option, char* ftitle, Int_t compress) {
  return new TFile(fname, option, ftitle, compress);
}
void TFile_Close1(TFile* x, Option_t* option) {
  x->Close(option);
}
Int_t TFile_Write1(TFile* x, char* name, Int_t opt, Int_t bufsiz) {
  return x->Write(name, opt, bufsiz);
}
Int_t TFile_Write2(TFile* x, char* name, Int_t opt, Int_t bufsiz) {
  return x->Write(name, opt, bufsiz);
}
} //extern C
