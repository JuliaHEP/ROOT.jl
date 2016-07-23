#include <dlfcn.h>
#include <stdio.h>
#include <iostream>
#include "TROOT.h"

void init_root();

int main(int argc, char* argv[]) {
  gROOT->ProcessLine("int __dummy__=1;");
  gROOT->ProcessLine("std::cout << \"ROOT: ROOT initialized\" << std::endl;");

  void* handle_julia = dlopen(LIBJULIAREPL, RTLD_NOW | RTLD_GLOBAL);
  if (!handle_julia) {
    fputs(dlerror(), stderr);
    std::cerr << std::endl;
    std::cerr << "could not load library: " << LIBJULIAREPL << std::endl;
    return 1;
  }
  typedef int (*t_jl_main)(int, char**);
  t_jl_main jl_main = (t_jl_main)dlsym(handle_julia, "main");
  if (!jl_main) {
    fputs(dlerror(), stderr);
    std::cerr << std::endl;
    std::cerr << "could not load main from librepl" << std::endl;
    return 1;
  }
  return jl_main(argc, argv);
}
