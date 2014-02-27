//c++ `root-config --cflags --libs` -shared -fPIC gen/tcollection.cc -o gen/tcollection
#include <TCollection.h>
extern "C" {
Int_t TCollection_GetEntries1(TCollection* __obj ) {
  return __obj->GetEntries();
}
} //extern C
