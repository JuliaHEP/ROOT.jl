//c++ `root-config --cflags --libs` -shared -fPIC gen/tfile.cc -o gen/tfile
#include <TFile.h>
extern "C" {
TFile* TFile_TFile1() {
  return new TFile();
}
TFile* TFile_TFile2(const char* fname,  Option_t* option, const char* ftitle,  Int_t compress) {
  return new TFile(fname, option, ftitle, compress);
}
 void TFile_Close1(TFile* __obj,  Option_t* option) {
  return __obj->Close(option);
}
 Int_t TFile_Write1(TFile* __obj, const char* name,  Int_t opt,  Int_t bufsiz) {
  return __obj->Write(name, opt, bufsiz);
}
 Int_t TFile_Write2(TFile* __obj, const char* name,  Int_t opt,  Int_t bufsiz) {
  return __obj->Write(name, opt, bufsiz);
}
} //extern C
