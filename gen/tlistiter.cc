//c++ `root-config --cflags --libs` -shared -fPIC gen/tlistiter.cc -o gen/tlistiter
#include <TList.h>
extern "C" {
TListIter* TListIter_TListIter1(const TList* l,  Bool_t dir) {
  return new TListIter(l, dir);
}
 TObject* TListIter_Next1(TListIter* __obj ) {
  return __obj->Next();
}
 void TListIter_Reset1(TListIter* __obj ) {
  return __obj->Reset();
}
} //extern C
