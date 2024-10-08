// this file was auto-generated by wrapit v1.4.0
#include "Wrapper.h"

#include "jlROOT.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {
  template<> struct IsMirroredType<TH1S> : std::false_type { };
  template<> struct DefaultConstructible<TH1S> : std::false_type { };
template<> struct SuperType<TH1S> { typedef TH1 type; };
}

// Class generating the wrapper for type TH1S
// signature to use in the veto file: TH1S
struct JlTH1S: public Wrapper {

  JlTH1S(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TH1S (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:498:7
    jlcxx::TypeWrapper<TH1S>  t = jlModule.add_type<TH1S>("TH1S",
      jlcxx::julia_base_type<TH1>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TH1S>>(new jlcxx::TypeWrapper<TH1S>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1S::TH1S(const char *, const char *, Int_t, Double_t, Double_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:502:4
    t.constructor<const char *, const char *, Int_t, Double_t, Double_t>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1S::TH1S(const char *, const char *, Int_t, const Float_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:503:4
    t.constructor<const char *, const char *, Int_t, const Float_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1S::TH1S(const char *, const char *, Int_t, const Double_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:504:4
    t.constructor<const char *, const char *, Int_t, const Double_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1S::TH1S(const TH1S &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:505:4
    t.constructor<const TH1S &>(/*finalize=*/true);

    DEBUG_MSG("Adding wrapper for TH1S & TH1S::operator=(const TH1S &) (" __HERE__ ")");
    // signature to use in the veto list: TH1S & TH1S::operator=(const TH1S &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:506:10
    t.method("assign", static_cast<TH1S & (TH1S::*)(const TH1S &) >(&TH1S::operator=));

    DEBUG_MSG("Adding wrapper for void TH1S::AddBinContent(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1S::AddBinContent(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:509:13
    t.method("AddBinContent", static_cast<void (TH1S::*)(Int_t) >(&TH1S::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1S::AddBinContent(Int_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1S::AddBinContent(Int_t, Double_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:510:13
    t.method("AddBinContent", static_cast<void (TH1S::*)(Int_t, Double_t) >(&TH1S::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1S::Copy(TObject &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1S::Copy(TObject &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:511:13
    t.method("Copy", static_cast<void (TH1S::*)(TObject &)  const>(&TH1S::Copy));

    DEBUG_MSG("Adding wrapper for void TH1S::Reset(Option_t *) (" __HERE__ ")");
    // signature to use in the veto list: void TH1S::Reset(Option_t *)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:512:13
    t.method("Reset", static_cast<void (TH1S::*)(Option_t *) >(&TH1S::Reset));
    t.method("Reset", [](TH1S& a)->void { a.Reset(); });
    t.method("Reset", [](TH1S* a)->void { a->Reset(); });

    DEBUG_MSG("Adding wrapper for void TH1S::SetBinsLength(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1S::SetBinsLength(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:513:13
    t.method("SetBinsLength", static_cast<void (TH1S::*)(Int_t) >(&TH1S::SetBinsLength));
    t.method("SetBinsLength", [](TH1S& a)->void { a.SetBinsLength(); });
    t.method("SetBinsLength", [](TH1S* a)->void { a->SetBinsLength(); });

    DEBUG_MSG("Adding wrapper for Version_t TH1S::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TH1S::Class_Version()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    module_.method("TH1S!Class_Version", static_cast<Version_t (*)() >(&TH1S::Class_Version));

    DEBUG_MSG("Adding wrapper for TClass * TH1S::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1S::IsA()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    t.method("IsA", static_cast<TClass * (TH1S::*)()  const>(&TH1S::IsA));

    DEBUG_MSG("Adding wrapper for void TH1S::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1S::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    t.method("StreamerNVirtual", static_cast<void (TH1S::*)(TBuffer &) >(&TH1S::StreamerNVirtual));

    DEBUG_MSG("Adding wrapper for const char * TH1S::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1S::DeclFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    module_.method("TH1S!DeclFileName", []() { return (std::string)TH1S::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TH1S::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1S::ImplFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    module_.method("TH1S!ImplFileLine", static_cast<int (*)() >(&TH1S::ImplFileLine));

    DEBUG_MSG("Adding wrapper for const char * TH1S::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1S::ImplFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    module_.method("TH1S!ImplFileName", []() { return (std::string)TH1S::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TH1S::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1S::Class_Name()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    module_.method("TH1S!Class_Name", []() { return (std::string)TH1S::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TH1S::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1S::Dictionary()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    module_.method("TH1S!Dictionary", static_cast<TClass * (*)() >(&TH1S::Dictionary));

    DEBUG_MSG("Adding wrapper for TClass * TH1S::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1S::Class()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    module_.method("TH1S!Class", static_cast<TClass * (*)() >(&TH1S::Class));

    DEBUG_MSG("Adding wrapper for void TH1S::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1S::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    t.method("Streamer", static_cast<void (TH1S::*)(TBuffer &) >(&TH1S::Streamer));

    DEBUG_MSG("Adding wrapper for int TH1S::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1S::DeclFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:515:4
    module_.method("TH1S!DeclFileLine", static_cast<int (*)() >(&TH1S::DeclFileLine));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TH1S>> type_;
};
std::shared_ptr<Wrapper> newJlTH1S(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTH1S(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TH1I> : std::false_type { };
  template<> struct DefaultConstructible<TH1I> : std::false_type { };
template<> struct SuperType<TH1I> { typedef TH1 type; };
}

// Class generating the wrapper for type TH1I
// signature to use in the veto file: TH1I
struct JlTH1I: public Wrapper {

  JlTH1I(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TH1I (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:539:7
    jlcxx::TypeWrapper<TH1I>  t = jlModule.add_type<TH1I>("TH1I",
      jlcxx::julia_base_type<TH1>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TH1I>>(new jlcxx::TypeWrapper<TH1I>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1I::TH1I(const char *, const char *, Int_t, Double_t, Double_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:543:4
    t.constructor<const char *, const char *, Int_t, Double_t, Double_t>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1I::TH1I(const char *, const char *, Int_t, const Float_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:544:4
    t.constructor<const char *, const char *, Int_t, const Float_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1I::TH1I(const char *, const char *, Int_t, const Double_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:545:4
    t.constructor<const char *, const char *, Int_t, const Double_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1I::TH1I(const TH1I &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:546:4
    t.constructor<const TH1I &>(/*finalize=*/true);

    DEBUG_MSG("Adding wrapper for TH1I & TH1I::operator=(const TH1I &) (" __HERE__ ")");
    // signature to use in the veto list: TH1I & TH1I::operator=(const TH1I &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:547:10
    t.method("assign", static_cast<TH1I & (TH1I::*)(const TH1I &) >(&TH1I::operator=));

    DEBUG_MSG("Adding wrapper for void TH1I::AddBinContent(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1I::AddBinContent(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:550:13
    t.method("AddBinContent", static_cast<void (TH1I::*)(Int_t) >(&TH1I::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1I::AddBinContent(Int_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1I::AddBinContent(Int_t, Double_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:551:13
    t.method("AddBinContent", static_cast<void (TH1I::*)(Int_t, Double_t) >(&TH1I::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1I::Copy(TObject &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1I::Copy(TObject &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:552:13
    t.method("Copy", static_cast<void (TH1I::*)(TObject &)  const>(&TH1I::Copy));

    DEBUG_MSG("Adding wrapper for void TH1I::Reset(Option_t *) (" __HERE__ ")");
    // signature to use in the veto list: void TH1I::Reset(Option_t *)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:553:13
    t.method("Reset", static_cast<void (TH1I::*)(Option_t *) >(&TH1I::Reset));
    t.method("Reset", [](TH1I& a)->void { a.Reset(); });
    t.method("Reset", [](TH1I* a)->void { a->Reset(); });

    DEBUG_MSG("Adding wrapper for void TH1I::SetBinsLength(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1I::SetBinsLength(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:554:13
    t.method("SetBinsLength", static_cast<void (TH1I::*)(Int_t) >(&TH1I::SetBinsLength));
    t.method("SetBinsLength", [](TH1I& a)->void { a.SetBinsLength(); });
    t.method("SetBinsLength", [](TH1I* a)->void { a->SetBinsLength(); });

    DEBUG_MSG("Adding wrapper for Version_t TH1I::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TH1I::Class_Version()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    module_.method("TH1I!Class_Version", static_cast<Version_t (*)() >(&TH1I::Class_Version));

    DEBUG_MSG("Adding wrapper for TClass * TH1I::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1I::IsA()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    t.method("IsA", static_cast<TClass * (TH1I::*)()  const>(&TH1I::IsA));

    DEBUG_MSG("Adding wrapper for void TH1I::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1I::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    t.method("StreamerNVirtual", static_cast<void (TH1I::*)(TBuffer &) >(&TH1I::StreamerNVirtual));

    DEBUG_MSG("Adding wrapper for const char * TH1I::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1I::DeclFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    module_.method("TH1I!DeclFileName", []() { return (std::string)TH1I::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TH1I::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1I::ImplFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    module_.method("TH1I!ImplFileLine", static_cast<int (*)() >(&TH1I::ImplFileLine));

    DEBUG_MSG("Adding wrapper for const char * TH1I::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1I::ImplFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    module_.method("TH1I!ImplFileName", []() { return (std::string)TH1I::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TH1I::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1I::Class_Name()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    module_.method("TH1I!Class_Name", []() { return (std::string)TH1I::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TH1I::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1I::Dictionary()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    module_.method("TH1I!Dictionary", static_cast<TClass * (*)() >(&TH1I::Dictionary));

    DEBUG_MSG("Adding wrapper for TClass * TH1I::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1I::Class()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    module_.method("TH1I!Class", static_cast<TClass * (*)() >(&TH1I::Class));

    DEBUG_MSG("Adding wrapper for void TH1I::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1I::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    t.method("Streamer", static_cast<void (TH1I::*)(TBuffer &) >(&TH1I::Streamer));

    DEBUG_MSG("Adding wrapper for int TH1I::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1I::DeclFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:556:4
    module_.method("TH1I!DeclFileLine", static_cast<int (*)() >(&TH1I::DeclFileLine));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TH1I>> type_;
};
std::shared_ptr<Wrapper> newJlTH1I(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTH1I(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TH1L> : std::false_type { };
  template<> struct DefaultConstructible<TH1L> : std::false_type { };
template<> struct SuperType<TH1L> { typedef TH1 type; };
}

// Class generating the wrapper for type TH1L
// signature to use in the veto file: TH1L
struct JlTH1L: public Wrapper {

  JlTH1L(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TH1L (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:580:7
    jlcxx::TypeWrapper<TH1L>  t = jlModule.add_type<TH1L>("TH1L",
      jlcxx::julia_base_type<TH1>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TH1L>>(new jlcxx::TypeWrapper<TH1L>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1L::TH1L(const char *, const char *, Int_t, Double_t, Double_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:584:4
    t.constructor<const char *, const char *, Int_t, Double_t, Double_t>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1L::TH1L(const char *, const char *, Int_t, const Float_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:585:4
    t.constructor<const char *, const char *, Int_t, const Float_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1L::TH1L(const char *, const char *, Int_t, const Double_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:586:4
    t.constructor<const char *, const char *, Int_t, const Double_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1L::TH1L(const TH1L &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:587:4
    t.constructor<const TH1L &>(/*finalize=*/true);

    DEBUG_MSG("Adding wrapper for TH1L & TH1L::operator=(const TH1L &) (" __HERE__ ")");
    // signature to use in the veto list: TH1L & TH1L::operator=(const TH1L &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:588:10
    t.method("assign", static_cast<TH1L & (TH1L::*)(const TH1L &) >(&TH1L::operator=));

    DEBUG_MSG("Adding wrapper for void TH1L::AddBinContent(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1L::AddBinContent(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:591:13
    t.method("AddBinContent", static_cast<void (TH1L::*)(Int_t) >(&TH1L::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1L::AddBinContent(Int_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1L::AddBinContent(Int_t, Double_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:592:13
    t.method("AddBinContent", static_cast<void (TH1L::*)(Int_t, Double_t) >(&TH1L::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1L::Copy(TObject &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1L::Copy(TObject &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:593:13
    t.method("Copy", static_cast<void (TH1L::*)(TObject &)  const>(&TH1L::Copy));

    DEBUG_MSG("Adding wrapper for void TH1L::Reset(Option_t *) (" __HERE__ ")");
    // signature to use in the veto list: void TH1L::Reset(Option_t *)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:594:13
    t.method("Reset", static_cast<void (TH1L::*)(Option_t *) >(&TH1L::Reset));
    t.method("Reset", [](TH1L& a)->void { a.Reset(); });
    t.method("Reset", [](TH1L* a)->void { a->Reset(); });

    DEBUG_MSG("Adding wrapper for void TH1L::SetBinsLength(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1L::SetBinsLength(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:595:13
    t.method("SetBinsLength", static_cast<void (TH1L::*)(Int_t) >(&TH1L::SetBinsLength));
    t.method("SetBinsLength", [](TH1L& a)->void { a.SetBinsLength(); });
    t.method("SetBinsLength", [](TH1L* a)->void { a->SetBinsLength(); });

    DEBUG_MSG("Adding wrapper for Version_t TH1L::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TH1L::Class_Version()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    module_.method("TH1L!Class_Version", static_cast<Version_t (*)() >(&TH1L::Class_Version));

    DEBUG_MSG("Adding wrapper for TClass * TH1L::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1L::IsA()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    t.method("IsA", static_cast<TClass * (TH1L::*)()  const>(&TH1L::IsA));

    DEBUG_MSG("Adding wrapper for void TH1L::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1L::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    t.method("StreamerNVirtual", static_cast<void (TH1L::*)(TBuffer &) >(&TH1L::StreamerNVirtual));

    DEBUG_MSG("Adding wrapper for const char * TH1L::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1L::DeclFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    module_.method("TH1L!DeclFileName", []() { return (std::string)TH1L::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TH1L::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1L::ImplFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    module_.method("TH1L!ImplFileLine", static_cast<int (*)() >(&TH1L::ImplFileLine));

    DEBUG_MSG("Adding wrapper for const char * TH1L::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1L::ImplFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    module_.method("TH1L!ImplFileName", []() { return (std::string)TH1L::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TH1L::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1L::Class_Name()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    module_.method("TH1L!Class_Name", []() { return (std::string)TH1L::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TH1L::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1L::Dictionary()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    module_.method("TH1L!Dictionary", static_cast<TClass * (*)() >(&TH1L::Dictionary));

    DEBUG_MSG("Adding wrapper for TClass * TH1L::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1L::Class()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    module_.method("TH1L!Class", static_cast<TClass * (*)() >(&TH1L::Class));

    DEBUG_MSG("Adding wrapper for void TH1L::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1L::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    t.method("Streamer", static_cast<void (TH1L::*)(TBuffer &) >(&TH1L::Streamer));

    DEBUG_MSG("Adding wrapper for int TH1L::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1L::DeclFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:597:4
    module_.method("TH1L!DeclFileLine", static_cast<int (*)() >(&TH1L::DeclFileLine));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TH1L>> type_;
};
std::shared_ptr<Wrapper> newJlTH1L(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTH1L(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TH1F> : std::false_type { };
  template<> struct DefaultConstructible<TH1F> : std::false_type { };
template<> struct SuperType<TH1F> { typedef TH1 type; };
}

// Class generating the wrapper for type TH1F
// signature to use in the veto file: TH1F
struct JlTH1F: public Wrapper {

  JlTH1F(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TH1F (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:621:7
    jlcxx::TypeWrapper<TH1F>  t = jlModule.add_type<TH1F>("TH1F",
      jlcxx::julia_base_type<TH1>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TH1F>>(new jlcxx::TypeWrapper<TH1F>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1F::TH1F(const char *, const char *, Int_t, Double_t, Double_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:625:4
    t.constructor<const char *, const char *, Int_t, Double_t, Double_t>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1F::TH1F(const char *, const char *, Int_t, const Float_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:626:4
    t.constructor<const char *, const char *, Int_t, const Float_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1F::TH1F(const char *, const char *, Int_t, const Double_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:627:4
    t.constructor<const char *, const char *, Int_t, const Double_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1F::TH1F(const TH1F &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:629:4
    t.constructor<const TH1F &>(/*finalize=*/true);

    DEBUG_MSG("Adding wrapper for TH1F & TH1F::operator=(const TH1F &) (" __HERE__ ")");
    // signature to use in the veto list: TH1F & TH1F::operator=(const TH1F &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:630:10
    t.method("assign", static_cast<TH1F & (TH1F::*)(const TH1F &) >(&TH1F::operator=));

    DEBUG_MSG("Adding wrapper for void TH1F::AddBinContent(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::AddBinContent(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:635:13
    t.method("AddBinContent", static_cast<void (TH1F::*)(Int_t) >(&TH1F::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1F::AddBinContent(Int_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::AddBinContent(Int_t, Double_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:13
    t.method("AddBinContent", static_cast<void (TH1F::*)(Int_t, Double_t) >(&TH1F::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1F::Copy(TObject &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::Copy(TObject &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:641:13
    t.method("Copy", static_cast<void (TH1F::*)(TObject &)  const>(&TH1F::Copy));

    DEBUG_MSG("Adding wrapper for void TH1F::Reset(Option_t *) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::Reset(Option_t *)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:642:13
    t.method("Reset", static_cast<void (TH1F::*)(Option_t *) >(&TH1F::Reset));
    t.method("Reset", [](TH1F& a)->void { a.Reset(); });
    t.method("Reset", [](TH1F* a)->void { a->Reset(); });

    DEBUG_MSG("Adding wrapper for void TH1F::SetBinsLength(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::SetBinsLength(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:643:13
    t.method("SetBinsLength", static_cast<void (TH1F::*)(Int_t) >(&TH1F::SetBinsLength));
    t.method("SetBinsLength", [](TH1F& a)->void { a.SetBinsLength(); });
    t.method("SetBinsLength", [](TH1F* a)->void { a->SetBinsLength(); });

    DEBUG_MSG("Adding wrapper for Version_t TH1F::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TH1F::Class_Version()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    module_.method("TH1F!Class_Version", static_cast<Version_t (*)() >(&TH1F::Class_Version));

    DEBUG_MSG("Adding wrapper for TClass * TH1F::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1F::IsA()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    t.method("IsA", static_cast<TClass * (TH1F::*)()  const>(&TH1F::IsA));

    DEBUG_MSG("Adding wrapper for void TH1F::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    t.method("StreamerNVirtual", static_cast<void (TH1F::*)(TBuffer &) >(&TH1F::StreamerNVirtual));

    DEBUG_MSG("Adding wrapper for const char * TH1F::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1F::DeclFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    module_.method("TH1F!DeclFileName", []() { return (std::string)TH1F::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TH1F::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1F::ImplFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    module_.method("TH1F!ImplFileLine", static_cast<int (*)() >(&TH1F::ImplFileLine));

    DEBUG_MSG("Adding wrapper for const char * TH1F::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1F::ImplFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    module_.method("TH1F!ImplFileName", []() { return (std::string)TH1F::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TH1F::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1F::Class_Name()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    module_.method("TH1F!Class_Name", []() { return (std::string)TH1F::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TH1F::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1F::Dictionary()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    module_.method("TH1F!Dictionary", static_cast<TClass * (*)() >(&TH1F::Dictionary));

    DEBUG_MSG("Adding wrapper for TClass * TH1F::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1F::Class()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    module_.method("TH1F!Class", static_cast<TClass * (*)() >(&TH1F::Class));

    DEBUG_MSG("Adding wrapper for void TH1F::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    t.method("Streamer", static_cast<void (TH1F::*)(TBuffer &) >(&TH1F::Streamer));

    DEBUG_MSG("Adding wrapper for int TH1F::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1F::DeclFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:645:4
    module_.method("TH1F!DeclFileLine", static_cast<int (*)() >(&TH1F::DeclFileLine));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TH1F>> type_;
};
std::shared_ptr<Wrapper> newJlTH1F(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTH1F(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TH1D> : std::false_type { };
  template<> struct DefaultConstructible<TH1D> : std::false_type { };
template<> struct SuperType<TH1D> { typedef TH1 type; };
}

// Class generating the wrapper for type TH1D
// signature to use in the veto file: TH1D
struct JlTH1D: public Wrapper {

  JlTH1D(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TH1D (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:669:7
    jlcxx::TypeWrapper<TH1D>  t = jlModule.add_type<TH1D>("TH1D",
      jlcxx::julia_base_type<TH1>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TH1D>>(new jlcxx::TypeWrapper<TH1D>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const char *, const char *, Int_t, Double_t, Double_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:673:4
    t.constructor<const char *, const char *, Int_t, Double_t, Double_t>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const char *, const char *, Int_t, const Float_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:674:4
    t.constructor<const char *, const char *, Int_t, const Float_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const char *, const char *, Int_t, const Double_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:675:4
    t.constructor<const char *, const char *, Int_t, const Double_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const TVectorD &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:676:13
    t.constructor<const TVectorD &>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const TH1D &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:677:4
    t.constructor<const TH1D &>(/*finalize=*/true);

    DEBUG_MSG("Adding wrapper for TH1D & TH1D::operator=(const TH1D &) (" __HERE__ ")");
    // signature to use in the veto list: TH1D & TH1D::operator=(const TH1D &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:678:10
    t.method("assign", static_cast<TH1D & (TH1D::*)(const TH1D &) >(&TH1D::operator=));

    DEBUG_MSG("Adding wrapper for void TH1D::AddBinContent(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::AddBinContent(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:683:13
    t.method("AddBinContent", static_cast<void (TH1D::*)(Int_t) >(&TH1D::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1D::AddBinContent(Int_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::AddBinContent(Int_t, Double_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:686:13
    t.method("AddBinContent", static_cast<void (TH1D::*)(Int_t, Double_t) >(&TH1D::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1D::Copy(TObject &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::Copy(TObject &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:688:13
    t.method("Copy", static_cast<void (TH1D::*)(TObject &)  const>(&TH1D::Copy));

    DEBUG_MSG("Adding wrapper for void TH1D::Reset(Option_t *) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::Reset(Option_t *)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:689:13
    t.method("Reset", static_cast<void (TH1D::*)(Option_t *) >(&TH1D::Reset));
    t.method("Reset", [](TH1D& a)->void { a.Reset(); });
    t.method("Reset", [](TH1D* a)->void { a->Reset(); });

    DEBUG_MSG("Adding wrapper for void TH1D::SetBinsLength(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::SetBinsLength(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:690:13
    t.method("SetBinsLength", static_cast<void (TH1D::*)(Int_t) >(&TH1D::SetBinsLength));
    t.method("SetBinsLength", [](TH1D& a)->void { a.SetBinsLength(); });
    t.method("SetBinsLength", [](TH1D* a)->void { a->SetBinsLength(); });

    DEBUG_MSG("Adding wrapper for Version_t TH1D::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TH1D::Class_Version()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    module_.method("TH1D!Class_Version", static_cast<Version_t (*)() >(&TH1D::Class_Version));

    DEBUG_MSG("Adding wrapper for TClass * TH1D::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1D::IsA()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    t.method("IsA", static_cast<TClass * (TH1D::*)()  const>(&TH1D::IsA));

    DEBUG_MSG("Adding wrapper for void TH1D::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    t.method("StreamerNVirtual", static_cast<void (TH1D::*)(TBuffer &) >(&TH1D::StreamerNVirtual));

    DEBUG_MSG("Adding wrapper for const char * TH1D::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1D::DeclFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    module_.method("TH1D!DeclFileName", []() { return (std::string)TH1D::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TH1D::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1D::ImplFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    module_.method("TH1D!ImplFileLine", static_cast<int (*)() >(&TH1D::ImplFileLine));

    DEBUG_MSG("Adding wrapper for const char * TH1D::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1D::ImplFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    module_.method("TH1D!ImplFileName", []() { return (std::string)TH1D::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TH1D::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1D::Class_Name()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    module_.method("TH1D!Class_Name", []() { return (std::string)TH1D::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TH1D::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1D::Dictionary()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    module_.method("TH1D!Dictionary", static_cast<TClass * (*)() >(&TH1D::Dictionary));

    DEBUG_MSG("Adding wrapper for TClass * TH1D::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1D::Class()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    module_.method("TH1D!Class", static_cast<TClass * (*)() >(&TH1D::Class));

    DEBUG_MSG("Adding wrapper for void TH1D::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    t.method("Streamer", static_cast<void (TH1D::*)(TBuffer &) >(&TH1D::Streamer));

    DEBUG_MSG("Adding wrapper for int TH1D::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1D::DeclFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:692:4
    module_.method("TH1D!DeclFileLine", static_cast<int (*)() >(&TH1D::DeclFileLine));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TH1D>> type_;
};
std::shared_ptr<Wrapper> newJlTH1D(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTH1D(module));
}
