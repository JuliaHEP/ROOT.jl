@constructor LIBROOT TH1D () TH1D1 ( )
@constructor LIBROOT TH1D (name::Ptr{Uint8}, title::Ptr{Uint8}, nbinsx::Int_t, xlow::Double_t, xup::Double_t, ) TH1D2 (nothing, nothing, nothing, nothing, nothing,  )
@constructor LIBROOT TH1D (name::Ptr{Uint8}, title::Ptr{Uint8}, nbinsx::Int_t, xbins::Ptr{Float_t}, ) TH1D3 (nothing, nothing, nothing, nothing,  )
@constructor LIBROOT TH1D (name::Ptr{Uint8}, title::Ptr{Uint8}, nbinsx::Int_t, xbins::Ptr{Double_t}, ) TH1D4 (nothing, nothing, nothing, nothing,  )
@method LIBROOT TH1D GetRMS Float64 (i::Int_t, ) GetRMS (1,  )
@method LIBROOT TH1D GetMean Float64 (i::Int_t, ) GetMean (1,  )
@subclass TH1D TH1
@subclass TH1D TArrayD
