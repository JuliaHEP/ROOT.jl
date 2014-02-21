@constructor :libroot TTree () TTree2
@constructor :libroot TTree (name::Ptr{Uint8}, title::Ptr{Uint8}, splitlevel::Int_t, ) TTree3
@method :libroot TTree Branch Int_t (list::TCollection, bufsize::Int_t, splitlevel::Int_t, name::Ptr{Uint8}, ) Branch1
@method :libroot TTree Branch Int_t (list::TList, bufsize::Int_t, splitlevel::Int_t, ) Branch2
@method :libroot TTree Branch Int_t (folder::Ptr{Uint8}, bufsize::Int_t, splitlevel::Int_t, ) Branch3
@method :libroot TTree Branch TBranch (name::Ptr{Uint8}, address::Ptr{None}, leaflist::Ptr{Uint8}, bufsize::Int_t, ) Branch4
@method :libroot TTree Branch TBranch (name::Ptr{Uint8}, address::Long_t, leaflist::Ptr{Uint8}, bufsize::Int_t, ) Branch6
@method :libroot TTree Branch TBranch (name::Ptr{Uint8}, address::Cint, leaflist::Ptr{Uint8}, bufsize::Int_t, ) Branch7
@method :libroot TTree Branch TBranch (name::Ptr{Uint8}, classname::Ptr{Uint8}, addobj::Ptr{None}, bufsize::Int_t, splitlevel::Int_t, ) Branch8
@method :libroot TTree Fill Int_t () Fill1
@method :libroot TTree GetEntries Long64_t () GetEntries1
@method :libroot TTree GetEntries Long64_t (selection::Ptr{Uint8}, ) GetEntries2
@method :libroot TTree Write Int_t (name::Ptr{Uint8}, option::Int_t, bufsize::Int_t, ) Write1
@method :libroot TTree Write Int_t (name::Ptr{Uint8}, option::Int_t, bufsize::Int_t, ) Write2
