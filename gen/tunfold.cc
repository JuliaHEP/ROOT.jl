//c++ `root-config --cflags --libs` -shared -fPIC gen/tunfold.cc -o gen/tunfold
#include <TUnfold.h>
extern "C" {
TUnfold* TUnfold_TUnfold1(const TH2* hist_A,  TUnfold::EHistMap histmap,  TUnfold::ERegMode regmode,  TUnfold::EConstraint constraint) {
  return new TUnfold(hist_A, histmap, regmode, constraint);
}
 Double_t TUnfold_DoUnfold1(TUnfold* __obj,  Double_t tau, const TH1* hist_y,  Double_t scaleBias) {
  return __obj->DoUnfold(tau, hist_y, scaleBias);
}
 Int_t TUnfold_SetInput1(TUnfold* __obj, const TH1* hist_y,  Double_t scaleBias,  Double_t oneOverZeroError) {
  return __obj->SetInput(hist_y, scaleBias, oneOverZeroError);
}
 Double_t TUnfold_DoUnfold2(TUnfold* __obj,  Double_t tau) {
  return __obj->DoUnfold(tau);
}
 TH1D* TUnfold_GetOutput1(TUnfold* __obj, const char* name, const char* title,  Double_t x0,  Double_t x1) {
  return __obj->GetOutput(name, title, x0, x1);
}
 TH1D* TUnfold_GetBias1(TUnfold* __obj, const char* name, const char* title,  Double_t x0,  Double_t x1) {
  return __obj->GetBias(name, title, x0, x1);
}
 TH2D* TUnfold_GetEmatrix1(TUnfold* __obj, const char* name, const char* title,  Double_t x0,  Double_t x1) {
  return __obj->GetEmatrix(name, title, x0, x1);
}
 void TUnfold_GetOutput2(TUnfold* __obj,  TH1* output, const Int_t* binMap) {
  return __obj->GetOutput(output, binMap);
}
 void TUnfold_GetEmatrix2(TUnfold* __obj,  TH2* ematrix, const Int_t* binMap) {
  return __obj->GetEmatrix(ematrix, binMap);
}
} //extern C
