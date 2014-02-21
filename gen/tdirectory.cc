//c++ `root-config --cflags --libs` -shared -fPIC gen/tdirectory.cc -o gen/tdirectory
#include <TDirectory.h>
extern "C" {
TDirectory* TDirectory_TDirectory2() {
  return new TDirectory();
}
TDirectory* TDirectory_TDirectory3(char* name, char* title, Option_t* option, TDirectory* motherDir) {
  return new TDirectory(name, title, option, motherDir);
}
void TDirectory_Close1(TDirectory* x, Option_t* option) {
  x->Close(option);
}
TObject* TDirectory_Get1(TDirectory* x, char* namecycle) {
  return x->Get(namecycle);
}
} //extern C
