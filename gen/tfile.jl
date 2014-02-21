@constructor :libroot TFile () TFile1
@constructor :libroot TFile (fname::Ptr{Uint8}, option::Ptr{Option_t}, ftitle::Ptr{Uint8}, compress::Int_t, ) TFile2
@method :libroot TFile Close None (option::Ptr{Option_t}, ) Close1
@method :libroot TFile Write Int_t (name::Ptr{Uint8}, opt::Int_t, bufsiz::Int_t, ) Write1
@method :libroot TFile Write Int_t (name::Ptr{Uint8}, opt::Int_t, bufsiz::Int_t, ) Write2
