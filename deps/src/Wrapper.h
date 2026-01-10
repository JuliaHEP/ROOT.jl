#ifndef WRAPPER_H
#define WRAPPER_H
#include "jlcxx/jlcxx.hpp"

struct Wrapper{
  Wrapper(jlcxx::Module& module): module_(module) {};
  virtual ~Wrapper() {};
  virtual void add_methods() const = 0;

protected:
  jlcxx::Module& module_;
};
#endif //WRAPPER_H not defined
