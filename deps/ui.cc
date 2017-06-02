#include <dlfcn.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include "libgen.h"
#include "julia.h"
#include "uv.h"
#include "TROOT.h"

void init_root();

int main(int argc, char* argv[]) {
  using namespace std;

  gROOT->ProcessLine("TThread::Initialize();");
  // cerr << "INFO: ROOT initialized" << endl;

  void* handle_julia = dlopen(LIBJULIA, RTLD_NOW | RTLD_GLOBAL);
  if (!handle_julia) {
    fputs(dlerror(), stderr);
    cerr << endl;
    cerr << "could not load library: " << LIBJULIA << endl;
    return 1;
  }

  typedef char* (*t_jl_pathname_for_handle)(void *);

  typedef int (*t_julia_init)(JL_IMAGE_SEARCH);

  typedef int (*t_jl_set_ARGS)(int, char**);
  typedef int (*t_jl_eval_string)(const char*);
  typedef int (*t_jl_atexit_hook)(int);
  typedef int (*t_jl_parse_opts)(int *argcp, char ***argvp);

  t_jl_pathname_for_handle jl_pathname_for_handle = (t_jl_pathname_for_handle)dlsym(handle_julia, "jl_pathname_for_handle");
  t_julia_init julia_init = (t_julia_init)dlsym(handle_julia, "julia_init");
  t_jl_set_ARGS jl_set_ARGS = (t_jl_set_ARGS)dlsym(handle_julia, "jl_set_ARGS");
  t_jl_eval_string jl_eval_string = (t_jl_eval_string)dlsym(handle_julia, "jl_eval_string");
  t_jl_atexit_hook jl_atexit_hook = (t_jl_atexit_hook)dlsym(handle_julia, "jl_atexit_hook");
  t_jl_parse_opts jl_parse_opts = (t_jl_parse_opts)dlsym(handle_julia, "jl_parse_opts");

  jl_parse_opts(&argc, (char***)&argv);

  jl_options_t *optsptr = (jl_options_t*)dlsym(handle_julia, "jl_options");
  if (optsptr == 0) {
    cerr << "ERROR: Can't access jl_options" << endl;
    return 1;
  }

  string juliaLibPath(jl_pathname_for_handle(handle_julia));
  // cerr << "DEBUG: juliaLibPath = " << juliaLibPath << endl;
  char *juliaLibDir = dirname((char*)juliaLibPath.c_str());
  // cerr << "DEBUG: libjldir = " << juliaLibDir << endl;
  char* juliaDir = dirname(juliaLibDir);
  // cerr << "DEBUG: juliaDir = " << juliaDir << endl;

  string julia_home;
  if (getenv("JULIA_HOME") == 0) {
    julia_home = string(juliaDir) + "/" +"bin";
    optsptr->julia_home = julia_home.c_str();
  }
  // if (optsptr->julia_home != 0) cerr << "DEBUG: jl_options.julia_home = " << optsptr->julia_home << endl;

  julia_init(optsptr->image_file_specified ? JL_IMAGE_CWD : JL_IMAGE_JULIA_HOME);

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
