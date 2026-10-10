#ifndef TEMPLATES_H
#define TEMPLATES_H

//#include "TTree.h"
//#include "TH1.h"
//typedef TVectorT<double> TVectorD;

class TDirectoryFile;
class TH1;
class TTree;
#include "TTreeReaderValue.h"
#include "TTreeReaderArray.h"
#include "TBranchPtr.h"
#include "Rtypes.h"
#include "ROOT/RVec.hxx"
#include <vector>

//TObject  TFileDirectory::Get(const char *namecycle) override;
inline TTree* GetTTree(TDirectoryFile& f, const char *namecycle){
  return f.Get<TTree>(namecycle);
}

inline TH1* GetTH1(TDirectoryFile& f, const char *namecycle){
  return f.Get<TH1>(namecycle);
}

#ifdef WRAPIT
#  define FCN_TEMPLATE template<>
#else
#  define FCN_TEMPLATE template
#endif

template class TTreeReaderValue<Char_t>;
template class TTreeReaderValue<UChar_t>;
template class TTreeReaderValue<Short_t>;
template class TTreeReaderValue<UShort_t>;
template class TTreeReaderValue<Int_t>;
template class TTreeReaderValue<UInt_t>;
template class TTreeReaderValue<Long_t>;
template class TTreeReaderValue<ULong_t>;
template class TTreeReaderValue<Float_t>;
template class TTreeReaderValue<Double_t>;
template class TTreeReaderValue<std::string>;
//template class TTreeReaderValue<LongDouble_t>;
//template class TTreeReaderValue<Bool_t>;
//template class TTreeReaderValue<Long64_t>;
//template class TTreeReaderValue<ULong64_t>;

template class TTreeReaderArray<Char_t>;
template class TTreeReaderArray<UChar_t>;
template class TTreeReaderArray<Short_t>;
template class TTreeReaderArray<UShort_t>;
template class TTreeReaderArray<Int_t>;
template class TTreeReaderArray<UInt_t>;
template class TTreeReaderArray<Long_t>;
template class TTreeReaderArray<ULong_t>;
template class TTreeReaderArray<Float_t>;
template class TTreeReaderArray<Double_t>;
template class TTreeReaderArray<std::string>;
//template class TTreeReaderArray<LongDouble_t>;
//template class TTreeReaderArray<Bool_t>;
//template class TTreeReaderArray<Long64_t>;
//template class TTreeReaderArray<ULong64_t>;

template class TTreeReaderValue<ROOT::RVec<Char_t>>;
template class TTreeReaderValue<ROOT::RVec<UChar_t>>;
template class TTreeReaderValue<ROOT::RVec<Short_t>>;
template class TTreeReaderValue<ROOT::RVec<UShort_t>>;
template class TTreeReaderValue<ROOT::RVec<Int_t>>;
template class TTreeReaderValue<ROOT::RVec<UInt_t>>;
template class TTreeReaderValue<ROOT::RVec<Long_t>>;
template class TTreeReaderValue<ROOT::RVec<ULong_t>>;
template class TTreeReaderValue<ROOT::RVec<Float_t>>;
template class TTreeReaderValue<ROOT::RVec<Double_t>>;
//template class TTreeReaderValue<ROOT::RVec<std::string>>;

template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<Char_t>>>;
template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<UChar_t>>>;
template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<Short_t>>>;
template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<UShort_t>>>;
template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<Int_t>>>;
template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<UInt_t>>>;
template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<Long_t>>>;
template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<ULong_t>>>;
template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<Float_t>>>;
template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<Double_t>>>;
//template class TTreeReaderValue<ROOT::RVec<ROOT::RVec<std::string>>>;


template<typename T>
std::size_t GetSize(const TTreeReaderArray<T>* x){ return x->GetSize(); }
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Char_t>* x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<UChar_t>* x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Short_t>* x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<UShort_t>* x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Int_t>* x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<UInt_t>* x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Long_t>* x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<ULong_t>* x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Float_t>* x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Double_t>* x);
//FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<std::string>* x);

template<typename T>
std::size_t GetSize(const TTreeReaderArray<T>& x){ return x.GetSize(); }
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Char_t>& x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<UChar_t>& x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Short_t>& x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<UShort_t>& x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Int_t>& x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<UInt_t>& x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Long_t>& x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<ULong_t>& x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Float_t>& x);
FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<Double_t>& x);
//FCN_TEMPLATE std::size_t GetSize(const TTreeReaderArray<std::string>& x);


template class TBranchPtr<Char_t>;
template class TBranchPtr<UChar_t>;
template class TBranchPtr<Short_t>;
template class TBranchPtr<UShort_t>;
template class TBranchPtr<Int_t>;
template class TBranchPtr<UInt_t>;
template class TBranchPtr<Long_t>;
template class TBranchPtr<ULong_t>;
template class TBranchPtr<Float_t>;
template class TBranchPtr<Double_t>;

template class TBranchPtr<std::vector<Char_t>>;
template class TBranchPtr<std::vector<UChar_t>>;
template class TBranchPtr<std::vector<Short_t>>;
template class TBranchPtr<std::vector<UShort_t>>;
template class TBranchPtr<std::vector<Int_t>>;
template class TBranchPtr<std::vector<UInt_t>>;
template class TBranchPtr<std::vector<Long_t>>;
template class TBranchPtr<std::vector<ULong_t>>;
template class TBranchPtr<std::vector<Float_t>>;
template class TBranchPtr<std::vector<Double_t>>;

template class TBranchPtr<ROOT::RVec<Char_t>>;
template class TBranchPtr<ROOT::RVec<UChar_t>>;
template class TBranchPtr<ROOT::RVec<Short_t>>;
template class TBranchPtr<ROOT::RVec<UShort_t>>;
template class TBranchPtr<ROOT::RVec<Int_t>>;
template class TBranchPtr<ROOT::RVec<UInt_t>>;
template class TBranchPtr<ROOT::RVec<Long_t>>;
template class TBranchPtr<ROOT::RVec<ULong_t>>;
template class TBranchPtr<ROOT::RVec<Float_t>>;
template class TBranchPtr<ROOT::RVec<Double_t>>;
//template class TBranchPtr<ROOT::RVec<std::string>>;

template class TBranchPtr<ROOT::RVec<ROOT::RVec<Char_t>>>;
template class TBranchPtr<ROOT::RVec<ROOT::RVec<UChar_t>>>;
template class TBranchPtr<ROOT::RVec<ROOT::RVec<Short_t>>>;
template class TBranchPtr<ROOT::RVec<ROOT::RVec<UShort_t>>>;
template class TBranchPtr<ROOT::RVec<ROOT::RVec<Int_t>>>;
template class TBranchPtr<ROOT::RVec<ROOT::RVec<UInt_t>>>;
template class TBranchPtr<ROOT::RVec<ROOT::RVec<Long_t>>>;
template class TBranchPtr<ROOT::RVec<ROOT::RVec<ULong_t>>>;
template class TBranchPtr<ROOT::RVec<ROOT::RVec<Float_t>>>;
template class TBranchPtr<ROOT::RVec<ROOT::RVec<Double_t>>>;
//template class TBranchPtr<ROOT::RVec<ROOT::RVec<std::string>>>;

FCN_TEMPLATE TBranchPtr<Char_t>   Branch(TTree&, const char* name, Char_t&   obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<UChar_t>  Branch(TTree&, const char* name, UChar_t&  obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<Short_t>  Branch(TTree&, const char* name, Short_t&  obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<UShort_t> Branch(TTree&, const char* name, UShort_t& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<Int_t>    Branch(TTree&, const char* name, Int_t&    obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<UInt_t>   Branch(TTree&, const char* name, UInt_t&   obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<Long_t>   Branch(TTree&, const char* name, Long_t&   obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ULong_t>  Branch(TTree&, const char* name, ULong_t&  obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<Float_t>  Branch(TTree&, const char* name, Float_t&  obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<Double_t> Branch(TTree&, const char* name, Double_t& obj, Int_t bufsize, Int_t splitlevel);

FCN_TEMPLATE TBranchPtr<std::vector<Char_t>>   Branch(TTree&, const char* name, std::vector<Char_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<std::vector<UChar_t>>  Branch(TTree&, const char* name, std::vector<UChar_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<std::vector<Short_t>>  Branch(TTree&, const char* name, std::vector<Short_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<std::vector<UShort_t>> Branch(TTree&, const char* name, std::vector<UShort_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<std::vector<Int_t>>    Branch(TTree&, const char* name, std::vector<Int_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<std::vector<UInt_t>>   Branch(TTree&, const char* name, std::vector<UInt_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<std::vector<Long_t>>   Branch(TTree&, const char* name, std::vector<Long_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<std::vector<ULong_t>>  Branch(TTree&, const char* name, std::vector<ULong_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<std::vector<Float_t>>  Branch(TTree&, const char* name, std::vector<Float_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<std::vector<Double_t>> Branch(TTree&, const char* name, std::vector<Double_t>& obj, Int_t bufsize, Int_t splitlevel);

FCN_TEMPLATE TBranchPtr<ROOT::RVec<Char_t>>   Branch(TTree&, const char* name, ROOT::RVec<Char_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<UChar_t>>  Branch(TTree&, const char* name, ROOT::RVec<UChar_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<Short_t>>  Branch(TTree&, const char* name, ROOT::RVec<Short_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<UShort_t>> Branch(TTree&, const char* name, ROOT::RVec<UShort_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<Int_t>>    Branch(TTree&, const char* name, ROOT::RVec<Int_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<UInt_t>>   Branch(TTree&, const char* name, ROOT::RVec<UInt_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<Long_t>>   Branch(TTree&, const char* name, ROOT::RVec<Long_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ULong_t>>  Branch(TTree&, const char* name, ROOT::RVec<ULong_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<Float_t>>  Branch(TTree&, const char* name, ROOT::RVec<Float_t>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<Double_t>> Branch(TTree&, const char* name, ROOT::RVec<Double_t>& obj, Int_t bufsize, Int_t splitlevel);
//FCN_TEMPLATE TBranchPtr<ROOT::RVec<std::string>> Branch(TTree&, const char* name, ROOT::RVec<std::string>& obj, Int_t bufsize, Int_t splitlevel);

FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<Char_t>>>   Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<Char_t>>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<UChar_t>>>  Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<UChar_t>>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<Short_t>>>  Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<Short_t>>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<UShort_t>>> Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<UShort_t>>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<Int_t>>>    Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<Int_t>>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<UInt_t>>>   Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<UInt_t>>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<Long_t>>>   Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<Long_t>>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<ULong_t>>>  Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<ULong_t>>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<Float_t>>>  Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<Float_t>>& obj, Int_t bufsize, Int_t splitlevel);
FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<Double_t>>> Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<Double_t>>& obj, Int_t bufsize, Int_t splitlevel);
//FCN_TEMPLATE TBranchPtr<ROOT::RVec<ROOT::RVec<std::string>>> Branch(TTree&, const char* name, ROOT::RVec<ROOT::RVec<std::string>>& obj, Int_t bufsize, Int_t splitlevel);

FCN_TEMPLATE void SetAddress(TBranchPtr<Char_t>   obj, Char_t* add);
FCN_TEMPLATE void SetAddress(TBranchPtr<UChar_t>  obj, UChar_t* add);
FCN_TEMPLATE void SetAddress(TBranchPtr<Short_t>  obj, Short_t* add);
FCN_TEMPLATE void SetAddress(TBranchPtr<UShort_t> obj, UShort_t* add);
FCN_TEMPLATE void SetAddress(TBranchPtr<Int_t>    obj, Int_t* add);
FCN_TEMPLATE void SetAddress(TBranchPtr<UInt_t>   obj, UInt_t* add);
FCN_TEMPLATE void SetAddress(TBranchPtr<Long_t>   obj, Long_t* add);
FCN_TEMPLATE void SetAddress(TBranchPtr<ULong_t>  obj, ULong_t* add);
FCN_TEMPLATE void SetAddress(TBranchPtr<Float_t>  obj, Float_t* add);
FCN_TEMPLATE void SetAddress(TBranchPtr<Double_t> obj, Double_t* add);

FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<Char_t>>   obj, std::vector<Char_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<UChar_t>>  obj, std::vector<UChar_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<Short_t>>  obj, std::vector<Short_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<UShort_t>> obj, std::vector<UShort_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<Int_t>>    obj, std::vector<Int_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<UInt_t>>   obj, std::vector<UInt_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<Long_t>>   obj, std::vector<Long_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<ULong_t>>  obj, std::vector<ULong_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<Float_t>>  obj, std::vector<Float_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<std::vector<Double_t>> obj, std::vector<Double_t>& add);

FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<Char_t>>   obj, ROOT::RVec<Char_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<UChar_t>>  obj, ROOT::RVec<UChar_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<Short_t>>  obj, ROOT::RVec<Short_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<UShort_t>> obj, ROOT::RVec<UShort_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<Int_t>>    obj, ROOT::RVec<Int_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<UInt_t>>   obj, ROOT::RVec<UInt_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<Long_t>>   obj, ROOT::RVec<Long_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ULong_t>>  obj, ROOT::RVec<ULong_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<Float_t>>  obj, ROOT::RVec<Float_t>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<Double_t>> obj, ROOT::RVec<Double_t>& add);
//FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<std::string>> obj, ROOT::RVec<std::string>& add);

FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<Char_t>>>   obj, ROOT::RVec<ROOT::RVec<Char_t>>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<UChar_t>>>  obj, ROOT::RVec<ROOT::RVec<UChar_t>>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<Short_t>>>  obj, ROOT::RVec<ROOT::RVec<Short_t>>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<UShort_t>>> obj, ROOT::RVec<ROOT::RVec<UShort_t>>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<Int_t>>>    obj, ROOT::RVec<ROOT::RVec<Int_t>>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<UInt_t>>>   obj, ROOT::RVec<ROOT::RVec<UInt_t>>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<Long_t>>>   obj, ROOT::RVec<ROOT::RVec<Long_t>>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<ULong_t>>>  obj, ROOT::RVec<ROOT::RVec<ULong_t>>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<Float_t>>>  obj, ROOT::RVec<ROOT::RVec<Float_t>>& add);
FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<Double_t>>> obj, ROOT::RVec<ROOT::RVec<Double_t>>& add);
//FCN_TEMPLATE void SetObject(TBranchPtr<ROOT::RVec<ROOT::RVec<std::string>>> obj, ROOT::RVec<ROOT::RVec<std::string>>& add);

FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, Char_t*   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, UChar_t*  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, Short_t*  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, UShort_t* add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, Int_t*    add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, UInt_t*   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, Long_t*   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ULong_t*  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, Float_t*  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, Double_t* add);

FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<Char_t>**   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<UChar_t>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<Short_t>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<UShort_t>** add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<Int_t>**    add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<UInt_t>**   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<Long_t>**   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<ULong_t>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<Float_t>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, std::vector<Double_t>** add);

FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<Char_t>**   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<UChar_t>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<Short_t>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<UShort_t>** add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<Int_t>**    add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<UInt_t>**   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<Long_t>**   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ULong_t>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<Float_t>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<Double_t>** add);
//FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<std::string>** add);

FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<Char_t>>**   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<UChar_t>>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<Short_t>>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<UShort_t>>** add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<Int_t>>**    add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<UInt_t>>**   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<Long_t>>**   add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<ULong_t>>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<Float_t>>**  add);
FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<Double_t>>** add);
//FCN_TEMPLATE Int_t SetBranchAddress(TTree& tree, const char* bname, ROOT::RVec<ROOT::RVec<std::string>>** add);

#endif //TEMPLATES_H not defined
