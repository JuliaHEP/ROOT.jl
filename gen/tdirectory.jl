@constructor LIBROOT TDirectory () TDirectory1 ( )
@constructor LIBROOT TDirectory (name::Ptr{Uint8}, title::Ptr{Uint8}, option::Ptr{Option_t}, motherDir::Ptr{TDirectory}, ) TDirectory2 (nothing, nothing, "", 0,  )
@method LIBROOT TDirectory Close None (option::Ptr{Option_t}, ) Close1 ("",  )
@method LIBROOT TDirectory Get Ptr{TObject} (namecycle::Ptr{Uint8}, ) Get1 (nothing,  )
@method LIBROOT TDirectory GetList Ptr{TList} () GetList1 ( )
@method LIBROOT TDirectory GetListOfKeys Ptr{TList} () GetListOfKeys1 ( )
@method LIBROOT TDirectory mkdir Ptr{TDirectory} (name::Ptr{Uint8}, title::Ptr{Uint8}, ) mkdir1 (nothing, "",  )
@method LIBROOT TDirectory Cd Bool_t (path::Ptr{Uint8}, ) Cd1 (nothing,  )
@subclass TDirectory TNamed
