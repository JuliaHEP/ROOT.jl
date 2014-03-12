//c++ `root-config --cflags --libs` -shared -fPIC gen/th2d.cc -o gen/th2d
#include <TH2D.h>
extern "C" {
TH2D* TH2D_TH2D1() {
  return new TH2D();
}
TH2D* TH2D_TH2D2(char* name, char* title, Int_t nbinsx, Double_t xlow, Double_t xup, Int_t nbinsy, Double_t ylow, Double_t yup) {
  return new TH2D(name, title, nbinsx, xlow, xup, nbinsy, ylow, yup);
}
TH2D* TH2D_TH2D3(char* name, char* title, Int_t nbinsx, Double_t* xbins, Int_t nbinsy, Double_t ylow, Double_t yup) {
  return new TH2D(name, title, nbinsx, xbins, nbinsy, ylow, yup);
}
TH2D* TH2D_TH2D4(char* name, char* title, Int_t nbinsx, Double_t xlow, Double_t xup, Int_t nbinsy, Double_t* ybins) {
  return new TH2D(name, title, nbinsx, xlow, xup, nbinsy, ybins);
}
TH2D* TH2D_TH2D5(char* name, char* title, Int_t nbinsx, Double_t* xbins, Int_t nbinsy, Double_t* ybins) {
  return new TH2D(name, title, nbinsx, xbins, nbinsy, ybins);
}
TH2D* TH2D_TH2D6(char* name, char* title, Int_t nbinsx, Float_t* xbins, Int_t nbinsy, Float_t* ybins) {
  return new TH2D(name, title, nbinsx, xbins, nbinsy, ybins);
}
} //extern C
