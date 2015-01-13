//c++ `root-config --cflags --libs` -shared -fPIC gen/th1d.cc -o gen/th1d
#include <TH1D.h>
extern "C" {
TH1D* TH1D_TH1D1() {
  return new TH1D();
}
TH1D* TH1D_TH1D2(const char* name, const char* title,  Int_t nbinsx,  Double_t xlow,  Double_t xup) {
  return new TH1D(name, title, nbinsx, xlow, xup);
}
TH1D* TH1D_TH1D3(const char* name, const char* title,  Int_t nbinsx, const Float_t* xbins) {
  return new TH1D(name, title, nbinsx, xbins);
}
TH1D* TH1D_TH1D4(const char* name, const char* title,  Int_t nbinsx, const Double_t* xbins) {
  return new TH1D(name, title, nbinsx, xbins);
}

double TH1D_GetRMS(TH1D* h, int axis) {
  return h->GetRMS(axis);
}

double TH1D_GetMean(TH1D* h, int axis) {
  return h->GetMean(axis);
}
} //extern C
