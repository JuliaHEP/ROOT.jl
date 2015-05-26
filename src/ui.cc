//#include <julia.h>
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

    const std::string libjulia_path(getenv("JULIA_LIB"));
    
    //load julia
    void* handle_julia = dlopen (libjulia_path.c_str(), RTLD_NOW|RTLD_GLOBAL);
    //load repl
    void* handle = dlopen ("librepl", RTLD_NOW|RTLD_GLOBAL);
    if (!handle || !handle_julia) {
        fputs (dlerror(), stderr);
        std::cerr << "could not load library" << std::endl;
        return 1;
    }
    typedef int (*t_jl_main)(int, char**);
    t_jl_main jl_main = (t_jl_main)dlsym(handle, "main");
    if (!jl_main) {
        fputs (dlerror(), stderr);
        std::cerr << "could not load jl_main" << std::endl;
        return 1;
    }
    gROOT->ProcessLine("std::cout << \"starting julia\" << std::endl;");
    return jl_main(argc, argv);
}
