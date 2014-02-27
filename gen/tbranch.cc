//c++ `root-config --cflags --libs` -shared -fPIC gen/tbranch.cc -o gen/tbranch
#include <TBranch.h>
extern "C" {
TBranch* TBranch_TBranch1() {
  return new TBranch();
}
TBranch* TBranch_TBranch2(TTree* tree, char* name, void* address, char* leaflist, Int_t basketsize, Int_t compress) {
  return new TBranch(tree, name, address, leaflist, basketsize, compress);
}
TBranch* TBranch_TBranch3(TBranch* parent, char* name, void* address, char* leaflist, Int_t basketsize, Int_t compress) {
  return new TBranch(parent, name, address, leaflist, basketsize, compress);
}
} //extern C
