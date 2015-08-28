//c++ `root-config --cflags --libs` -shared -fPIC gen/th2.cc -o gen/th2
#include <TH2.h>
extern "C" {
 Int_t TH2_Fill1(TH2* __obj,  Double_t x,  Double_t y) {
  return __obj->Fill(x, y);
}
 Int_t TH2_Fill2(TH2* __obj,  Double_t x,  Double_t y,  Double_t w) {
  return __obj->Fill(x, y, w);
}
 Int_t TH2_Fill3(TH2* __obj,  Double_t x, const char* namey,  Double_t w) {
  return __obj->Fill(x, namey, w);
}
 Int_t TH2_Fill4(TH2* __obj, const char* namex,  Double_t y,  Double_t w) {
  return __obj->Fill(namex, y, w);
}
 Int_t TH2_Fill5(TH2* __obj, const char* namex, const char* namey,  Double_t w) {
  return __obj->Fill(namex, namey, w);
}

Double_t TH2_GetBinLowEdgeY(TH2* __obj, int n) {
  return __obj->GetYaxis()->GetBinLowEdge(n);
}

} //extern C
