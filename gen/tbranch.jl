@constructor LIBROOT TBranch () TBranch1 ( )
@constructor LIBROOT TBranch (tree::Ptr{TTree}, name::Ptr{UInt8}, address::Ptr{Void}, leaflist::Ptr{UInt8}, basketsize::Int_t, compress::Int_t, ) TBranch2 (nothing, nothing, nothing, nothing, 32000, -1,  )
@constructor LIBROOT TBranch (parent::Ptr{TBranch}, name::Ptr{UInt8}, address::Ptr{Void}, leaflist::Ptr{UInt8}, basketsize::Int_t, compress::Int_t, ) TBranch3 (nothing, nothing, nothing, nothing, 32000, -1,  )
@method LIBROOT TBranch GetClassName Ptr{UInt8} () GetClassName1 ( )
@method LIBROOT TBranch GetListOfLeaves Ptr{TObjArray} () GetListOfLeaves1 ( )
@method LIBROOT TBranch SetAddress Void (add::Ptr{Void}, ) SetAddress1 (nothing,  )
@subclass TBranch TNamed
@subclass TBranch TAttFill
