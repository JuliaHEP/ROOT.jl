//c++ `root-config --cflags --libs` -shared -fPIC gen/ttree.cc -o gen/ttree
#include <TTree.h>
extern "C" {
TTree* TTree_TTree1() {
  return new TTree();
}
TTree* TTree_TTree2(char* name, char* title, Int_t splitlevel) {
  return new TTree(name, title, splitlevel);
}
Int_t TTree_Branch1(TTree* __obj, TCollection* list, Int_t bufsize, Int_t splitlevel, char* name) {
  return __obj->Branch(list, bufsize, splitlevel, name);
}
Int_t TTree_Branch2(TTree* __obj, TList* list, Int_t bufsize, Int_t splitlevel) {
  return __obj->Branch(list, bufsize, splitlevel);
}
Int_t TTree_Branch3(TTree* __obj, char* folder, Int_t bufsize, Int_t splitlevel) {
  return __obj->Branch(folder, bufsize, splitlevel);
}
TBranch* TTree_Branch4(TTree* __obj, char* name, void* address, char* leaflist, Int_t bufsize) {
  return __obj->Branch(name, address, leaflist, bufsize);
}
TBranch* TTree_Branch6(TTree* __obj, char* name, Long_t address, char* leaflist, Int_t bufsize) {
  return __obj->Branch(name, address, leaflist, bufsize);
}
TBranch* TTree_Branch7(TTree* __obj, char* name, int address, char* leaflist, Int_t bufsize) {
  return __obj->Branch(name, address, leaflist, bufsize);
}
TBranch* TTree_Branch8(TTree* __obj, char* name, char* classname, void* addobj, Int_t bufsize, Int_t splitlevel) {
  return __obj->Branch(name, classname, addobj, bufsize, splitlevel);
}
Int_t TTree_Fill1(TTree* __obj ) {
  return __obj->Fill();
}
Long64_t TTree_GetEntries1(TTree* __obj ) {
  return __obj->GetEntries();
}
Long64_t TTree_GetEntries2(TTree* __obj, char* selection) {
  return __obj->GetEntries(selection);
}
TObjArray* TTree_GetListOfBranches1(TTree* __obj ) {
  return __obj->GetListOfBranches();
}
Int_t TTree_Write1(TTree* __obj, char* name, Int_t option, Int_t bufsize) {
  return __obj->Write(name, option, bufsize);
}
Int_t TTree_Write2(TTree* __obj, char* name, Int_t option, Int_t bufsize) {
  return __obj->Write(name, option, bufsize);
}
} //extern C
