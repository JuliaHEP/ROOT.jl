//c++ `root-config --cflags --libs` -shared -fPIC gen/tseqcollection.cc -o gen/tseqcollection
#include <TSeqCollection.h>
extern "C" {
TObject* TSeqCollection_At1(TSeqCollection* __obj, Int_t idx) {
  return __obj->At(idx);
}
} //extern C
