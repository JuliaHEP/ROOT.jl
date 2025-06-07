#include "Extra.h"
#include "TROOT.h"
#include "TVirtualPad.h"

void updateAllCanvas(){
  //copied from TCling::UpdateAllCanvas()
  TIter next(gROOT->GetListOfCanvases());
  TVirtualPad* canvas;
  while ((canvas = (TVirtualPad*)next())) {
      canvas->Update();
  }
}
  
