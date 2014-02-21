//c++ `root-config --cflags --libs` -shared -fPIC gen/ttree.cc -o gen/ttree
#include <TTree.h>
extern "C" {
TTree* TTree_TTree2() {
  return new TTree();
}
TTree* TTree_TTree3(char* name, char* title, Int_t splitlevel) {
  return new TTree(name, title, splitlevel);
}
Int_t TTree_Branch1(TTree* x, TCollection* list, Int_t bufsize, Int_t splitlevel, char* name) {
  return x->Branch(list, bufsize, splitlevel, name);
}
Int_t TTree_Branch2(TTree* x, TList* list, Int_t bufsize, Int_t splitlevel) {
  return x->Branch(list, bufsize, splitlevel);
}
Int_t TTree_Branch3(TTree* x, char* folder, Int_t bufsize, Int_t splitlevel) {
  return x->Branch(folder, bufsize, splitlevel);
}
TBranch* TTree_Branch4(TTree* x, char* name, void* address, char* leaflist, Int_t bufsize) {
  return x->Branch(name, address, leaflist, bufsize);
}
TBranch* TTree_Branch6(TTree* x, char* name, Long_t address, char* leaflist, Int_t bufsize) {
  return x->Branch(name, address, leaflist, bufsize);
}
TBranch* TTree_Branch7(TTree* x, char* name, int address, char* leaflist, Int_t bufsize) {
  return x->Branch(name, address, leaflist, bufsize);
}
TBranch* TTree_Branch8(TTree* x, char* name, char* classname, void* addobj, Int_t bufsize, Int_t splitlevel) {
  return x->Branch(name, classname, addobj, bufsize, splitlevel);
}
Int_t TTree_Fill1(TTree* x ) {
  return x->Fill();
}
Long64_t TTree_GetEntries1(TTree* x ) {
  return x->GetEntries();
}
Long64_t TTree_GetEntries2(TTree* x, char* selection) {
  return x->GetEntries(selection);
}
Int_t TTree_Write1(TTree* x, char* name, Int_t option, Int_t bufsize) {
  return x->Write(name, option, bufsize);
}
Int_t TTree_Write2(TTree* x, char* name, Int_t option, Int_t bufsize) {
  return x->Write(name, option, bufsize);
}
} //extern C
