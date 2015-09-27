module gROOT
import ..LIBROOT

function process_line(s::ASCIIString)
    ccall((:gROOT_ProcessLine, LIBROOT), Clong, (Ptr{UInt8}, ), s)
end

function set_batch(b::Bool)
    ccall((:gROOT_SetBatch, LIBROOT), Void, (Bool, ), b)
end

end
