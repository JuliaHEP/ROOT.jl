@constructor LIBROOT TH2D () TH2D1 ( )
@constructor LIBROOT TH2D (name::Ptr{UInt8}, title::Ptr{UInt8}, nbinsx::Int_t, xlow::Double_t, xup::Double_t, nbinsy::Int_t, ylow::Double_t, yup::Double_t, ) TH2D2 (nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing,  )
@constructor LIBROOT TH2D (name::Ptr{UInt8}, title::Ptr{UInt8}, nbinsx::Int_t, xbins::Ptr{Double_t}, nbinsy::Int_t, ylow::Double_t, yup::Double_t, ) TH2D3 (nothing, nothing, nothing, nothing, nothing, nothing, nothing,  )
@constructor LIBROOT TH2D (name::Ptr{UInt8}, title::Ptr{UInt8}, nbinsx::Int_t, xlow::Double_t, xup::Double_t, nbinsy::Int_t, ybins::Ptr{Double_t}, ) TH2D4 (nothing, nothing, nothing, nothing, nothing, nothing, nothing,  )
@constructor LIBROOT TH2D (name::Ptr{UInt8}, title::Ptr{UInt8}, nbinsx::Int_t, xbins::Ptr{Double_t}, nbinsy::Int_t, ybins::Ptr{Double_t}, ) TH2D5 (nothing, nothing, nothing, nothing, nothing, nothing,  )
@constructor LIBROOT TH2D (name::Ptr{UInt8}, title::Ptr{UInt8}, nbinsx::Int_t, xbins::Ptr{Float_t}, nbinsy::Int_t, ybins::Ptr{Float_t}, ) TH2D6 (nothing, nothing, nothing, nothing, nothing, nothing,  )

@subclass TH2D TH2
@subclass TH2D TArrayD
