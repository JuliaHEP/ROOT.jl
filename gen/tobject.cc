//c++ `root-config --cflags --libs` -shared -fPIC gen/tobject.cc -o gen/tobject
#include <TObject.h>
extern "C" {
char* TObject_GetName1(TObject* __obj ) {
  return __obj->GetName();
}
char* TObject_GetTitle1(TObject* __obj ) {
  return __obj->GetTitle();
}
void TObject_Print1(TObject* __obj, Option_t* option) {
  return __obj->Print(option);
}
Int_t TObject_Write1(TObject* __obj, char* name, Int_t option, Int_t bufsize) {
  return __obj->Write(name, option, bufsize);
}
Int_t TObject_Write2(TObject* __obj, char* name, Int_t option, Int_t bufsize) {
  return __obj->Write(name, option, bufsize);
}
} //extern C
