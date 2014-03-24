//c++ `root-config --cflags --libs` -shared -fPIC gen/tdirectory.cc -o gen/tdirectory
#include <TDirectory.h>
extern "C" {
TDirectory* TDirectory_TDirectory1() {
  return new TDirectory();
}
TDirectory* TDirectory_TDirectory2(const char* name, const char* title,  Option_t* option,  TDirectory* motherDir) {
  return new TDirectory(name, title, option, motherDir);
}
 void TDirectory_Close1(TDirectory* __obj,  Option_t* option) {
  return __obj->Close(option);
}
 TObject* TDirectory_Get1(TDirectory* __obj, const char* namecycle) {
  return __obj->Get(namecycle);
}
 TList* TDirectory_GetListOfKeys1(TDirectory* __obj ) {
  return __obj->GetListOfKeys();
}
 TDirectory* TDirectory_mkdir1(TDirectory* __obj, const char* name, const char* title) {
  return __obj->mkdir(name, title);
}
 Bool_t TDirectory_Cd1(TDirectory* __obj, const char* path) {
  return __obj->Cd(path);
}
} //extern C
