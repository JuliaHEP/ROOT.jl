// this file was auto-generated by wrapit v1.3.2
#include "Wrapper.h"

#include "jlROOT.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

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
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:577:7
    jlcxx::TypeWrapper<TH1F>  t = jlModule.add_type<TH1F>("TH1F",
      jlcxx::julia_base_type<TH1>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TH1F>>(new jlcxx::TypeWrapper<TH1F>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1F::TH1F(const char *, const char *, Int_t, Double_t, Double_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:581:4
    t.constructor<const char *, const char *, Int_t, Double_t, Double_t>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1F::TH1F(const char *, const char *, Int_t, const Float_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:582:4
    t.constructor<const char *, const char *, Int_t, const Float_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1F::TH1F(const char *, const char *, Int_t, const Double_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:583:4
    t.constructor<const char *, const char *, Int_t, const Double_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1F::TH1F(const TH1F &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:585:4
    t.constructor<const TH1F &>(/*finalize=*/true);

    DEBUG_MSG("Adding wrapper for TH1F & TH1F::operator=(const TH1F &) (" __HERE__ ")");
    // signature to use in the veto list: TH1F & TH1F::operator=(const TH1F &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:586:10
    t.method("assign", static_cast<TH1F & (TH1F::*)(const TH1F &) >(&TH1F::operator=));

    DEBUG_MSG("Adding wrapper for void TH1F::AddBinContent(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::AddBinContent(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:589:13
    t.method("AddBinContent", static_cast<void (TH1F::*)(Int_t) >(&TH1F::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1F::AddBinContent(Int_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::AddBinContent(Int_t, Double_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:590:13
    t.method("AddBinContent", static_cast<void (TH1F::*)(Int_t, Double_t) >(&TH1F::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1F::Copy(TObject &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::Copy(TObject &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:592:13
    t.method("Copy", static_cast<void (TH1F::*)(TObject &)  const>(&TH1F::Copy));

    DEBUG_MSG("Adding wrapper for void TH1F::Reset(Option_t *) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::Reset(Option_t *)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:593:13
    t.method("Reset", static_cast<void (TH1F::*)(Option_t *) >(&TH1F::Reset));
    t.method("Reset", [](TH1F& a)->void { a.Reset(); });
    t.method("Reset", [](TH1F* a)->void { a->Reset(); });

    DEBUG_MSG("Adding wrapper for void TH1F::SetBinsLength(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::SetBinsLength(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:594:13
    t.method("SetBinsLength", static_cast<void (TH1F::*)(Int_t) >(&TH1F::SetBinsLength));
    t.method("SetBinsLength", [](TH1F& a)->void { a.SetBinsLength(); });
    t.method("SetBinsLength", [](TH1F* a)->void { a->SetBinsLength(); });

    DEBUG_MSG("Adding wrapper for Version_t TH1F::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TH1F::Class_Version()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    module_.method("TH1F!Class_Version", static_cast<Version_t (*)() >(&TH1F::Class_Version));

    DEBUG_MSG("Adding wrapper for TClass * TH1F::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1F::IsA()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    t.method("IsA", static_cast<TClass * (TH1F::*)()  const>(&TH1F::IsA));

    DEBUG_MSG("Adding wrapper for void TH1F::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    t.method("StreamerNVirtual", static_cast<void (TH1F::*)(TBuffer &) >(&TH1F::StreamerNVirtual));

    DEBUG_MSG("Adding wrapper for const char * TH1F::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1F::DeclFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    module_.method("TH1F!DeclFileName", []() { return (std::string)TH1F::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TH1F::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1F::ImplFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    module_.method("TH1F!ImplFileLine", static_cast<int (*)() >(&TH1F::ImplFileLine));

    DEBUG_MSG("Adding wrapper for const char * TH1F::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1F::ImplFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    module_.method("TH1F!ImplFileName", []() { return (std::string)TH1F::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TH1F::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1F::Class_Name()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    module_.method("TH1F!Class_Name", []() { return (std::string)TH1F::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TH1F::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1F::Dictionary()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    module_.method("TH1F!Dictionary", static_cast<TClass * (*)() >(&TH1F::Dictionary));

    DEBUG_MSG("Adding wrapper for TClass * TH1F::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1F::Class()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    module_.method("TH1F!Class", static_cast<TClass * (*)() >(&TH1F::Class));

    DEBUG_MSG("Adding wrapper for void TH1F::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1F::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
    t.method("Streamer", static_cast<void (TH1F::*)(TBuffer &) >(&TH1F::Streamer));

    DEBUG_MSG("Adding wrapper for int TH1F::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1F::DeclFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:596:4
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
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:620:7
    jlcxx::TypeWrapper<TH1D>  t = jlModule.add_type<TH1D>("TH1D",
      jlcxx::julia_base_type<TH1>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TH1D>>(new jlcxx::TypeWrapper<TH1D>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const char *, const char *, Int_t, Double_t, Double_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:624:4
    t.constructor<const char *, const char *, Int_t, Double_t, Double_t>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const char *, const char *, Int_t, const Float_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:625:4
    t.constructor<const char *, const char *, Int_t, const Float_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const char *, const char *, Int_t, const Double_t *) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:626:4
    t.constructor<const char *, const char *, Int_t, const Double_t *>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const TVectorD &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:627:13
    t.constructor<const TVectorD &>(/*finalize=*/true);


    DEBUG_MSG("Adding wrapper for void TH1D::TH1D(const TH1D &) (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:628:4
    t.constructor<const TH1D &>(/*finalize=*/true);

    DEBUG_MSG("Adding wrapper for TH1D & TH1D::operator=(const TH1D &) (" __HERE__ ")");
    // signature to use in the veto list: TH1D & TH1D::operator=(const TH1D &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:629:10
    t.method("assign", static_cast<TH1D & (TH1D::*)(const TH1D &) >(&TH1D::operator=));

    DEBUG_MSG("Adding wrapper for void TH1D::AddBinContent(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::AddBinContent(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:632:13
    t.method("AddBinContent", static_cast<void (TH1D::*)(Int_t) >(&TH1D::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1D::AddBinContent(Int_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::AddBinContent(Int_t, Double_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:633:13
    t.method("AddBinContent", static_cast<void (TH1D::*)(Int_t, Double_t) >(&TH1D::AddBinContent));

    DEBUG_MSG("Adding wrapper for void TH1D::Copy(TObject &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::Copy(TObject &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:635:13
    t.method("Copy", static_cast<void (TH1D::*)(TObject &)  const>(&TH1D::Copy));

    DEBUG_MSG("Adding wrapper for void TH1D::Reset(Option_t *) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::Reset(Option_t *)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:636:13
    t.method("Reset", static_cast<void (TH1D::*)(Option_t *) >(&TH1D::Reset));
    t.method("Reset", [](TH1D& a)->void { a.Reset(); });
    t.method("Reset", [](TH1D* a)->void { a->Reset(); });

    DEBUG_MSG("Adding wrapper for void TH1D::SetBinsLength(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::SetBinsLength(Int_t)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:637:13
    t.method("SetBinsLength", static_cast<void (TH1D::*)(Int_t) >(&TH1D::SetBinsLength));
    t.method("SetBinsLength", [](TH1D& a)->void { a.SetBinsLength(); });
    t.method("SetBinsLength", [](TH1D* a)->void { a->SetBinsLength(); });

    DEBUG_MSG("Adding wrapper for Version_t TH1D::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TH1D::Class_Version()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    module_.method("TH1D!Class_Version", static_cast<Version_t (*)() >(&TH1D::Class_Version));

    DEBUG_MSG("Adding wrapper for TClass * TH1D::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1D::IsA()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    t.method("IsA", static_cast<TClass * (TH1D::*)()  const>(&TH1D::IsA));

    DEBUG_MSG("Adding wrapper for void TH1D::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    t.method("StreamerNVirtual", static_cast<void (TH1D::*)(TBuffer &) >(&TH1D::StreamerNVirtual));

    DEBUG_MSG("Adding wrapper for const char * TH1D::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1D::DeclFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    module_.method("TH1D!DeclFileName", []() { return (std::string)TH1D::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TH1D::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1D::ImplFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    module_.method("TH1D!ImplFileLine", static_cast<int (*)() >(&TH1D::ImplFileLine));

    DEBUG_MSG("Adding wrapper for const char * TH1D::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1D::ImplFileName()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    module_.method("TH1D!ImplFileName", []() { return (std::string)TH1D::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TH1D::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TH1D::Class_Name()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    module_.method("TH1D!Class_Name", []() { return (std::string)TH1D::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TH1D::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1D::Dictionary()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    module_.method("TH1D!Dictionary", static_cast<TClass * (*)() >(&TH1D::Dictionary));

    DEBUG_MSG("Adding wrapper for TClass * TH1D::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TH1D::Class()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    module_.method("TH1D!Class", static_cast<TClass * (*)() >(&TH1D::Class));

    DEBUG_MSG("Adding wrapper for void TH1D::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TH1D::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    t.method("Streamer", static_cast<void (TH1D::*)(TBuffer &) >(&TH1D::Streamer));

    DEBUG_MSG("Adding wrapper for int TH1D::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TH1D::DeclFileLine()
    // defined in /home/pgras/.julia/conda/3/include/TH1.h:639:4
    module_.method("TH1D!DeclFileLine", static_cast<int (*)() >(&TH1D::DeclFileLine));
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TH1D>> type_;
};
std::shared_ptr<Wrapper> newJlTH1D(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTH1D(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TApplicationImp> : std::false_type { };
  template<> struct DefaultConstructible<TApplicationImp> : std::false_type { };
}

// Class generating the wrapper for type TApplicationImp
// signature to use in the veto file: TApplicationImp
struct JlTApplicationImp: public Wrapper {

  JlTApplicationImp(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TApplicationImp (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TApplicationImp.h:29:7
    jlcxx::TypeWrapper<TApplicationImp>  t = jlModule.add_type<TApplicationImp>("TApplicationImp");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TApplicationImp>>(new jlcxx::TypeWrapper<TApplicationImp>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TApplicationImp>> type_;
};
std::shared_ptr<Wrapper> newJlTApplicationImp(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTApplicationImp(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TDatime> : std::false_type { };
  template<> struct DefaultConstructible<TDatime> : std::false_type { };
}

// Class generating the wrapper for type TDatime
// signature to use in the veto file: TDatime
struct JlTDatime: public Wrapper {

  JlTDatime(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TDatime (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TDatime.h:37:7
    jlcxx::TypeWrapper<TDatime>  t = jlModule.add_type<TDatime>("TDatime");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TDatime>>(new jlcxx::TypeWrapper<TDatime>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TDatime>> type_;
};
std::shared_ptr<Wrapper> newJlTDatime(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTDatime(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TArrayC> : std::false_type { };
  template<> struct DefaultConstructible<TArrayC> : std::false_type { };
}

// Class generating the wrapper for type TArrayC
// signature to use in the veto file: TArrayC
struct JlTArrayC: public Wrapper {

  JlTArrayC(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TArrayC (" __HERE__ ")");
    // defined in /home/pgras/.julia/conda/3/include/TArrayC.h:27:7
    jlcxx::TypeWrapper<TArrayC>  t = jlModule.add_type<TArrayC>("TArrayC");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TArrayC>>(new jlcxx::TypeWrapper<TArrayC>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/true);
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TArrayC>> type_;
};
std::shared_ptr<Wrapper> newJlTArrayC(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTArrayC(module));
}
