/*
 * RVec has many public methods. We redefine in this file a simpler API for
 * Julia, that together with a julia counterpart aims to be similar to Julia
 * AbtractVector ones.
 */

// Desired julia methods:
// Base.getindex → bound check in Julia
// Base.setindex! → bound check and type conversion in Julia
// Base.push! → type conversion in Julia
// Base.length
// Base.sizehint!
// Base.iterate → to implement in Julia
// Base.IteratorSize → to implement in Julia
// Base.firstindex → to implement in Julia
// Base.lastindex → to implement in Julia
// Base.eltype → to implement in Julia
// Base.similar → to implement in Julia
// Base.axes if we dont start indices by 1
// Base.strides → to implement in Julia
// Base.elsize
// Base.copyto!(::RVec, ::Broadcasted)  to optimize broadcasts

#include "Wrapper.h"

#include "jlROOT.h"
#include "dbg_msg.h"
#include "jlcxx/functions.hpp"
#include "jlcxx/stl.hpp"

namespace jlcxx {

  template<typename T>
  struct BuildParameterList<ROOT::VecOps::RVec<T>>
  {
    typedef ParameterList<T> type;
  };

  template<typename T> struct IsMirroredType<ROOT::VecOps::RVec<T>> : std::false_type { };
  template<typename T> struct DefaultConstructible<ROOT::VecOps::RVec<T>> : std::false_type { };
}

// Class generating the wrapper for type ROOT::VecOps::RVec
// signature to use in the veto file: ROOT::VecOps::RVec
struct JlROOT_VecOps_RVec: public Wrapper {

  JlROOT_VecOps_RVec(jlcxx::Module& jlModule): Wrapper(jlModule){
    DEBUG_MSG("Adding wrapper for type ROOT::VecOps::RVec (" __HERE__ ")");
    // defined in /home/pgras/.julia/artifacts/54e60c641c75fb2e5777b51cd519d1c05678ef04/include/ROOT/RVec.hxx:1529:30
    jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>  t =  jlModule.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("ROOT!VecOps!RVec", jlcxx::julia_type("AbstractVector", "Base"));
    type_ = std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>>(new jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>(jlModule, t));
    t.constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);
    
    auto decl_methods = [this]<typename T> (jlcxx::TypeWrapper<ROOT::VecOps::RVec<T>> wrapped){
      auto module_ = this->module_;
      typedef ROOT::VecOps::RVec<T> WrappedType;
      wrapped.template constructor<>(/*finalize=*/jlcxx::finalize_policy::yes);


      DEBUG_MSG("Adding wrapper for ROOT::VecOps::RVec::RVec<T>(size_t, const T &) (" __HERE__ ")");
      // defined in /home/pgras/.julia/artifacts/54e60c641c75fb2e5777b51cd519d1c05678ef04/include/ROOT/RVec.hxx:1544:13
      wrapped.template constructor<size_t, const T &>(/*finalize=*/jlcxx::finalize_policy::yes, jlcxx::arg("this"), jlcxx::arg("Size"), jlcxx::arg("Value"));


      DEBUG_MSG("Adding wrapper for ROOT::VecOps::RVec::RVec<T>(size_t) (" __HERE__ ")");
      // defined in /home/pgras/.julia/artifacts/54e60c641c75fb2e5777b51cd519d1c05678ef04/include/ROOT/RVec.hxx:1546:13
      wrapped.template constructor<size_t>(/*finalize=*/jlcxx::finalize_policy::yes, jlcxx::arg("this"), jlcxx::arg("Size"));

      //Base module method implemenations
      DEBUG_MSG("Adding wrapper to implement setindex!(::RVec,...) (" __HERE__ ")");
      wrapped.method("_unsafe_getindex", [](WrappedType & a, int i)->const T & { return a[i-1]; },
                     jlcxx::arg("this"), jlcxx::arg("val"), jlcxx::arg("i"));
      wrapped.method("_unsafe_getindex", [](WrappedType * a, int i)->const T & { return (*a)[i-1]; },
                     jlcxx::arg("this"), jlcxx::arg("val"), jlcxx::arg("i"));
      wrapped.method("_unsafe_setindex!", [](WrappedType & a, const T& val, int i)->WrappedType & { a[i-1] = val; return a; },
                     jlcxx::arg("this"), jlcxx::arg("val"), jlcxx::arg("i"));
      wrapped.method("_unsafe_setindex!", [](WrappedType * a, const T& val, int i)->WrappedType * { (*a)[i-1] = val; return a; },
                     jlcxx::arg("this"), jlcxx::arg("val"), jlcxx::arg("i"));
      wrapped.method("_push!", [](WrappedType & a, const T& val)->WrappedType & { a.push_back(val); return a; },
                     jlcxx::arg("this"), jlcxx::arg("val"));
      wrapped.method("_push!", [](WrappedType * a, const T& val)->WrappedType * { a->push_back(val); return a; },
                     jlcxx::arg("this"), jlcxx::arg("val"));
      
      wrapped.module().set_override_module(jl_base_module);

      wrapped.method("length", [](WrappedType & a)->int { return a.size(); },
                     jlcxx::arg("this"));
      wrapped.method("length", [](WrappedType * a)->int { return a->size(); },
                     jlcxx::arg("this"));

      wrapped.method("sizehint!", [](WrappedType & a,
                                     int n) -> WrappedType &{
        a.reserve(n);
        return a;
      }, jlcxx::arg("this"), jlcxx::arg("n"));

      wrapped.method("sizehint!", [](WrappedType * a,
                                     int n) -> WrappedType *{
        a->reserve(n);
        return a;
      }, jlcxx::arg("this"), jlcxx::arg("n"));

      wrapped.method("elsize", [](WrappedType & a) -> int{
        return sizeof(T*);
      },  jlcxx::arg("this"));
      
      wrapped.method("elsize", [](WrappedType * a) -> int{
        return sizeof(T*);
      },  jlcxx::arg("this"));
      
      wrapped.module().unset_override_module();
    };
    
    t.apply<ROOT::VecOps::RVec<unsigned long>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned long>>,
            ROOT::VecOps::RVec<long long>,
            ROOT::VecOps::RVec<char>,
            ROOT::VecOps::RVec<short>,
            ROOT::VecOps::RVec<int>,
            ROOT::VecOps::RVec<long>,
            ROOT::VecOps::RVec<unsigned char>,
            ROOT::VecOps::RVec<unsigned short>,
            ROOT::VecOps::RVec<unsigned int>,
            ROOT::VecOps::RVec<float>,
            ROOT::VecOps::RVec<double>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<char>>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned char>>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<short>>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned short>>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<int>>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<unsigned int>>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<long>>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<float>>,
            ROOT::VecOps::RVec<ROOT::VecOps::RVec<double>>>(decl_methods);
  }
  
  void add_methods() const{ /*no-op*/ }
  
private:
std::unique_ptr<jlcxx::TypeWrapper<jlcxx::Parametric<jlcxx::TypeVar<1>>>> type_;
};

std::shared_ptr<Wrapper> newJlROOT_VecOps_RVec(jlcxx::Module& module){
  return std::shared_ptr<Wrapper>(new JlROOT_VecOps_RVec(module));
}


/*
template<typename T>
const T& cxxgetindex(ROOT::VecOps::RVec<T> v, int i){
  return v[i];
}

template<typename T>
const ROOT::VecOps::RVec<T>& cxxsetindex(ROOT::VecOps::RVec<T> v,
                                         const T& val, int i){
  v[i] = val;
  return v;
}

template<typename T>
const ROOT::VecOps::RVec<T>& cxxpush(ROOT::VecOps::RVec<T> v,
                                     const T& val){
  v.push_back(v);
}

template<typename T>
const ROOT::VecOps::RVec<T>& cxxappend(ROOT::VecOps::RVec<T>& v1,
                                       const ROOT::VecOps::RVec<T>& v2){
  v1.append(v2.begin(), v2.end());
  return v1;
}

template<typename T>
const ROOT::VecOps::RVec<T>& cxxsizehint(ROOT::VecOps::RVec<T>& v,
                                         int i){
  v.reserve(i);
  return v;
}

template<typename T>
const int elsize(const ROOT::VecOps::RVec<T>& v){
  return sizeof(T*);
}
*/
