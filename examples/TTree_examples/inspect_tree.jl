using ROOT, CxxWrap

function Base.show(io::IO, x::ROOT.EDataType)
    typenames = ("Other", "NoType", "Char", "Short", "Int", "Long", 
	         "Float", "Counter", "Char*", "Double", "Double32", "char",
	         "UChar", "UShort", "UInt", "ULong", "Bits", "Long64", "ULong64",
	         "Bool", "Float16", "Void")
    print(io, typenames[x+2])
end

function Base.show(io::IO, br::ROOT.TBranch)
    cl = Ref{CxxPtr{ROOT.TClass}}()
    etype = Ref{ROOT.EDataType}()
    GetExpectedType(br, cl, etype)
    l = CxxPtr{ROOT.TLeaf}(At(GetListOfLeaves(br), 0))
    slen = GetLenStatic(l)
    brlen = GetLeafCount(l)
    if cl[] != Ptr{Nothing}()
	clname = ClassName(cl[])
	print(io, GetName(br), "::", clname, " ", etype[])
    else
	print(io, GetName(br), "::", etype[])
    end
    if slen > 1
	print(io, "[", slen, "]")
    end
    if brlen != Ptr{Nothing}()
	print(io, "[", GetName(brlen), "]")
    end
end

Base.show(io::IO, br::CxxPtr{ROOT.TBranch}) = Base.show(io, br[])

f = ROOT.TFile!Open("root://eospublic.cern.ch//eos/opendata/cms/Run2016H/DoubleMuon/NANOAOD/UL2016_MiniAODv2_NanoAODv9-v1/2510000/127C2975-1B1C-A046-AABF-62B77E757A86.root")

tree = f["Events"]
brs = GetListOfBranches(tree)
brss = [ CxxPtr{ROOT.TBranch}(At(brs, i-1)) for i in 1:GetEntries(brs) ];

for (ib,b) in enumerate(brss)
    println(ib, ". ", b)
end


