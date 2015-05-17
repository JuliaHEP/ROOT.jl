//c++ `root-config --cflags --libs` -shared -fPIC gen/th3.cc -o gen/th3
#include <TH3.h>
extern "C" {
 Int_t TH3_Fill1(TH3* __obj,  Double_t x,  Double_t y,  Double_t z) {
  return __obj->Fill(x, y, z);
}
 Int_t TH3_Fill2(TH3* __obj,  Double_t x,  Double_t y,  Double_t z,  Double_t w) {
  return __obj->Fill(x, y, z, w);
}
 Int_t TH3_Fill3(TH3* __obj, const char* namex, const char* namey, const char* namez,  Double_t w) {
  return __obj->Fill(namex, namey, namez, w);
}
 Int_t TH3_Fill4(TH3* __obj, const char* namex,  Double_t y, const char* namez,  Double_t w) {
  return __obj->Fill(namex, y, namez, w);
}
 Int_t TH3_Fill5(TH3* __obj, const char* namex, const char* namey,  Double_t z,  Double_t w) {
  return __obj->Fill(namex, namey, z, w);
}
 Int_t TH3_Fill6(TH3* __obj,  Double_t x, const char* namey, const char* namez,  Double_t w) {
  return __obj->Fill(x, namey, namez, w);
}
 Int_t TH3_Fill7(TH3* __obj,  Double_t x, const char* namey,  Double_t z,  Double_t w) {
  return __obj->Fill(x, namey, z, w);
}
 Int_t TH3_Fill8(TH3* __obj,  Double_t x,  Double_t y, const char* namez,  Double_t w) {
  return __obj->Fill(x, y, namez, w);
}
} //extern C
