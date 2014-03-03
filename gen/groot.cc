#include <TROOT.h>

extern "C" {
    long gROOT_ProcessLine(const char* c) {
        return gROOT->ProcessLine(c); 
    }
}
