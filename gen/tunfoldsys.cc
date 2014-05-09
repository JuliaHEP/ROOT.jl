//c++ `root-config --cflags --libs` -shared -fPIC gen/tunfoldsys.cc -o gen/tunfoldsys
#include <TUnfoldSys.h>
extern "C" {
TUnfoldSys* TUnfoldSys_TUnfoldSys1(const TH2* hist_A,  TUnfold::EHistMap histmap,  TUnfold::ERegMode regmode,  TUnfold::EConstraint constraint) {
  return new TUnfoldSys(hist_A, histmap, regmode, constraint);
}
 Int_t TUnfoldSys_SetInput1(TUnfoldSys* __obj, const TH1* hist_y,  Double_t scaleBias,  Double_t oneOverZeroError) {
  return __obj->SetInput(hist_y, scaleBias, oneOverZeroError);
}
} //extern C
