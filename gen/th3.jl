@method LIBROOT TH3 Fill Int_t (x::Double_t, y::Double_t, z::Double_t, ) Fill1 (nothing, nothing,  )
@method LIBROOT TH3 Fill Int_t (x::Double_t, y::Double_t, z::Double_t, w::Double_t, ) Fill2 (nothing, nothing, nothing,  )
# @method LIBROOT TH3 Fill Int_t (x::Double_t, namey::Ptr{Uint8}, w::Double_t, ) Fill3 (nothing, nothing, nothing,  )
# @method LIBROOT TH3 Fill Int_t (namex::Ptr{Uint8}, y::Double_t, w::Double_t, ) Fill4 (nothing, nothing, nothing,  )
# @method LIBROOT TH3 Fill Int_t (namex::Ptr{Uint8}, namey::Ptr{Uint8}, w::Double_t, ) Fill5 (nothing, nothing, nothing,  )

@method LIBROOT TH3 GetBinLowEdgeX Double_t (n::Cint, ) GetBinLowEdgeX (nothing, )
@method LIBROOT TH3 GetBinLowEdgeY Double_t (n::Cint, ) GetBinLowEdgeY (nothing, )
@method LIBROOT TH3 GetBinLowEdgeZ Double_t (n::Cint, ) GetBinLowEdgeZ (nothing, )

@subclass TH3 TH1
