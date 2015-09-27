#include <TSVDUnfold.h>
#include <TH1D.h>
#include <TH2D.h>
extern "C" {
TSVDUnfold* TSVDUnfold_TSVDUnfold1(const TH1D *bdat, const TH1D *bini, const TH1D *xini, const TH2D *Adet) {
  return new TSVDUnfold(bdat, bini, xini, Adet);
}

TSVDUnfold* TSVDUnfold_TSVDUnfold2(const TH1D *bdat, TH2D *Bcov, const TH1D *bini, const TH1D *xini, const TH2D *Adet) {
  return new TSVDUnfold(bdat, Bcov, bini, xini, Adet);
}
void TSVDUnfold_SetNormalize1(TSVDUnfold* obj, bool normalize) {
    obj->SetNormalize(normalize);
}

TH1D* TSVDUnfold_Unfold1(TSVDUnfold* obj, Int_t kreg) {
    return obj->Unfold(kreg);
}

TH2D* TSVDUnfold_GetUnfoldCovMatrix1(TSVDUnfold* obj, const TH2D *cov, Int_t ntoys, Int_t seed=1) {
    return obj->GetUnfoldCovMatrix(cov, ntoys, seed);
}

TH2D* TSVDUnfold_GetAdetCovMatrix1(TSVDUnfold* obj, Int_t ntoys, Int_t seed=1) {
    return obj->GetAdetCovMatrix(ntoys, seed);
}

Int_t TSVDUnfold_GetKReg1(TSVDUnfold* obj) {
    return obj->GetKReg();
}

TH1D* TSVDUnfold_GetD1(TSVDUnfold* obj) {
    return obj->GetD();
} 

TH1D* TSVDUnfold_GetSV1(TSVDUnfold* obj) {
    return obj->GetSV();
}

TH2D* TSVDUnfold_GetXtau1(TSVDUnfold* obj) {
    return obj->GetXtau();
} 

TH2D*  TSVDUnfold_GetXinv1(TSVDUnfold* obj) {
    return obj->GetXinv();
}

TH2D*  TSVDUnfold_GetBCov1(TSVDUnfold* obj) {
    return obj->GetBCov();
}

Double_t TSVDUnfold_ComputeChiSquared1(TSVDUnfold* obj, const TH1D *truspec, const TH1D *unfspec) {
    return obj->ComputeChiSquared(*truspec, *unfspec);
}

}
