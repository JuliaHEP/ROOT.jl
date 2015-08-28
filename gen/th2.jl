@method LIBROOT TH2 Fill Int_t (x::Double_t, y::Double_t, ) Fill1 (nothing, nothing,  )
@method LIBROOT TH2 Fill Int_t (x::Double_t, y::Double_t, w::Double_t, ) Fill2 (nothing, nothing, nothing,  )
@method LIBROOT TH2 Fill Int_t (x::Double_t, namey::Ptr{UInt8}, w::Double_t, ) Fill3 (nothing, nothing, nothing,  )
@method LIBROOT TH2 Fill Int_t (namex::Ptr{UInt8}, y::Double_t, w::Double_t, ) Fill4 (nothing, nothing, nothing,  )
@method LIBROOT TH2 Fill Int_t (namex::Ptr{UInt8}, namey::Ptr{UInt8}, w::Double_t, ) Fill5 (nothing, nothing, nothing,  )

@method LIBROOT TH2 GetBinLowEdgeY Double_t (n::Cint, ) GetBinLowEdgeY (nothing, )

@subclass TH2 TH1
