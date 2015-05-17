@constructor LIBROOT TDirectory () TDirectory1 ( )
@constructor LIBROOT TDirectory (name::Ptr{UInt8}, title::Ptr{UInt8}, option::Ptr{Option_t}, motherDir::Ptr{TDirectory}, ) TDirectory2 (nothing, nothing, "", 0,  )
@method LIBROOT TDirectory Close Void (option::Ptr{Option_t}, ) Close1 ("",  )
@method LIBROOT TDirectory Get Ptr{TObject} (namecycle::Ptr{UInt8}, ) Get1 (nothing,  )
@method LIBROOT TDirectory GetList Ptr{TList} () GetList1 ( )
@method LIBROOT TDirectory GetListOfKeys Ptr{TList} () GetListOfKeys1 ( )
@method LIBROOT TDirectory mkdir Ptr{TDirectory} (name::Ptr{UInt8}, title::Ptr{UInt8}, ) mkdir1 (nothing, "",  )
@method LIBROOT TDirectory Cd Bool_t (path::Ptr{UInt8}, ) Cd1 (nothing,  )
@subclass TDirectory TNamed
