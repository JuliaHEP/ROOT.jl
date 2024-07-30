// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlROOT.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<TTreeFriendLeafIter> : std::false_type { };
  template<> struct DefaultConstructible<TTreeFriendLeafIter> : std::false_type { };
template<> struct SuperType<TTreeFriendLeafIter> { typedef TIterator type; };
}

// Class generating the wrapper for type TTreeFriendLeafIter
// signature to use in the veto file: TTreeFriendLeafIter
struct JlTTreeFriendLeafIter: public Wrapper {

  JlTTreeFriendLeafIter(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TTreeFriendLeafIter (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:670:7
    jlcxx::TypeWrapper<TTreeFriendLeafIter>  t = jlModule.add_type<TTreeFriendLeafIter>("TTreeFriendLeafIter",
      jlcxx::julia_base_type<TIterator>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TTreeFriendLeafIter>>(new jlcxx::TypeWrapper<TTreeFriendLeafIter>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;


    DEBUG_MSG("Adding wrapper for void TTreeFriendLeafIter::TTreeFriendLeafIter(const TTree *, Bool_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:682:4
    t.constructor<const TTree *>(/*finalize=*/true);
    t.constructor<const TTree *, Bool_t>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TTreeFriendLeafIter::TTreeFriendLeafIter(const TTreeFriendLeafIter &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:683:4
    t.constructor<const TTreeFriendLeafIter &>(/*finalize=*/true);

    DEBUG_MSG("Adding wrapper for TIterator & TTreeFriendLeafIter::operator=(const TIterator &) (" __HERE__ ")");
    // signature to use in the veto list: TIterator & TTreeFriendLeafIter::operator=(const TIterator &)
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:685:15
    t.method("assign", static_cast<TIterator & (TTreeFriendLeafIter::*)(const TIterator &) >(&TTreeFriendLeafIter::operator=));

    DEBUG_MSG("Adding wrapper for TTreeFriendLeafIter & TTreeFriendLeafIter::operator=(const TTreeFriendLeafIter &) (" __HERE__ ")");
    // signature to use in the veto list: TTreeFriendLeafIter & TTreeFriendLeafIter::operator=(const TTreeFriendLeafIter &)
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:686:25
    t.method("assign", static_cast<TTreeFriendLeafIter & (TTreeFriendLeafIter::*)(const TTreeFriendLeafIter &) >(&TTreeFriendLeafIter::operator=));

    DEBUG_MSG("Adding wrapper for const TCollection * TTreeFriendLeafIter::GetCollection() (" __HERE__ ")");
    // signature to use in the veto list: const TCollection * TTreeFriendLeafIter::GetCollection()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:688:23
    t.method("GetCollection", static_cast<const TCollection * (TTreeFriendLeafIter::*)()  const>(&TTreeFriendLeafIter::GetCollection));

    DEBUG_MSG("Adding wrapper for Option_t * TTreeFriendLeafIter::GetOption() (" __HERE__ ")");
    // signature to use in the veto list: Option_t * TTreeFriendLeafIter::GetOption()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:689:23
    t.method("GetOption", static_cast<Option_t * (TTreeFriendLeafIter::*)()  const>(&TTreeFriendLeafIter::GetOption));

    DEBUG_MSG("Adding wrapper for TObject * TTreeFriendLeafIter::Next() (" __HERE__ ")");
    // signature to use in the veto list: TObject * TTreeFriendLeafIter::Next()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:690:23
    t.method("Next", static_cast<TObject * (TTreeFriendLeafIter::*)() >(&TTreeFriendLeafIter::Next));

    DEBUG_MSG("Adding wrapper for void TTreeFriendLeafIter::Reset() (" __HERE__ ")");
    // signature to use in the veto list: void TTreeFriendLeafIter::Reset()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:691:23
    t.method("Reset", static_cast<void (TTreeFriendLeafIter::*)() >(&TTreeFriendLeafIter::Reset));
    module_.set_override_module(jl_base_module);

    DEBUG_MSG("Adding wrapper for Bool_t TTreeFriendLeafIter::operator!=(const TIterator &) (" __HERE__ ")");
    // signature to use in the veto list: Bool_t TTreeFriendLeafIter::operator!=(const TIterator &)
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:692:11
    t.method("!=", static_cast<Bool_t (TTreeFriendLeafIter::*)(const TIterator &)  const>(&TTreeFriendLeafIter::operator!=));

    DEBUG_MSG("Adding wrapper for Bool_t TTreeFriendLeafIter::operator!=(const TTreeFriendLeafIter &) (" __HERE__ ")");
    // signature to use in the veto list: Bool_t TTreeFriendLeafIter::operator!=(const TTreeFriendLeafIter &)
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:696:11
    t.method("!=", static_cast<Bool_t (TTreeFriendLeafIter::*)(const TTreeFriendLeafIter &)  const>(&TTreeFriendLeafIter::operator!=));

    DEBUG_MSG("Adding wrapper for TObject * TTreeFriendLeafIter::operator*() (" __HERE__ ")");
    // signature to use in the veto list: TObject * TTreeFriendLeafIter::operator*()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:700:13
    t.method("getindex", static_cast<TObject * (TTreeFriendLeafIter::*)()  const>(&TTreeFriendLeafIter::operator*));

    module_.unset_override_module();

    DEBUG_MSG("Adding wrapper for Version_t TTreeFriendLeafIter::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TTreeFriendLeafIter::Class_Version()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    module_.method("TTreeFriendLeafIter!Class_Version", static_cast<Version_t (*)() >(&TTreeFriendLeafIter::Class_Version));

    DEBUG_MSG("Adding wrapper for TClass * TTreeFriendLeafIter::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TTreeFriendLeafIter::IsA()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    t.method("IsA", static_cast<TClass * (TTreeFriendLeafIter::*)()  const>(&TTreeFriendLeafIter::IsA));

    DEBUG_MSG("Adding wrapper for void TTreeFriendLeafIter::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TTreeFriendLeafIter::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    t.method("StreamerNVirtual", static_cast<void (TTreeFriendLeafIter::*)(TBuffer &) >(&TTreeFriendLeafIter::StreamerNVirtual));

    DEBUG_MSG("Adding wrapper for const char * TTreeFriendLeafIter::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TTreeFriendLeafIter::DeclFileName()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    module_.method("TTreeFriendLeafIter!DeclFileName", []() { return (std::string)TTreeFriendLeafIter::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TTreeFriendLeafIter::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TTreeFriendLeafIter::ImplFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    module_.method("TTreeFriendLeafIter!ImplFileLine", static_cast<int (*)() >(&TTreeFriendLeafIter::ImplFileLine));

    DEBUG_MSG("Adding wrapper for const char * TTreeFriendLeafIter::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TTreeFriendLeafIter::ImplFileName()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    module_.method("TTreeFriendLeafIter!ImplFileName", []() { return (std::string)TTreeFriendLeafIter::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TTreeFriendLeafIter::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TTreeFriendLeafIter::Class_Name()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    module_.method("TTreeFriendLeafIter!Class_Name", []() { return (std::string)TTreeFriendLeafIter::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TTreeFriendLeafIter::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TTreeFriendLeafIter::Dictionary()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    module_.method("TTreeFriendLeafIter!Dictionary", static_cast<TClass * (*)() >(&TTreeFriendLeafIter::Dictionary));

    DEBUG_MSG("Adding wrapper for TClass * TTreeFriendLeafIter::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TTreeFriendLeafIter::Class()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    module_.method("TTreeFriendLeafIter!Class", static_cast<TClass * (*)() >(&TTreeFriendLeafIter::Class));

    DEBUG_MSG("Adding wrapper for void TTreeFriendLeafIter::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TTreeFriendLeafIter::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    t.method("Streamer", static_cast<void (TTreeFriendLeafIter::*)(TBuffer &) >(&TTreeFriendLeafIter::Streamer));

    DEBUG_MSG("Adding wrapper for int TTreeFriendLeafIter::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TTreeFriendLeafIter::DeclFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TTree.h:704:4
    module_.method("TTreeFriendLeafIter!DeclFileLine", static_cast<int (*)() >(&TTreeFriendLeafIter::DeclFileLine));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TTreeFriendLeafIter>> type_;
};
std::shared_ptr<Wrapper> newJlTTreeFriendLeafIter(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTTreeFriendLeafIter(module));
}

namespace jlcxx {

  template<typename T>
  struct BuildParameterList<TBranchPtr<T>>
  {
    typedef ParameterList<T> type;
  };

  template<typename T> struct IsMirroredType<TBranchPtr<T>> : std::false_type { };
  template<typename T> struct DefaultConstructible<TBranchPtr<T>> : std::false_type { };
}

// Class generating the wrapper for type TBranchPtr
// signature to use in the veto file: TBranchPtr
struct JlTBranchPtr: public Wrapper {

  JlTBranchPtr(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TBranchPtr (" __HERE__ ")");
    // defined in src/TBranchPtr.h:13:7
    jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>  t =  jlModule.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("TBranchPtr");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>>(new jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>(jlModule, t));
    auto t93_decl_methods = [this]<typename T> (jlcxx::TypeWrapper<TBranchPtr<T>> wrapped){
      auto module_ = this->module_;
      typedef TBranchPtr<T> WrappedType;


      DEBUG_MSG("Adding wrapper for void TBranchPtr::TBranchPtr<T>(TBranch *) (" __HERE__ ")");
      // defined in src/TBranchPtr.h:17:3
      wrapped.template constructor<TBranch *>(/*finalize=*/true);

      DEBUG_MSG("Adding wrapper for TBranch * TBranchPtr::operator->() (" __HERE__ ")");
      // signature to use in the veto list: TBranch * TBranchPtr::operator->()
      // defined in src/TBranchPtr.h:19:12
      wrapped.method("arrow", static_cast<TBranch * (WrappedType::*)()  const>(&WrappedType::operator->));
      module_.set_override_module(jl_base_module);

      DEBUG_MSG("Adding wrapper for TBranch & TBranchPtr::operator*() (" __HERE__ ")");
      // signature to use in the veto list: TBranch & TBranchPtr::operator*()
      // defined in src/TBranchPtr.h:20:12
      wrapped.method("getindex", static_cast<TBranch & (WrappedType::*)()  const>(&WrappedType::operator*));

      module_.unset_override_module();
    };
    t.apply<TBranchPtr<std::vector<double>>, TBranchPtr<std::vector<float>>, TBranchPtr<std::vector<unsigned long>>, TBranchPtr<std::vector<long>>, TBranchPtr<std::vector<unsigned int>>, TBranchPtr<std::vector<int>>, TBranchPtr<std::vector<unsigned short>>, TBranchPtr<std::vector<short>>, TBranchPtr<std::vector<unsigned char>>, TBranchPtr<std::vector<char>>, TBranchPtr<double>, TBranchPtr<float>, TBranchPtr<unsigned long>, TBranchPtr<long>, TBranchPtr<unsigned int>, TBranchPtr<int>, TBranchPtr<unsigned short>, TBranchPtr<short>, TBranchPtr<unsigned char>, TBranchPtr<char>>(t93_decl_methods);
  }

  void add_methods() const{
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>> type_;
};
std::shared_ptr<Wrapper> newJlTBranchPtr(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTBranchPtr(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TTreeReader> : std::false_type { };
  template<> struct DefaultConstructible<TTreeReader> : std::false_type { };
  template<> struct CopyConstructible<TTreeReader> : std::false_type { };
template<> struct SuperType<TTreeReader> { typedef TObject type; };
}

// Class generating the wrapper for type TTreeReader
// signature to use in the veto file: TTreeReader
struct JlTTreeReader: public Wrapper {

  JlTTreeReader(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TTreeReader (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:44:7
    jlcxx::TypeWrapper<TTreeReader>  t = jlModule.add_type<TTreeReader>("TTreeReader",
      jlcxx::julia_base_type<TObject>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TTreeReader>>(new jlcxx::TypeWrapper<TTreeReader>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TTreeReader::TTreeReader(TTree *, TEntryList *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:165:4
    t.constructor<TTree *>(/*finalize=*/true);
    t.constructor<TTree *, TEntryList *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TTreeReader::TTreeReader(const char *, TDirectory *, TEntryList *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:166:4
    t.constructor<const char *, TDirectory *>(/*finalize=*/true);
    t.constructor<const char *, TDirectory *, TEntryList *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TTreeReader::TTreeReader(const char *, TEntryList *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:167:4
    t.constructor<const char *>(/*finalize=*/true);
    t.constructor<const char *, TEntryList *>(/*finalize=*/true);

    DEBUG_MSG("Adding wrapper for void TTreeReader::SetTree(TTree *, TEntryList *) (" __HERE__ ")");
    // signature to use in the veto list: void TTreeReader::SetTree(TTree *, TEntryList *)
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:171:9
    t.method("SetTree", static_cast<void (TTreeReader::*)(TTree *, TEntryList *) >(&TTreeReader::SetTree));
    t.method("SetTree", [](TTreeReader& a, TTree * arg0)->void { a.SetTree(arg0); });
    t.method("SetTree", [](TTreeReader* a, TTree * arg0)->void { a->SetTree(arg0); });

    DEBUG_MSG("Adding wrapper for void TTreeReader::SetTree(const char *, TEntryList *) (" __HERE__ ")");
    // signature to use in the veto list: void TTreeReader::SetTree(const char *, TEntryList *)
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:172:9
    t.method("SetTree", static_cast<void (TTreeReader::*)(const char *, TEntryList *) >(&TTreeReader::SetTree));
    t.method("SetTree", [](TTreeReader& a, const char * arg0)->void { a.SetTree(arg0); });
    t.method("SetTree", [](TTreeReader* a, const char * arg0)->void { a->SetTree(arg0); });

    DEBUG_MSG("Adding wrapper for void TTreeReader::SetTree(const char *, TDirectory *, TEntryList *) (" __HERE__ ")");
    // signature to use in the veto list: void TTreeReader::SetTree(const char *, TDirectory *, TEntryList *)
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:175:9
    t.method("SetTree", static_cast<void (TTreeReader::*)(const char *, TDirectory *, TEntryList *) >(&TTreeReader::SetTree));
    t.method("SetTree", [](TTreeReader& a, const char * arg0, TDirectory * arg1)->void { a.SetTree(arg0, arg1); });
    t.method("SetTree", [](TTreeReader* a, const char * arg0, TDirectory * arg1)->void { a->SetTree(arg0, arg1); });

    DEBUG_MSG("Adding wrapper for Bool_t TTreeReader::IsChain() (" __HERE__ ")");
    // signature to use in the veto list: Bool_t TTreeReader::IsChain()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:177:11
    t.method("IsChain", static_cast<Bool_t (TTreeReader::*)()  const>(&TTreeReader::IsChain));

    DEBUG_MSG("Adding wrapper for Bool_t TTreeReader::IsInvalid() (" __HERE__ ")");
    // signature to use in the veto list: Bool_t TTreeReader::IsInvalid()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:179:11
    t.method("IsInvalid", static_cast<Bool_t (TTreeReader::*)()  const>(&TTreeReader::IsInvalid));

    DEBUG_MSG("Adding wrapper for TTree * TTreeReader::GetTree() (" __HERE__ ")");
    // signature to use in the veto list: TTree * TTreeReader::GetTree()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:181:11
    t.method("GetTree", static_cast<TTree * (TTreeReader::*)()  const>(&TTreeReader::GetTree));

    DEBUG_MSG("Adding wrapper for TEntryList * TTreeReader::GetEntryList() (" __HERE__ ")");
    // signature to use in the veto list: TEntryList * TTreeReader::GetEntryList()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:182:16
    t.method("GetEntryList", static_cast<TEntryList * (TTreeReader::*)()  const>(&TTreeReader::GetEntryList));

    DEBUG_MSG("Adding wrapper for Bool_t TTreeReader::Next() (" __HERE__ ")");
    // signature to use in the veto list: Bool_t TTreeReader::Next()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:190:11
    t.method("Next", static_cast<Bool_t (TTreeReader::*)() >(&TTreeReader::Next));

    DEBUG_MSG("Adding wrapper for TTreeReader::EEntryStatus TTreeReader::SetEntry(Long64_t) (" __HERE__ ")");
    // signature to use in the veto list: TTreeReader::EEntryStatus TTreeReader::SetEntry(Long64_t)
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:199:17
    t.method("SetEntry", static_cast<TTreeReader::EEntryStatus (TTreeReader::*)(Long64_t) >(&TTreeReader::SetEntry));

    DEBUG_MSG("Adding wrapper for TTreeReader::EEntryStatus TTreeReader::SetLocalEntry(Long64_t) (" __HERE__ ")");
    // signature to use in the veto list: TTreeReader::EEntryStatus TTreeReader::SetLocalEntry(Long64_t)
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:209:17
    t.method("SetLocalEntry", static_cast<TTreeReader::EEntryStatus (TTreeReader::*)(Long64_t) >(&TTreeReader::SetLocalEntry));

    DEBUG_MSG("Adding wrapper for TTreeReader::EEntryStatus TTreeReader::SetEntriesRange(Long64_t, Long64_t) (" __HERE__ ")");
    // signature to use in the veto list: TTreeReader::EEntryStatus TTreeReader::SetEntriesRange(Long64_t, Long64_t)
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:211:17
    t.method("SetEntriesRange", static_cast<TTreeReader::EEntryStatus (TTreeReader::*)(Long64_t, Long64_t) >(&TTreeReader::SetEntriesRange));

    DEBUG_MSG("Adding wrapper for void TTreeReader::Restart() (" __HERE__ ")");
    // signature to use in the veto list: void TTreeReader::Restart()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:219:9
    t.method("Restart", static_cast<void (TTreeReader::*)() >(&TTreeReader::Restart));

    DEBUG_MSG("Adding wrapper for TTreeReader::EEntryStatus TTreeReader::GetEntryStatus() (" __HERE__ ")");
    // signature to use in the veto list: TTreeReader::EEntryStatus TTreeReader::GetEntryStatus()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:223:17
    t.method("GetEntryStatus", static_cast<TTreeReader::EEntryStatus (TTreeReader::*)()  const>(&TTreeReader::GetEntryStatus));

    DEBUG_MSG("Adding wrapper for Long64_t TTreeReader::GetEntries() (" __HERE__ ")");
    // signature to use in the veto list: Long64_t TTreeReader::GetEntries()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:225:13
    t.method("GetEntries", static_cast<Long64_t (TTreeReader::*)()  const>(&TTreeReader::GetEntries));

    DEBUG_MSG("Adding wrapper for Long64_t TTreeReader::GetEntries(Bool_t) (" __HERE__ ")");
    // signature to use in the veto list: Long64_t TTreeReader::GetEntries(Bool_t)
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:226:13
    t.method("GetEntries", static_cast<Long64_t (TTreeReader::*)(Bool_t) >(&TTreeReader::GetEntries));

    DEBUG_MSG("Adding wrapper for Long64_t TTreeReader::GetCurrentEntry() (" __HERE__ ")");
    // signature to use in the veto list: Long64_t TTreeReader::GetCurrentEntry()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:235:13
    t.method("GetCurrentEntry", static_cast<Long64_t (TTreeReader::*)()  const>(&TTreeReader::GetCurrentEntry));

    DEBUG_MSG("Adding wrapper for Bool_t TTreeReader::Notify() (" __HERE__ ")");
    // signature to use in the veto list: Bool_t TTreeReader::Notify()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:237:11
    t.method("Notify", static_cast<Bool_t (TTreeReader::*)() >(&TTreeReader::Notify));

    DEBUG_MSG("Adding wrapper for TTreeReader::Iterator_t TTreeReader::begin() (" __HERE__ ")");
    // signature to use in the veto list: TTreeReader::Iterator_t TTreeReader::begin()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:240:15
    t.method("begin", static_cast<TTreeReader::Iterator_t (TTreeReader::*)() >(&TTreeReader::begin));

    DEBUG_MSG("Adding wrapper for TTreeReader::Iterator_t TTreeReader::end() (" __HERE__ ")");
    // signature to use in the veto list: TTreeReader::Iterator_t TTreeReader::end()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:244:15
    t.method("end", static_cast<TTreeReader::Iterator_t (TTreeReader::*)()  const>(&TTreeReader::end));

    DEBUG_MSG("Adding wrapper for Version_t TTreeReader::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TTreeReader::Class_Version()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    module_.method("TTreeReader!Class_Version", static_cast<Version_t (*)() >(&TTreeReader::Class_Version));

    DEBUG_MSG("Adding wrapper for TClass * TTreeReader::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TTreeReader::IsA()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    t.method("IsA", static_cast<TClass * (TTreeReader::*)()  const>(&TTreeReader::IsA));

    DEBUG_MSG("Adding wrapper for void TTreeReader::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TTreeReader::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    t.method("StreamerNVirtual", static_cast<void (TTreeReader::*)(TBuffer &) >(&TTreeReader::StreamerNVirtual));

    DEBUG_MSG("Adding wrapper for const char * TTreeReader::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TTreeReader::DeclFileName()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    module_.method("TTreeReader!DeclFileName", []() { return (std::string)TTreeReader::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TTreeReader::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TTreeReader::ImplFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    module_.method("TTreeReader!ImplFileLine", static_cast<int (*)() >(&TTreeReader::ImplFileLine));

    DEBUG_MSG("Adding wrapper for const char * TTreeReader::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TTreeReader::ImplFileName()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    module_.method("TTreeReader!ImplFileName", []() { return (std::string)TTreeReader::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TTreeReader::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TTreeReader::Class_Name()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    module_.method("TTreeReader!Class_Name", []() { return (std::string)TTreeReader::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TTreeReader::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TTreeReader::Dictionary()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    module_.method("TTreeReader!Dictionary", static_cast<TClass * (*)() >(&TTreeReader::Dictionary));

    DEBUG_MSG("Adding wrapper for TClass * TTreeReader::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TTreeReader::Class()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    module_.method("TTreeReader!Class", static_cast<TClass * (*)() >(&TTreeReader::Class));

    DEBUG_MSG("Adding wrapper for void TTreeReader::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TTreeReader::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    t.method("Streamer", static_cast<void (TTreeReader::*)(TBuffer &) >(&TTreeReader::Streamer));

    DEBUG_MSG("Adding wrapper for int TTreeReader::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TTreeReader::DeclFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TTreeReader.h:314:4
    module_.method("TTreeReader!DeclFileLine", static_cast<int (*)() >(&TTreeReader::DeclFileLine));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TTreeReader>> type_;
};
std::shared_ptr<Wrapper> newJlTTreeReader(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTTreeReader(module));
}

namespace jlcxx {

  template<typename T>
  struct BuildParameterList<TTreeReaderValue<T>>
  {
    typedef ParameterList<T> type;
  };

  template<typename T> struct IsMirroredType<TTreeReaderValue<T>> : std::false_type { };
  template<typename T> struct DefaultConstructible<TTreeReaderValue<T>> : std::false_type { };
}

// Class generating the wrapper for type TTreeReaderValue
// signature to use in the veto file: TTreeReaderValue
struct JlTTreeReaderValue: public Wrapper {

  JlTTreeReaderValue(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TTreeReaderValue (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TTreeReaderValue.h:146:30
    jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>  t =  jlModule.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("TTreeReaderValue");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>>(new jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>(jlModule, t));
    auto t100_decl_methods = [this]<typename T> (jlcxx::TypeWrapper<TTreeReaderValue<T>> wrapped){
      auto module_ = this->module_;
      typedef TTreeReaderValue<T> WrappedType;


      DEBUG_MSG("Adding wrapper for void TTreeReaderValue::TTreeReaderValue<T>(TTreeReader &, const char *) (" __HERE__ ")");
      // defined in /home/pgras/.julia/conda/3/include/TTreeReaderValue.h:152:4
      wrapped.template constructor<TTreeReader &, const char *>(/*finalize=*/true);

      DEBUG_MSG("Adding wrapper for T * TTreeReaderValue::Get() (" __HERE__ ")");
      // signature to use in the veto list: T * TTreeReaderValue::Get()
      // defined in /home/pgras/.julia/conda/3/include/TTreeReaderValue.h:161:7
      wrapped.method("Get", static_cast<T * (WrappedType::*)() >(&WrappedType::Get));

      DEBUG_MSG("Adding wrapper for T * TTreeReaderValue::operator->() (" __HERE__ ")");
      // signature to use in the veto list: T * TTreeReaderValue::operator->()
      // defined in /home/pgras/.julia/conda/3/include/TTreeReaderValue.h:174:7
      wrapped.method("arrow", static_cast<T * (WrappedType::*)() >(&WrappedType::operator->));
      module_.set_override_module(jl_base_module);

      DEBUG_MSG("Adding wrapper for T & TTreeReaderValue::operator*() (" __HERE__ ")");
      // signature to use in the veto list: T & TTreeReaderValue::operator*()
      // defined in /home/pgras/.julia/conda/3/include/TTreeReaderValue.h:179:7
      wrapped.method("getindex", static_cast<T & (WrappedType::*)() >(&WrappedType::operator*));

      module_.unset_override_module();
    };
    t.apply<TTreeReaderValue<double>, TTreeReaderValue<float>, TTreeReaderValue<unsigned long>, TTreeReaderValue<long>, TTreeReaderValue<unsigned int>, TTreeReaderValue<int>, TTreeReaderValue<unsigned short>, TTreeReaderValue<short>, TTreeReaderValue<unsigned char>, TTreeReaderValue<char>>(t100_decl_methods);
  }

  void add_methods() const{
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>> type_;
};
std::shared_ptr<Wrapper> newJlTTreeReaderValue(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTTreeReaderValue(module));
}
