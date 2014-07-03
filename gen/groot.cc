//manually written
#include <TROOT.h>

extern "C" {
    void* gROOT_ProcessLine(const char* c) {
        return (void*)(gROOT->ProcessLine(c)); 
    }
    
    void gROOT_SetBatch(bool b) {
        gROOT->SetBatch(b); 
    }
}
