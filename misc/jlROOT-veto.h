// Following method is defined twice, using respectively Long_t and Long64_t,
// which are the same on a 64 architecture, to name the 3rd argument type.
// Need to veto one of the two
int TSystem::GetPathInfo(const char *, Long_t *, Long64_t *, Long_t *, Long_t *);

// Protected access of TROOT::new prevents TROOT contructor wrapper to work,
TROOT::TROOT(const char *, const char *, VoidFuncPtr_t *);

// Wrapper failes to compile due to the return type, void (*)()
// (complains a conversion method to a Julia type is missing).
Func_t TSystem::DynFindSymbol(const char *, const char *);

// Following methods have a similar ones, where parameters of the callback
// function are declared as const. Only one signature of callback function
// can be wrapped.
TF1::TF1(const char *, Double_t (*)(Double_t *, Double_t *), Double_t, Double_t, Int_t, Int_t, TF1::EAddToList);
TF2::TF2(const char *, Double_t (*)(Double_t *, Double_t *), Double_t, Double_t, Double_t, Double_t, Int_t, Int_t);
TF3::TF3(const char *, Double_t (*)(Double_t *, Double_t *), Double_t, Double_t, Double_t, Double_t, Double_t, Double_t, Int_t, Int_t);

/.*std::[io]stream.*/;

TTreeReader::Iterator_t TTreeReader::Iterator_t::operator++(int);
TTreeReader::Iterator_t & TTreeReader::Iterator_t::operator++();
ROOT::RDataFrame::RDataFrame(std::unique_ptr<ROOT::RDF::RDataSource>, const ROOT::RDataFrame::ColumnNames_t &);
/ROOT::RDataFrame ROOT::Internal::.*/;

TLeaf::GetValueHelper;
// 
//Quad precision float not supported:
/.*LongDouble_t.*/;

/void TROOT::RegisterModule(.*)/;

//Duplicate uses with TBranch * TTree::Branch(const char *, void*, const char *, Int_t, Int_t);
//and the one with 2nd arg as int is giving a warning about duplicate methods.
TBranch * TTree::Branch(const char *, int, const char *, Int_t);
TBranch * TTree::Branch(const char *, Longptr_t, const char *, Int_t);

///.*operator new.*/;
///.*operator delete.*/;
//Version_t TObjArrayIter::Class_Version();
//const char * TObjArrayIter::DeclFileName();
///.*TObject::.*/;

/.*ROOT::Internal::.*/;
///.*ROOT::Experimental::Internal::.*/
/.*ROOT::Experimental::.*/;

std::atomic;

//Causing compilation issue because of pure virtual methods
ROOT::Math::IBaseFunctionMultiDimTempl;

//Causing compilation issue because of lack of WrapIt! support
//for templated mother classes
TMatrixTBase;

//Causing a compilation issue
TVirtualGeoConverter;

////Causing a compilation issue
//TVirtualMutex;

TVirtualFitter::FCNFunc_t TVirtualFitter::GetFCN();

//Issue at linkage. A priori outdated: see macro OLD in hist/hist/src/TFractionFitter.cxx.
void TFractionFitFCN(Int_t &, Double_t *, Double_t &, Double_t *, Int_t);

//Generates a build error
TMatrixTBase;

//Generates a build error
Vc_1::Vector;

//Leads to an error on module import
std::set;

//Prevents the ROOT.jl module precompilation with the error "ERROR: Method overwriting is not permitted during Module precompilation. Use `__precompile__(false)` to opt-out of precompilation". see https://github.com/JuliaInterop/CxxWrap.jl/issues/485
void ROOT::EnableImplicitMT(ROOT::EIMTConfig);

//Allocation operators do not need to be called directly from Julia
void *operator TObject::new(size_t);
void *operator TObject::new[](size_t);
void *operator TObject::new(size_t sz);
void *operator TObject::new[](size_t, void *);
void operator TObject::delete(void *);
void operator TObject::delete[](void *);
void operator TObject::delete(void*, size_t);
void operator TObject::delete[](void*, size_t);
void operator TObject::delete(void *, void *);
void operator TObject::delete[](void *, void *);

//causes an error on accessor creation because it is an c-array,
//and wrapit does not detect it
ExceptionContext_t::fBuf;

//deprecated RooFit methods:
TIterator * RooAbsArg::clientIterator()
TIterator * RooAbsArg::valueClientIterator()
TIterator * RooAbsArg::shapeClientIterator()
TIterator * RooAbsArg::serverIterator()
RooFIter RooAbsArg::valueClientMIterator()
RooFIter RooAbsArg::shapeClientMIterator()
RooFIter RooAbsArg::serverMIterator()

ROOT::TVirtualRWMutex::StateAndRecurseCount::fState!;

//returns a function pointer which is not supported.
ReAllocCharFun_t TBuffer::GetReAllocFunc();

//function pointer. Generated accessor not currently correct
//gThreadTsd;
//gThreadXAR;
//gGXBatch;
//gPtr2VirtualX;

//causes issue with std::char_traits, should have their
//custom wrappers as other std classes like StdVector for std::vector
std::basic_string_view;
std::basic_ofstream;

//Deprecated
TStringLong;

//not relevant for the user:
/.*::ShowMembers(.*).*/;
/.*ROOT::Internal::.*/;
/.*ROOT::Detail::.*/;
/.*RooFit::Detail::.*/;

//causing errors, but not essential for the user
ROOT::TSeq::iterator;

//clang 19 does not recognize TAxis(std::vector<double> const &bins)
//and returns TAxis::TAxis(const int &) that we need to veto
TAxis::TAxis(const int &);
const int & TF1Parameters::ParamsVec();
TF1NormSum::TF1NormSum(const int &, const int &, Double_t);
int TF1NormSum::GetParameters();

//unsuppored std classes
/.*std::pair<.*/;

/.*::Copy(TAtt.* &)/;

//To prevent double registration errors
Int_t TBuffer::ReadStaticArray(UChar_t *);
Int_t TBuffer::ReadStaticArray(ULong_t *);
Int_t TBuffer::ReadStaticArray(Long_t *);
//Int_t TBuffer::ReadStaticArray(ULong64_t *);
void TBuffer::ReadFastArray(UChar_t *, Int_t);
void TBuffer::ReadFastArray(ULong_t *, Int_t);
void TBuffer::ReadFastArray(Long_t *, Int_t);
void TBuffer::WriteArray(const UChar_t *, Int_t);
void TBuffer::WriteArray(const ULong_t *, Int_t);
void TBuffer::WriteArray(const Long_t *, Int_t);
void TBuffer::WriteFastArray(const UChar_t *, Long64_t);
void TBuffer::WriteFastArray(const ULong_t *, Long64_t);
void TBuffer::WriteFastArray(const Long_t *, Long64_t);

//Causes double registration errors
//(with Long_t version? Why?)
TBuffer & ::operator>>(TBuffer &, Bool_t &);
TBuffer & ::operator>>(TBuffer &, Char_t &);
TBuffer & ::operator>>(TBuffer &, UChar_t &)
TBuffer & ::operator>>(TBuffer &, UInt_t &)
TBuffer & ::operator>>(TBuffer &, Short_t &);
TBuffer & ::operator>>(TBuffer &, UShort_t &);
TBuffer & ::operator>>(TBuffer &, Int_t &);
TBuffer & ::operator>>(TBuffer &, ULong_t &);
TBuffer & ::operator>>(TBuffer &, Char_t *);
//TBuffer & ::operator<<(TBuffer &, Char_t);
//TBuffer & ::operator<<(TBuffer &, UChar_t);
//TBuffer & ::operator<<(TBuffer &, Short_t);
//TBuffer & ::operator<<(TBuffer &, UShort_t);
//TBuffer & ::operator<<(TBuffer &, Int_t);
//TBuffer & ::operator<<(TBuffer &, UInt_t)
//TBuffer & ::operator<<(TBuffer &, ULong_t)
TBuffer & ::operator<<(TBuffer &, const Char_t *);

//Duplicates (overwritten error) with version with (U)Long64_t in place of (U)Long_t
//Long_t ::TMath::Abs(Long_t);
//Long64_t ::TMath::Abs(Long64_t); //not clear when this one needs to be vetoed
//Long_t ::TMath::Min(Long_t, Long_t);
//Long_t ::TMath::Max(Long_t, Long_t);
//ULong_t ::TMath::Min(ULong_t, ULong_t);
//ULong_t ::TMath::Max(ULong_t, ULong_t);
ULong_t ::host2net(ULong_t)
Long_t ::host2net(Long_t)
ULong_t ::net2host(ULong_t)
Long_t ::net2host(Long_t)

//deprecated by ROOT
TList::TList(TObject *);
Bool_t TGeoBBox::AreOverlapping(const TGeoBBox *, const TGeoMatrix *, const TGeoBBox *, const TGeoMatrix *);

//void TEnv::SetValue(const char *, const char *, EEnvLevel, const char *)
//void TEnv::SetValue(const char *, EEnvLevel)
//generate a double registration error with `void TEnv::SetValue(const char *, EEnvLevel)`
//void TEnv::SetValue(const char *, Int_t);
//void TEnv::SetValue(const char *, Double_t)

//Causes a Double registration error
UInt_t ::Hash(const TString &);
UInt_t ::Hash(const TString *);

//Causes a overwritten error
TString::TString(Ssiz_t);

//overwritten error 
TString & TString::Remove(TString::EStripType, char);

//duplicates (overwritten error) with methods with Int_t in place of Window_t
void TVirtualX::MoveWindow(Window_t, Int_t, Int_t);
void TVirtualX::SetCursor(Window_t, Cursor_t);

//overwrite void ::frombuf(char *&, UChar_t *) preventing ROOT module
//precompilation
void ::frombuf(char *&, Bool_t *);



