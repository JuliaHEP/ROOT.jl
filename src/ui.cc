//#include <julia.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "TROOT.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    TROOT root_obj("root", "root");
    //dummy code to initialize codegen
    gROOT->ProcessLine("int __dummy__=1;");
//    gROOT->ProcessLine("std::cout << \"ROOT initialized\" << std::endl;");

    const std::string libjulia_path(
        std::string(getenv("JULIA_HOME")) + std::string("/usr/lib/libjulia.dylib")
    );
    
    //load julia
    void* handle_julia = dlopen (libjulia_path.c_str(), RTLD_LAZY);
    //load repl
    void* handle = dlopen ("librepl.dylib", RTLD_LAZY);
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
//    gROOT->ProcessLine("std::cout << \"starting julia\" << std::endl;");
    return jl_main(argc, argv);
}
