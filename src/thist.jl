using Cxx
cxx"""#include <TH1D.h> """
cxx"""#include <memory>"""

typealias TH1DUPtr cxxt"""std::unique_ptr<TH1D>"""
typealias TH1DPtr pcpp"""TH1D"""
typealias TH1DValue cxxt"""TH1D"""

TH1D_uniq(args...) = icxx"""std::unique_ptr<TH1D>(new TH1D($(args[1]), $(args[2]), $(args[3]), $(args[4]), $(args[5])));"""
TH1D_shared(args...) = icxx"""std::shared_ptr<TH1D>(new TH1D($(args[1]), $(args[2]), $(args[3]), $(args[4]), $(args[5])));"""
TH1D_new(args...) = icxx"""new TH1D($(args[1]), $(args[2]), $(args[3]), $(args[4]), $(args[5]));"""

#creation on stack may be problematic, because assignment copies
#GC may not guarantee non-moving
TH1D_stack(args...) = icxx"""TH1D($(args[1]), $(args[2]), $(args[3]), $(args[4]), $(args[5]));"""


export TH1D_stack, TH1D_new, TH1D_uniq, TH1DUPtr, TH1DPtr, TH1DValue
