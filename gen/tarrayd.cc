//c++ `root-config --cflags --libs` -shared -fPIC gen/tarrayd.cc -o gen/tarrayd
#include <TArrayD.h>
extern "C" {
TArrayD* TArrayD_TArrayD1() {
  return new TArrayD();
}
TArrayD* TArrayD_TArrayD2( Int_t n) {
  return new TArrayD(n);
}
TArrayD* TArrayD_TArrayD3( Int_t n, const Double_t* array) {
  return new TArrayD(n, array);
}
 Double_t TArrayD_GetAt1(TArrayD* __obj,  Int_t i) {
  return __obj->GetAt(i);
}
 Int_t TArrayD_GetSize(TArrayD* __obj) {
  return __obj->GetSize();
}
 void TArrayD_SetAt1(TArrayD* __obj,  Double_t v,  Int_t i) {
  return __obj->SetAt(v, i);
}
} //extern C
