//#include <julia.h>
#include "deps.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "TROOT.h"
#include <iostream>
#include <string>
#include <cassert>

int main(int argc, char *argv[])
{
    //dummy code to initialize codegen
    gROOT->ProcessLine("int __dummy__=1;");
    gROOT->ProcessLine("std::cout << \"ROOT: ROOT initialized\" << std::endl;");

    //const std::string libjulia_path(getenv("JULIA_LIB"));
    //const std::string libjuliarepl_path(getenv("JULIAREPL_LIB"));
    
    //load julia
    void* handle_julia = dlopen (LIBJULIA, RTLD_NOW|RTLD_GLOBAL);
    if (!handle_julia) {
        fputs (dlerror(), stderr);
        std::cerr << std::endl;
        std::cerr << "could not load library: julia" << std::endl;
        return 1;
    }
    //load repl
    void* handle_repl = dlopen (LIBREPL, RTLD_NOW|RTLD_GLOBAL);
    if (!handle_repl) {
        fputs (dlerror(), stderr);
        std::cerr << std::endl;
        std::cerr << "could not load library: repl" << std::endl;
        return 1;
    }
    typedef int (*t_jl_main)(int, char**);
    t_jl_main jl_main = (t_jl_main)dlsym(handle_repl, "main");
    if (!jl_main) {
        fputs (dlerror(), stderr);
        std::cerr << "could not load jl_main" << std::endl;
        return 1;
    }
    gROOT->ProcessLine("std::cout << \"ROOT: starting julia\" << std::endl;");
   
    int nchar = 0;
    for (int i=0; i<argc; i++) {
        nchar += strlen(argv[i])+1;
    }
    nchar += strlen("-H")+1;
    nchar += strlen(ROOTJL_HOME)+1;
    nchar += strlen("-J")+1;
    nchar += strlen(SYSIMG)+1;
    //std::cout << "argc=" << argc << std::endl;

    assert(nchar < 5000);
    char newv[5000];
    char **newvals = (char**)malloc((argc+4) * sizeof(char*));
    char* idx = newv;
    idx = strcpy(newv, argv[0]);
    newvals[0] = idx;
    int prevlen = strlen(argv[0])+1;

    int ic = 1;
    for (auto& v : {"-H", ROOTJL_HOME, "-J", SYSIMG}) {
        idx = strcpy(idx + prevlen, v);
        newvals[ic] = idx;
        prevlen = strlen(v) + 1;
        ic += 1;
    }

    for (int i=1; i<argc; i++) {
        idx = strcpy(idx + prevlen, argv[i]);
        prevlen = strlen(argv[i]) + 1;
        newvals[ic+i-1] = idx;
    }

    // for (int i=0; i<argc+4; i++) {
    //     std::cout << newvals[i] << std::endl;
    // } 

    return jl_main(argc+4, newvals);
}
