//c++ `root-config --cflags --libs` -shared -fPIC gen/th1.cc -o gen/th1
#include <TH1.h>
extern "C" {
Int_t TH1_Fill1(TH1* __obj, Double_t x) {
  return __obj->Fill(x);
}
Int_t TH1_Fill2(TH1* __obj, Double_t x, Double_t w) {
  return __obj->Fill(x, w);
}
Int_t TH1_Fill3(TH1* __obj, char* name, Double_t w) {
  return __obj->Fill(name, w);
}
Double_t TH1_GetEntries1(TH1* __obj ) {
  return __obj->GetEntries();
}
Double_t TH1_Integral1(TH1* __obj, Option_t* option) {
  return __obj->Integral(option);
}
Double_t TH1_Integral2(TH1* __obj, Int_t binx1, Int_t binx2, Option_t* option) {
  return __obj->Integral(binx1, binx2, option);
}
} //extern C
