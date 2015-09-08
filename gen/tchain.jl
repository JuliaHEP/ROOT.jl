@constructor LIBROOT TChain () TChain1 ( )
@constructor LIBROOT TChain (name::Ptr{UInt8}, title::Ptr{UInt8}, ) TChain2 (nothing, "",  )
@method LIBROOT TChain AddFile Int_t (name::Ptr{UInt8}, nentries::Long64_t, tname::Ptr{UInt8}, ) AddFile1 (nothing, kBigNumber, "",  )
@method LIBROOT TChain LoadTree Long_t (entry::Long_t, ) LoadTree1 (nothing, )
@method LIBROOT TChain GetTreeNumber Long_t () GetTreeNumber1 ()
@subclass TChain TTree
