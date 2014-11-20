//c++ `root-config --cflags --libs` -shared -fPIC gen/tkey.cc -o gen/tkey
#include <TKey.h>
extern "C" {
 TObject* TKey_ReadObj1(TKey* __obj ) {
  return __obj->ReadObj();
}

const char* TKey_GetClassName1(TKey* __obj ) {
  return __obj->GetClassName();
}
} //extern C
