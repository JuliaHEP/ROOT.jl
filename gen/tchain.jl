@constructor LIBROOT TChain () TChain1 ( )
@constructor LIBROOT TChain (name::Ptr{Uint8}, title::Ptr{Uint8}, ) TChain2 (nothing, "",  )
@method LIBROOT TChain AddFile Int_t (name::Ptr{Uint8}, nentries::Long64_t, tname::Ptr{Uint8}, ) AddFile1 (nothing, kBigNumber, "",  )
@method LIBROOT TChain LoadTree Long_t (entry::Long_t, ) LoadTree1 (nothing, )
@method LIBROOT TChain GetEntries Long64_t () GetEntries1 ( )
@method LIBROOT TChain GetEntries Long64_t (selection::Ptr{Uint8}, ) GetEntries2 (nothing,  )
@method LIBROOT TChain GetTreeNumber Int_t () GetTreeNumber1 ( )
@subclass TChain TTree
