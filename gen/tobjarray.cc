//c++ `root-config --cflags --libs` -shared -fPIC gen/tobjarray.cc -o gen/tobjarray
#include <TObjArray.h>
extern "C" {
TObjArray* TObjArray_TObjArray1(Int_t s, Int_t lowerBound) {
  return new TObjArray(s, lowerBound);
}
} //extern C
