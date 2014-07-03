module gROOT

function process_line(s::ASCIIString)
    ccall((:gROOT_ProcessLine, :libroot), Clong, (Ptr{Uint8}, ), s)
end

function set_batch(b::Bool)
    ccall((:gROOT_SetBatch, :libroot), Void, (Bool, ), b)
end

end
