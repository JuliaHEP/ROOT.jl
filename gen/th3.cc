//c++ `root-config --cflags --libs` -shared -fPIC gen/th2.cc -o gen/th2
#include <TH3.h>
extern "C" {
 Int_t TH3_Fill1(TH3* __obj,  Double_t x,  Double_t y, Double_t z) {
  return __obj->Fill(x, y, z);
}
 Int_t TH3_Fill2(TH3* __obj,  Double_t x,  Double_t y, Double_t z,  Double_t w) {
  return __obj->Fill(x, y, z, w);
}
//  Int_t TH3_Fill3(TH3* __obj,  Double_t x, const char* namey,  Double_t w) {
//   return __obj->Fill(x, namey, w);
// }
//  Int_t TH3_Fill4(TH3* __obj, const char* namex,  Double_t y,  Double_t w) {
//   return __obj->Fill(namex, y, w);
// }
//  Int_t TH3_Fill5(TH3* __obj, const char* namex, const char* namey,  Double_t w) {
//   return __obj->Fill(namex, namey, w);
// }
 
Double_t TH3_GetBinLowEdgeX(TH3* __obj, int n) {
  return __obj->GetXaxis()->GetBinLowEdge(n);
}

Double_t TH3_GetBinLowEdgeY(TH3* __obj, int n) {
  return __obj->GetYaxis()->GetBinLowEdge(n);
}

Double_t TH3_GetBinLowEdgeZ(TH3* __obj, int n) {
  return __obj->GetZaxis()->GetBinLowEdge(n);
}
} //extern C
