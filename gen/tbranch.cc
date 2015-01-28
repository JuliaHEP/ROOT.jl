//c++ `root-config --cflags --libs` -shared -fPIC gen/tbranch.cc -o gen/tbranch
#include <TBranch.h>
extern "C" {
TBranch* TBranch_TBranch1() {
  return new TBranch();
}
TBranch* TBranch_TBranch2( TTree* tree, const char* name,  void* address, const char* leaflist,  Int_t basketsize,  Int_t compress) {
  return new TBranch(tree, name, address, leaflist, basketsize, compress);
}
TBranch* TBranch_TBranch3( TBranch* parent, const char* name,  void* address, const char* leaflist,  Int_t basketsize,  Int_t compress) {
  return new TBranch(parent, name, address, leaflist, basketsize, compress);
}
const char* TBranch_GetClassName1(TBranch* __obj ) {
  return __obj->GetClassName();
}
 TObjArray* TBranch_GetListOfLeaves1(TBranch* __obj ) {
  return __obj->GetListOfLeaves();
}
 void TBranch_SetAddress1(TBranch* __obj,  void* add) {
  return __obj->SetAddress(add);
}
 int TBranch_GetEntry1(TBranch* __obj, long entry) {
  return __obj->GetEntry(entry);
}
} //extern C
