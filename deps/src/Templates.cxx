#include "Templates.h"

std::vector<TBranch*> GetListOfBranches(TTree* obj){
  TObjArray* a = obj->GetListOfBranches();
  std::vector<TBranch*> v;
  auto len = a->GetEntries();
  v.reserve(len);
  for(size_t i = 0; i < len; ++i){
    v.push_back(dynamic_cast<TBranch*>(a->At(i)));
  }
  return v;
}

std::vector<TLeaf*> GetListOfLeaves(TTree* obj){
  TObjArray* a = obj->GetListOfLeaves();
  std::vector<TLeaf*> v;
  auto len = a->GetEntries();
  v.reserve(len);
  for(size_t i = 0; i < len; ++i){
    v.push_back(dynamic_cast<TLeaf*>(a->At(i)));
  }
  return v;
}

