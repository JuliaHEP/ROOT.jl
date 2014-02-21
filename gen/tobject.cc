//c++ `root-config --cflags --libs` -shared -fPIC gen/tobject.cc -o gen/tobject
#include <TObject.h>
extern "C" {
void TObject_Print1(TObject* x, Option_t* option) {
  x->Print(option);
}
Int_t TObject_Write1(TObject* x, char* name, Int_t option, Int_t bufsize) {
  return x->Write(name, option, bufsize);
}
Int_t TObject_Write2(TObject* x, char* name, Int_t option, Int_t bufsize) {
  return x->Write(name, option, bufsize);
}
} //extern C
