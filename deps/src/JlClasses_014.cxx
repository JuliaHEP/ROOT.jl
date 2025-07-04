// this file was auto-generated by wrapit v1.6.0
#include "Wrapper.h"

#include "jlROOT.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

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
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderValue.h:146:30
    jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>  t =  jlModule.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("TTreeReaderValue");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>>(new jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>(jlModule, t));
    auto t101_decl_methods = [this]<typename T> (jlcxx::TypeWrapper<TTreeReaderValue<T>> wrapped){
      auto module_ = this->module_;
      typedef TTreeReaderValue<T> WrappedType;


      DEBUG_MSG("Adding wrapper for void TTreeReaderValue::TTreeReaderValue<T>(TTreeReader &, const char *) (" __HERE__ ")");
      // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderValue.h:152:4
      wrapped.template constructor<TTreeReader &, const char *>(/*finalize=*/jlcxx::finalize_policy::yes, jlcxx::arg("this"), jlcxx::arg("tr"), jlcxx::arg("branchname")      );

      DEBUG_MSG("Adding wrapper for T * TTreeReaderValue::Get() (" __HERE__ ")");
      // signature to use in the veto list: T * TTreeReaderValue::Get()
      // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderValue.h:161:7
      wrapped.method("Get", [](WrappedType& a)->T * { return a.Get(); }, jlcxx::arg("this"));
      wrapped.method("Get", [](WrappedType* a)->T * { return a->Get(); }, jlcxx::arg("this"));

      DEBUG_MSG("Adding wrapper for T * TTreeReaderValue::operator->() (" __HERE__ ")");
      // signature to use in the veto list: T * TTreeReaderValue::operator->()
      // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderValue.h:174:7
      wrapped.method("arrow", [](WrappedType& a)->T * { return a.operator->(); }, jlcxx::arg("this"));
      wrapped.method("arrow", [](WrappedType* a)->T * { return a->operator->(); }, jlcxx::arg("this"));
      module_.set_override_module(jl_base_module);

      DEBUG_MSG("Adding wrapper for T & TTreeReaderValue::operator*() (" __HERE__ ")");
      // signature to use in the veto list: T & TTreeReaderValue::operator*()
      // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderValue.h:179:7
      wrapped.method("getindex", [](WrappedType& a)->T & { return a.operator*(); }, jlcxx::arg("this"));
      wrapped.method("getindex", [](WrappedType* a)->T & { return a->operator*(); }, jlcxx::arg("this"));

      module_.unset_override_module();
    };
    t.apply<TTreeReaderValue<double>, TTreeReaderValue<float>, TTreeReaderValue<unsigned long>, TTreeReaderValue<long>, TTreeReaderValue<unsigned int>, TTreeReaderValue<int>, TTreeReaderValue<unsigned short>, TTreeReaderValue<short>, TTreeReaderValue<unsigned char>, TTreeReaderValue<char>>(t101_decl_methods);
  }

  void add_methods() const{
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>> type_;
};
std::shared_ptr<Wrapper> newJlTTreeReaderValue(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTTreeReaderValue(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TTreeReader::Iterator_t> : std::false_type { };
  template<> struct DefaultConstructible<TTreeReader::Iterator_t> : std::false_type { };
}

// Class generating the wrapper for type TTreeReader::Iterator_t
// signature to use in the veto file: TTreeReader::Iterator_t
struct JlTTreeReader_Iterator_t: public Wrapper {

  JlTTreeReader_Iterator_t(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TTreeReader::Iterator_t (" __HERE__ ")");
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReader.h:56:10
    jlcxx::TypeWrapper<TTreeReader::Iterator_t>  t = jlModule.add_type<TTreeReader::Iterator_t>("TTreeReader!Iterator_t");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TTreeReader::Iterator_t>>(new jlcxx::TypeWrapper<TTreeReader::Iterator_t>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes    );


    DEBUG_MSG("Adding wrapper for void TTreeReader::Iterator_t::Iterator_t(TTreeReader &, Long64_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReader.h:77:7
    t.constructor<TTreeReader &, Long64_t>(/*finalize=*/jlcxx::finalize_policy::yes, jlcxx::arg("this"), jlcxx::arg("reader"), jlcxx::arg("entry")    );
    module_.set_override_module(jl_base_module);

    DEBUG_MSG("Adding wrapper for bool TTreeReader::Iterator_t::operator==(const TTreeReader::Iterator_t &) (" __HERE__ ")");
    // signature to use in the veto list: bool TTreeReader::Iterator_t::operator==(const TTreeReader::Iterator_t &)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReader.h:81:12
    t.method("==", [](TTreeReader::Iterator_t const& a, const TTreeReader::Iterator_t & arg0)->bool { return a.operator==(arg0); }, jlcxx::arg("this"), jlcxx::arg("lhs"));
    t.method("==", [](TTreeReader::Iterator_t const* a, const TTreeReader::Iterator_t & arg0)->bool { return a->operator==(arg0); }, jlcxx::arg("this"), jlcxx::arg("lhs"));

    DEBUG_MSG("Adding wrapper for bool TTreeReader::Iterator_t::operator!=(const TTreeReader::Iterator_t &) (" __HERE__ ")");
    // signature to use in the veto list: bool TTreeReader::Iterator_t::operator!=(const TTreeReader::Iterator_t &)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReader.h:107:12
    t.method("!=", [](TTreeReader::Iterator_t const& a, const TTreeReader::Iterator_t & arg0)->bool { return a.operator!=(arg0); }, jlcxx::arg("this"), jlcxx::arg("lhs"));
    t.method("!=", [](TTreeReader::Iterator_t const* a, const TTreeReader::Iterator_t & arg0)->bool { return a->operator!=(arg0); }, jlcxx::arg("this"), jlcxx::arg("lhs"));

    DEBUG_MSG("Adding wrapper for const Long64_t & TTreeReader::Iterator_t::operator*() (" __HERE__ ")");
    // signature to use in the veto list: const Long64_t & TTreeReader::Iterator_t::operator*()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReader.h:132:23
    t.method("getindex", [](TTreeReader::Iterator_t& a)->const Long64_t & { return a.operator*(); }, jlcxx::arg("this"));
    t.method("getindex", [](TTreeReader::Iterator_t* a)->const Long64_t & { return a->operator*(); }, jlcxx::arg("this"));

    DEBUG_MSG("Adding wrapper for const Long64_t & TTreeReader::Iterator_t::operator*() (" __HERE__ ")");
    // signature to use in the veto list: const Long64_t & TTreeReader::Iterator_t::operator*()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReader.h:143:23
    t.method("getindex", [](TTreeReader::Iterator_t const& a)->const Long64_t & { return a.operator*(); }, jlcxx::arg("this"));
    t.method("getindex", [](TTreeReader::Iterator_t const* a)->const Long64_t & { return a->operator*(); }, jlcxx::arg("this"));

    module_.unset_override_module();
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TTreeReader::Iterator_t>> type_;
};
std::shared_ptr<Wrapper> newJlTTreeReader_Iterator_t(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTTreeReader_Iterator_t(module));
}

namespace jlcxx {

  template<typename T>
  struct BuildParameterList<TTreeReaderArray<T>>
  {
    typedef ParameterList<T> type;
  };

  template<typename T> struct IsMirroredType<TTreeReaderArray<T>> : std::false_type { };
  template<typename T> struct DefaultConstructible<TTreeReaderArray<T>> : std::false_type { };
}

// Class generating the wrapper for type TTreeReaderArray
// signature to use in the veto file: TTreeReaderArray
struct JlTTreeReaderArray: public Wrapper {

  JlTTreeReaderArray(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TTreeReaderArray (" __HERE__ ")");
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderArray.h:75:30
    jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>  t =  jlModule.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("TTreeReaderArray");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>>(new jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>(jlModule, t));
    auto t107_decl_methods = [this]<typename T> (jlcxx::TypeWrapper<TTreeReaderArray<T>> wrapped){
      auto module_ = this->module_;
      typedef TTreeReaderArray<T> WrappedType;


      DEBUG_MSG("Adding wrapper for void TTreeReaderArray::TTreeReaderArray<T>(TTreeReader &, const char *) (" __HERE__ ")");
      // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderArray.h:202:4
      wrapped.template constructor<TTreeReader &, const char *>(/*finalize=*/jlcxx::finalize_policy::yes, jlcxx::arg("this"), jlcxx::arg("tr"), jlcxx::arg("branchname")      );

      DEBUG_MSG("Adding wrapper for T & TTreeReaderArray::At(std::size_t) (" __HERE__ ")");
      // signature to use in the veto list: T & TTreeReaderArray::At(std::size_t)
      // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderArray.h:205:7
      wrapped.method("At", [](WrappedType& a, std::size_t arg0)->T & { return a.At(arg0); }, jlcxx::arg("this"), jlcxx::arg("idx"));
      wrapped.method("At", [](WrappedType* a, std::size_t arg0)->T & { return a->At(arg0); }, jlcxx::arg("this"), jlcxx::arg("idx"));

      DEBUG_MSG("Adding wrapper for const T & TTreeReaderArray::At(std::size_t) (" __HERE__ ")");
      // signature to use in the veto list: const T & TTreeReaderArray::At(std::size_t)
      // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderArray.h:206:13
      wrapped.method("At", [](WrappedType const& a, std::size_t arg0)->const T & { return a.At(arg0); }, jlcxx::arg("this"), jlcxx::arg("idx"));
      wrapped.method("At", [](WrappedType const* a, std::size_t arg0)->const T & { return a->At(arg0); }, jlcxx::arg("this"), jlcxx::arg("idx"));
      module_.set_override_module(jl_base_module);


      DEBUG_MSG("Adding setindex! method  to wrap T & TTreeReaderArray::operator[](std::size_t) (" __HERE__ ")");
// defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderArray.h:207:7
      wrapped.method("setindex!",
        [](WrappedType& a, std::size_t i, T const & val){
        return a[i] = val;
      }, jlcxx::arg("this"), jlcxx::arg("index"), jlcxx::arg("value"));

      DEBUG_MSG("Adding getindex method to wrap T & TTreeReaderArray::operator[](std::size_t) (" __HERE__ ")");
      // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TTreeReaderArray.h:207:7
      wrapped.method("getindex",
        [](WrappedType& a, std::size_t i){
        return a[i];
      }, jlcxx::arg("this"), jlcxx::arg("index"));


      module_.unset_override_module();
    };
    t.apply<TTreeReaderArray<double>, TTreeReaderArray<float>, TTreeReaderArray<unsigned long>, TTreeReaderArray<long>, TTreeReaderArray<unsigned int>, TTreeReaderArray<int>, TTreeReaderArray<unsigned short>, TTreeReaderArray<short>, TTreeReaderArray<unsigned char>, TTreeReaderArray<char>>(t107_decl_methods);
  }

  void add_methods() const{
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>> type_;
};
std::shared_ptr<Wrapper> newJlTTreeReaderArray(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTTreeReaderArray(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TObjLink> : std::false_type { };
  template<> struct DefaultConstructible<TObjLink> : std::false_type { };
}

// Class generating the wrapper for type TObjLink
// signature to use in the veto file: TObjLink
struct JlTObjLink: public Wrapper {

  JlTObjLink(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TObjLink (" __HERE__ ")");
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TList.h:123:7
    jlcxx::TypeWrapper<TObjLink>  t = jlModule.add_type<TObjLink>("TObjLink");
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TObjLink>>(new jlcxx::TypeWrapper<TObjLink>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TObjLink>> type_;
};
std::shared_ptr<Wrapper> newJlTObjLink(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTObjLink(module));
}

namespace jlcxx {
  template<> struct IsMirroredType<TRandom> : std::false_type { };
  template<> struct DefaultConstructible<TRandom> : std::false_type { };
template<> struct SuperType<TRandom> { typedef TNamed type; };
}

// Class generating the wrapper for type TRandom
// signature to use in the veto file: TRandom
struct JlTRandom: public Wrapper {

  JlTRandom(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type TRandom (" __HERE__ ")");
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:27:7
    jlcxx::TypeWrapper<TRandom>  t = jlModule.add_type<TRandom>("TRandom",
      jlcxx::julia_base_type<TNamed>());
    type_ = std::unique_ptr<jlcxx::TypeWrapper<TRandom>>(new jlcxx::TypeWrapper<TRandom>(jlModule, t));
  }

  void add_methods() const{
    auto& t = *type_;
    t.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes    );


    DEBUG_MSG("Adding wrapper for void TRandom::TRandom(UInt_t) (" __HERE__ ")");
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:33:4
    t.constructor<UInt_t>(/*finalize=*/jlcxx::finalize_policy::yes, jlcxx::arg("this"), jlcxx::arg("seed")    );

    DEBUG_MSG("Adding wrapper for Int_t TRandom::Binomial(Int_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: Int_t TRandom::Binomial(Int_t, Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:35:22
    t.method("Binomial", [](TRandom& a, Int_t arg0, Double_t arg1)->Int_t { return a.Binomial(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("ntot"), jlcxx::arg("prob"));
    t.method("Binomial", [](TRandom* a, Int_t arg0, Double_t arg1)->Int_t { return a->Binomial(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("ntot"), jlcxx::arg("prob"));

    DEBUG_MSG("Adding wrapper for Double_t TRandom::BreitWigner(Double_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: Double_t TRandom::BreitWigner(Double_t, Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:36:22
    t.method("BreitWigner", [](TRandom& a)->Double_t { return a.BreitWigner(); }, jlcxx::arg("this"));
    t.method("BreitWigner", [](TRandom& a, Double_t arg0)->Double_t { return a.BreitWigner(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));
    t.method("BreitWigner", [](TRandom& a, Double_t arg0, Double_t arg1)->Double_t { return a.BreitWigner(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("mean"), jlcxx::arg("gamma"));
    t.method("BreitWigner", [](TRandom* a)->Double_t { return a->BreitWigner(); }, jlcxx::arg("this"));
    t.method("BreitWigner", [](TRandom* a, Double_t arg0)->Double_t { return a->BreitWigner(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));
    t.method("BreitWigner", [](TRandom* a, Double_t arg0, Double_t arg1)->Double_t { return a->BreitWigner(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("mean"), jlcxx::arg("gamma"));

    DEBUG_MSG("Adding wrapper for void TRandom::Circle(Double_t &, Double_t &, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::Circle(Double_t &, Double_t &, Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:37:22
    t.method("Circle", [](TRandom& a, Double_t & arg0, Double_t & arg1, Double_t arg2)->void { a.Circle(arg0, arg1, arg2); }, jlcxx::arg("this"), jlcxx::arg("x"), jlcxx::arg("y"), jlcxx::arg("r"));
    t.method("Circle", [](TRandom* a, Double_t & arg0, Double_t & arg1, Double_t arg2)->void { a->Circle(arg0, arg1, arg2); }, jlcxx::arg("this"), jlcxx::arg("x"), jlcxx::arg("y"), jlcxx::arg("r"));

    DEBUG_MSG("Adding wrapper for Double_t TRandom::Exp(Double_t) (" __HERE__ ")");
    // signature to use in the veto list: Double_t TRandom::Exp(Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:38:22
    t.method("Exp", [](TRandom& a, Double_t arg0)->Double_t { return a.Exp(arg0); }, jlcxx::arg("this"), jlcxx::arg("tau"));
    t.method("Exp", [](TRandom* a, Double_t arg0)->Double_t { return a->Exp(arg0); }, jlcxx::arg("this"), jlcxx::arg("tau"));

    DEBUG_MSG("Adding wrapper for Double_t TRandom::Gaus(Double_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: Double_t TRandom::Gaus(Double_t, Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:39:22
    t.method("Gaus", [](TRandom& a)->Double_t { return a.Gaus(); }, jlcxx::arg("this"));
    t.method("Gaus", [](TRandom& a, Double_t arg0)->Double_t { return a.Gaus(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));
    t.method("Gaus", [](TRandom& a, Double_t arg0, Double_t arg1)->Double_t { return a.Gaus(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("mean"), jlcxx::arg("sigma"));
    t.method("Gaus", [](TRandom* a)->Double_t { return a->Gaus(); }, jlcxx::arg("this"));
    t.method("Gaus", [](TRandom* a, Double_t arg0)->Double_t { return a->Gaus(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));
    t.method("Gaus", [](TRandom* a, Double_t arg0, Double_t arg1)->Double_t { return a->Gaus(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("mean"), jlcxx::arg("sigma"));

    DEBUG_MSG("Adding wrapper for UInt_t TRandom::GetSeed() (" __HERE__ ")");
    // signature to use in the veto list: UInt_t TRandom::GetSeed()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:40:22
    t.method("GetSeed", [](TRandom const& a)->UInt_t { return a.GetSeed(); }, jlcxx::arg("this"));
    t.method("GetSeed", [](TRandom const* a)->UInt_t { return a->GetSeed(); }, jlcxx::arg("this"));

    DEBUG_MSG("Adding wrapper for UInt_t TRandom::Integer(UInt_t) (" __HERE__ ")");
    // signature to use in the veto list: UInt_t TRandom::Integer(UInt_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:41:22
    t.method("Integer", [](TRandom& a, UInt_t arg0)->UInt_t { return a.Integer(arg0); }, jlcxx::arg("this"), jlcxx::arg("imax"));
    t.method("Integer", [](TRandom* a, UInt_t arg0)->UInt_t { return a->Integer(arg0); }, jlcxx::arg("this"), jlcxx::arg("imax"));

    DEBUG_MSG("Adding wrapper for Double_t TRandom::Landau(Double_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: Double_t TRandom::Landau(Double_t, Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:42:22
    t.method("Landau", [](TRandom& a)->Double_t { return a.Landau(); }, jlcxx::arg("this"));
    t.method("Landau", [](TRandom& a, Double_t arg0)->Double_t { return a.Landau(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));
    t.method("Landau", [](TRandom& a, Double_t arg0, Double_t arg1)->Double_t { return a.Landau(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("mean"), jlcxx::arg("sigma"));
    t.method("Landau", [](TRandom* a)->Double_t { return a->Landau(); }, jlcxx::arg("this"));
    t.method("Landau", [](TRandom* a, Double_t arg0)->Double_t { return a->Landau(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));
    t.method("Landau", [](TRandom* a, Double_t arg0, Double_t arg1)->Double_t { return a->Landau(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("mean"), jlcxx::arg("sigma"));

    DEBUG_MSG("Adding wrapper for ULong64_t TRandom::Poisson(Double_t) (" __HERE__ ")");
    // signature to use in the veto list: ULong64_t TRandom::Poisson(Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:43:22
    t.method("Poisson", [](TRandom& a, Double_t arg0)->ULong64_t { return a.Poisson(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));
    t.method("Poisson", [](TRandom* a, Double_t arg0)->ULong64_t { return a->Poisson(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));

    DEBUG_MSG("Adding wrapper for Double_t TRandom::PoissonD(Double_t) (" __HERE__ ")");
    // signature to use in the veto list: Double_t TRandom::PoissonD(Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:44:22
    t.method("PoissonD", [](TRandom& a, Double_t arg0)->Double_t { return a.PoissonD(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));
    t.method("PoissonD", [](TRandom* a, Double_t arg0)->Double_t { return a->PoissonD(arg0); }, jlcxx::arg("this"), jlcxx::arg("mean"));

    DEBUG_MSG("Adding wrapper for void TRandom::Rannor(Float_t &, Float_t &) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::Rannor(Float_t &, Float_t &)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:45:22
    t.method("Rannor", [](TRandom& a, Float_t & arg0, Float_t & arg1)->void { a.Rannor(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("a"), jlcxx::arg("b"));
    t.method("Rannor", [](TRandom* a, Float_t & arg0, Float_t & arg1)->void { a->Rannor(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("a"), jlcxx::arg("b"));

    DEBUG_MSG("Adding wrapper for void TRandom::Rannor(Double_t &, Double_t &) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::Rannor(Double_t &, Double_t &)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:46:22
    t.method("Rannor", [](TRandom& a, Double_t & arg0, Double_t & arg1)->void { a.Rannor(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("a"), jlcxx::arg("b"));
    t.method("Rannor", [](TRandom* a, Double_t & arg0, Double_t & arg1)->void { a->Rannor(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("a"), jlcxx::arg("b"));

    DEBUG_MSG("Adding wrapper for void TRandom::ReadRandom(const char *) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::ReadRandom(const char *)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:47:22
    t.method("ReadRandom", [](TRandom& a, const char * arg0)->void { a.ReadRandom(arg0); }, jlcxx::arg("this"), jlcxx::arg("filename"));
    t.method("ReadRandom", [](TRandom* a, const char * arg0)->void { a->ReadRandom(arg0); }, jlcxx::arg("this"), jlcxx::arg("filename"));

    DEBUG_MSG("Adding wrapper for void TRandom::SetSeed(ULong_t) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::SetSeed(ULong_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:48:22
    t.method("SetSeed", [](TRandom& a)->void { a.SetSeed(); }, jlcxx::arg("this"), jlcxx::arg("seed"));
    t.method("SetSeed", [](TRandom& a, ULong_t arg0)->void { a.SetSeed(arg0); }, jlcxx::arg("this"), jlcxx::arg("seed"));
    t.method("SetSeed", [](TRandom* a)->void { a->SetSeed(); }, jlcxx::arg("this"), jlcxx::arg("seed"));
    t.method("SetSeed", [](TRandom* a, ULong_t arg0)->void { a->SetSeed(arg0); }, jlcxx::arg("this"), jlcxx::arg("seed"));

    DEBUG_MSG("Adding wrapper for Double_t TRandom::Rndm() (" __HERE__ ")");
    // signature to use in the veto list: Double_t TRandom::Rndm()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:49:14
    t.method("Rndm", [](TRandom& a)->Double_t { return a.Rndm(); }, jlcxx::arg("this"));
    t.method("Rndm", [](TRandom* a)->Double_t { return a->Rndm(); }, jlcxx::arg("this"));

    DEBUG_MSG("Adding wrapper for Double_t TRandom::Rndm(Int_t) (" __HERE__ ")");
    // signature to use in the veto list: Double_t TRandom::Rndm(Int_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:51:22
    t.method("Rndm", [](TRandom& a, Int_t arg0)->Double_t { return a.Rndm(arg0); }, jlcxx::arg("this"), jlcxx::arg("arg0"));
    t.method("Rndm", [](TRandom* a, Int_t arg0)->Double_t { return a->Rndm(arg0); }, jlcxx::arg("this"), jlcxx::arg("arg0"));

    DEBUG_MSG("Adding wrapper for void TRandom::RndmArray(Int_t, Float_t *) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::RndmArray(Int_t, Float_t *)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:52:22
    t.method("RndmArray", [](TRandom& a, Int_t arg0, Float_t * arg1)->void { a.RndmArray(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("n"), jlcxx::arg("array"));
    t.method("RndmArray", [](TRandom* a, Int_t arg0, Float_t * arg1)->void { a->RndmArray(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("n"), jlcxx::arg("array"));

    DEBUG_MSG("Adding wrapper for void TRandom::RndmArray(Int_t, Double_t *) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::RndmArray(Int_t, Double_t *)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:53:22
    t.method("RndmArray", [](TRandom& a, Int_t arg0, Double_t * arg1)->void { a.RndmArray(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("n"), jlcxx::arg("array"));
    t.method("RndmArray", [](TRandom* a, Int_t arg0, Double_t * arg1)->void { a->RndmArray(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("n"), jlcxx::arg("array"));

    DEBUG_MSG("Adding wrapper for void TRandom::Sphere(Double_t &, Double_t &, Double_t &, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::Sphere(Double_t &, Double_t &, Double_t &, Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:54:22
    t.method("Sphere", [](TRandom& a, Double_t & arg0, Double_t & arg1, Double_t & arg2, Double_t arg3)->void { a.Sphere(arg0, arg1, arg2, arg3); }, jlcxx::arg("this"), jlcxx::arg("x"), jlcxx::arg("y"), jlcxx::arg("z"), jlcxx::arg("r"));
    t.method("Sphere", [](TRandom* a, Double_t & arg0, Double_t & arg1, Double_t & arg2, Double_t arg3)->void { a->Sphere(arg0, arg1, arg2, arg3); }, jlcxx::arg("this"), jlcxx::arg("x"), jlcxx::arg("y"), jlcxx::arg("z"), jlcxx::arg("r"));

    DEBUG_MSG("Adding wrapper for Double_t TRandom::Uniform(Double_t) (" __HERE__ ")");
    // signature to use in the veto list: Double_t TRandom::Uniform(Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:55:22
    t.method("Uniform", [](TRandom& a)->Double_t { return a.Uniform(); }, jlcxx::arg("this"));
    t.method("Uniform", [](TRandom& a, Double_t arg0)->Double_t { return a.Uniform(arg0); }, jlcxx::arg("this"), jlcxx::arg("x1"));
    t.method("Uniform", [](TRandom* a)->Double_t { return a->Uniform(); }, jlcxx::arg("this"));
    t.method("Uniform", [](TRandom* a, Double_t arg0)->Double_t { return a->Uniform(arg0); }, jlcxx::arg("this"), jlcxx::arg("x1"));

    DEBUG_MSG("Adding wrapper for Double_t TRandom::Uniform(Double_t, Double_t) (" __HERE__ ")");
    // signature to use in the veto list: Double_t TRandom::Uniform(Double_t, Double_t)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:56:22
    t.method("Uniform", [](TRandom& a, Double_t arg0, Double_t arg1)->Double_t { return a.Uniform(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("x1"), jlcxx::arg("x2"));
    t.method("Uniform", [](TRandom* a, Double_t arg0, Double_t arg1)->Double_t { return a->Uniform(arg0, arg1); }, jlcxx::arg("this"), jlcxx::arg("x1"), jlcxx::arg("x2"));

    DEBUG_MSG("Adding wrapper for void TRandom::WriteRandom(const char *) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::WriteRandom(const char *)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/TRandom.h:57:22
    t.method("WriteRandom", [](TRandom const& a, const char * arg0)->void { a.WriteRandom(arg0); }, jlcxx::arg("this"), jlcxx::arg("filename"));
    t.method("WriteRandom", [](TRandom const* a, const char * arg0)->void { a->WriteRandom(arg0); }, jlcxx::arg("this"), jlcxx::arg("filename"));

    DEBUG_MSG("Adding wrapper for Version_t TRandom::Class_Version() (" __HERE__ ")");
    // signature to use in the veto list: Version_t TRandom::Class_Version()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:293:68
    module_.method("TRandom!Class_Version", []()->Version_t { return TRandom::Class_Version(); });

    DEBUG_MSG("Adding wrapper for TClass * TRandom::IsA() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TRandom::IsA()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:294:76
    t.method("IsA", [](TRandom const& a)->TClass * { return a.IsA(); }, jlcxx::arg("this"));
    t.method("IsA", [](TRandom const* a)->TClass * { return a->IsA(); }, jlcxx::arg("this"));

    DEBUG_MSG("Adding wrapper for void TRandom::StreamerNVirtual(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::StreamerNVirtual(TBuffer &)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:300:9
    t.method("StreamerNVirtual", [](TRandom& a, TBuffer & arg0)->void { a.StreamerNVirtual(arg0); }, jlcxx::arg("this"), jlcxx::arg("ClassDef_StreamerNVirtual_b"));
    t.method("StreamerNVirtual", [](TRandom* a, TBuffer & arg0)->void { a->StreamerNVirtual(arg0); }, jlcxx::arg("this"), jlcxx::arg("ClassDef_StreamerNVirtual_b"));

    DEBUG_MSG("Adding wrapper for const char * TRandom::DeclFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TRandom::DeclFileName()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:301:88
    module_.method("TRandom!DeclFileName", []() { return (std::string)TRandom::DeclFileName(); });

    DEBUG_MSG("Adding wrapper for int TRandom::ImplFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TRandom::ImplFileLine()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:309:55
    module_.method("TRandom!ImplFileLine", []()->int { return TRandom::ImplFileLine(); });

    DEBUG_MSG("Adding wrapper for const char * TRandom::ImplFileName() (" __HERE__ ")");
    // signature to use in the veto list: const char * TRandom::ImplFileName()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:310:63
    module_.method("TRandom!ImplFileName", []() { return (std::string)TRandom::ImplFileName(); });

    DEBUG_MSG("Adding wrapper for const char * TRandom::Class_Name() (" __HERE__ ")");
    // signature to use in the veto list: const char * TRandom::Class_Name()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:311:57
    module_.method("TRandom!Class_Name", []() { return (std::string)TRandom::Class_Name(); });

    DEBUG_MSG("Adding wrapper for TClass * TRandom::Dictionary() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TRandom::Dictionary()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:312:47
    module_.method("TRandom!Dictionary", []()->TClass * { return TRandom::Dictionary(); });

    DEBUG_MSG("Adding wrapper for TClass * TRandom::Class() (" __HERE__ ")");
    // signature to use in the veto list: TClass * TRandom::Class()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:313:63
    module_.method("TRandom!Class", []()->TClass * { return TRandom::Class(); });

    DEBUG_MSG("Adding wrapper for void TRandom::Streamer(TBuffer &) (" __HERE__ ")");
    // signature to use in the veto list: void TRandom::Streamer(TBuffer &)
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:314:25
    t.method("Streamer", [](TRandom& a, TBuffer & arg0)->void { a.Streamer(arg0); }, jlcxx::arg("this"), jlcxx::arg("arg0"));
    t.method("Streamer", [](TRandom* a, TBuffer & arg0)->void { a->Streamer(arg0); }, jlcxx::arg("this"), jlcxx::arg("arg0"));

    DEBUG_MSG("Adding wrapper for int TRandom::DeclFileLine() (" __HERE__ ")");
    // signature to use in the veto list: int TRandom::DeclFileLine()
    // defined in /home/pgras/.julia/artifacts/a4f6424ccb8f5188e250f447149860af999a56a0/include/Rtypes.h:343:43
    module_.method("TRandom!DeclFileLine", []()->int { return TRandom::DeclFileLine(); });
  }

private:
  std::unique_ptr<jlcxx::TypeWrapper<TRandom>> type_;
};
std::shared_ptr<Wrapper> newJlTRandom(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlTRandom(module));
}
