function process_line(s::ASCIIString)
    ccall((:gROOT_ProcessLine, libroot), Clong, (Ptr{Uint8}, ), s)
end
