//c++ `root-config --cflags --libs` -shared -fPIC gen/tarray.cc -o gen/tarray
#include <TArray.h>
extern "C" {
 Int_t TArray_GetSize1(TArray* __obj) {
  return __obj->GetSize();
}
} //extern C
