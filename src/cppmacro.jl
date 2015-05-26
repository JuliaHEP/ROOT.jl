function rcpp(expr)
    res = ROOT.gROOT.process_line(expr)
    return res
end

function rcpp_load_as(expr, typ, n)
    res = ROOT.gROOT.process_line(expr)
    return unsafe_load(convert(Ptr{typ}, res), n)
end

function rcpp_raw(expr)
    ROOT.gROOT.process_line(".rawInput 1")
    res = ROOT.gROOT.process_line(expr)
    ROOT.gROOT.process_line(".rawInput 0")
    return res
end

export rcpp, rcpp_load_as, rcpp_raw
