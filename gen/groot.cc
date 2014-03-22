#include <TROOT.h>

extern "C" {
    void* gROOT_ProcessLine(const char* c) {
        return (void*)(gROOT->ProcessLine(c)); 
    }
}
