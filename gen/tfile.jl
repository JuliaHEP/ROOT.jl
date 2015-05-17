@constructor LIBROOT TFile () TFile1 ( )
@constructor LIBROOT TFile (fname::Ptr{UInt8}, option::Ptr{Option_t}, ftitle::Ptr{UInt8}, compress::Int_t, ) TFile2 (nothing, "", "", 1,  )
@method LIBROOT TFile Close Void (option::Ptr{Option_t}, ) Close1 ("",  )
@method LIBROOT TFile Write Int_t (name::Ptr{UInt8}, opt::Int_t, bufsiz::Int_t, ) Write1 (0, 0, 0,  )
@method LIBROOT TFile Write Int_t (name::Ptr{UInt8}, opt::Int_t, bufsiz::Int_t, ) Write2 (0, 0, 0,  )
@method LIBROOT TFile Open Ptr{TFile} (name::Ptr{UInt8}, option::Ptr{Option_t}, ftitle::Ptr{UInt8}, compress::Int_t, netopt::Int_t, ) Open1 (nothing, "", "", 1, 0,  )
@subclass TFile TDirectoryFile
