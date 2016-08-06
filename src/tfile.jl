using Cxx
cxx"""#include <TFile.h> """

typealias TFilePtr pcpp"""std::unique_ptr<TFile>"""
typealias TFileValue cxxt"""TFile"""


TFile(v1) = icxx"""std::unique_ptr<TFile>(new TFile($v1));"""
TFile(v1, v2) = icxx"""std::unique_ptr<TFile>(new TFile($v1, $v2));"""
TFile(v1, v2, v3) = icxx"""std::unique_ptr<TFile>(new TFile($v1, $v2, $v3));"""
TFile(v1, v2, v3, v4) = icxx"""std::unique_ptr<TFile>(new TFile($v1, $v2, $v3, $v4));"""

export TFile
