//c++ `root-config --cflags --libs` -shared -fPIC gen/tlist.cc -o gen/tlist
#include <TList.h>
extern "C" {
TList* TList_TList1() {
  return new TList();
}
TObject* TList_At1(TList* __obj, Int_t idx) {
  return __obj->At(idx);
}
} //extern C
