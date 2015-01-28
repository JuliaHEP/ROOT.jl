@constructor LIBROOT TBranch () TBranch1 ( )
@constructor LIBROOT TBranch (tree::Ptr{TTree}, name::Ptr{Uint8}, address::Ptr{None}, leaflist::Ptr{Uint8}, basketsize::Int_t, compress::Int_t, ) TBranch2 (nothing, nothing, nothing, nothing, 32000, -1,  )
@constructor LIBROOT TBranch (parent::Ptr{TBranch}, name::Ptr{Uint8}, address::Ptr{None}, leaflist::Ptr{Uint8}, basketsize::Int_t, compress::Int_t, ) TBranch3 (nothing, nothing, nothing, nothing, 32000, -1,  )
@method LIBROOT TBranch GetClassName Ptr{Uint8} () GetClassName1 ( )
@method LIBROOT TBranch GetListOfLeaves Ptr{TObjArray} () GetListOfLeaves1 ( )
@method LIBROOT TBranch SetAddress None (add::Ptr{None}, ) SetAddress1 (nothing,  )
@method LIBROOT TBranch GetEntry Int_t (entry::Long_t, ) GetEntry1 (nothing,  )
@subclass TBranch TNamed
@subclass TBranch TAttFill
