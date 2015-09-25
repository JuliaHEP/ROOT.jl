//#include <julia.h>
#include "deps.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "TROOT.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    //dummy code to initialize codegen
    gROOT->ProcessLine("int __dummy__=1;");
    gROOT->ProcessLine("std::cout << \"ROOT initialized\" << std::endl;");

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
    gROOT->ProcessLine("std::cout << \"starting julia\" << std::endl;");
    return jl_main(argc, argv);
}
