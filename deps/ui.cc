#include <dlfcn.h>
#include <stdio.h>
#include <iostream>
#include "julia.h"
#include "uv.h"
#include "TROOT.h"

void init_root();

int main(int argc, char* argv[]) {
  gROOT->ProcessLine("TThread::Initialize();");
  std::cerr << "INFO: ROOT initialized" << std::endl;

  void* handle_julia = dlopen(LIBJULIA, RTLD_NOW | RTLD_GLOBAL);
  if (!handle_julia) {
    fputs(dlerror(), stderr);
    std::cerr << std::endl;
    std::cerr << "could not load library: " << LIBJULIA << std::endl;
    return 1;
  }
  typedef int (*t_jl_init)(const char *);
  typedef int (*t_jl_set_ARGS)(int, char**);
  typedef int (*t_jl_eval_string)(const char*);
  typedef int (*t_jl_atexit_hook)(int);
  //typedef int (*t_jl_load)(const char*);
  typedef int (*t_jl_parse_opts)(int *argcp, char ***argvp);
  t_jl_init jl_init = (t_jl_init)dlsym(handle_julia, "jl_init");
  t_jl_set_ARGS jl_set_ARGS = (t_jl_set_ARGS)dlsym(handle_julia, "jl_set_ARGS");
  t_jl_eval_string jl_eval_string = (t_jl_eval_string)dlsym(handle_julia, "jl_eval_string");
  t_jl_atexit_hook jl_atexit_hook = (t_jl_atexit_hook)dlsym(handle_julia, "jl_atexit_hook");
  //t_jl_load jl_load = (t_jl_load)dlsym(handle_julia, "jl_load");
  t_jl_parse_opts jl_parse_opts = (t_jl_parse_opts)dlsym(handle_julia, "jl_parse_opts");
  
  jl_parse_opts(&argc, (char***)&argv);
  jl_init(NULL);
  jl_set_ARGS(argc, argv);
  int ret = 0;
  
  jl_eval_string("Base._start()");
  //if (argc > 0) {
  //    if (strcmp(argv[0], "-")) {
  //        ret = jl_load(argv[0]);
  //    }
  //}

  jl_atexit_hook(0);
  return ret;
}
