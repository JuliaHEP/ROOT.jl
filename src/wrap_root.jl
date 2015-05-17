using Clang.cindex

ROOTSYS = ENV["ROOTSYS"]

function wrap_root_file(
    fname::ASCIIString, class::ASCIIString, ofname::ASCIIString,
    funcs::Vector{Symbol},
    exclude::Vector{Symbol}=Symbol[]
    )
    topcu = cindex.parse_header(
        "$ROOTSYS/include/$fname";
        cplusplus = true,
        args=["-I$ROOTSYS/include", "-I/usr//include/c++/4.2.1/"]
    )

    cls = cindex.search(topcu, class)

    function to_wrap(s::Symbol)
        return s in funcs
    end

    of = open("$(ofname).cc", "w")
    ofjl = open("$(ofname).jl", "w")
    println(of, "//c++ `root-config --cflags --libs` -shared -fPIC $(ofname).cc -o $(ofname)")
    println(of, "#include <$fname>")
    println(of, "extern \"C\" {")
    for c in cls
        length(children(c)) == 0 && continue
        #println(name(c))

        MethodCount = Dict{Symbol, Int}()
        for decl in children(c)
            const declname = symbol(strip(spelling(decl)))
            wrapped = Any[]
            if to_wrap(declname) && (
                isa(decl, cindex.CXXMethod) ||
                isa(decl, cindex.Constructor) ||
                isa(decl, cindex.EnumDecl)
                )

                #check for public
                Clang.cindex.getCXXAccessSpecifier(decl)==1 || continue

                id = (MethodCount[declname] = get(MethodCount, declname, 0) + 1)
                if symbol("$(declname)$(id)") in exclude
                    println("excluding $(name(c))::$(declname)::$(id)")
                    continue
                end
                Clang.wrap_cpp.wrap(of, decl, id)
                Clang.wrap_cpp.wrapjl(ofjl, "LIBROOT", decl, id)
            end
        end
        for sup in Clang.wrap_cpp.class_supers(c)
            println(ofjl, "@subclass $(spelling(c)) $(sup.text)")
        end
    end
    println(of, "} //extern C")
    close(of)
    close(ofjl)
end

mkpath("gen")
wrap_root_file("TObject.h", "TObject", "gen/tobject", [:Print, :Write, :GetName, :GetTitle, :ClassName])

wrap_root_file("TDirectory.h", "TDirectory", "gen/tdirectory",
    [:Get, :Close, :TDirectory, :GetListOfKeys, :Cd, :mkdir,
    :GetList
    ]
)
wrap_root_file("TFile.h", "TFile", "gen/tfile",
    [:TFile, :Close, :Get, :Write, :Open],
    [:Open2]
)
wrap_root_file("TKey.h", "TKey", "gen/tkey", [:GetName, :ReadOb, :GetClassName])
wrap_root_file("TList.h", "TListIter", "gen/tlistiter", [:TListIter, :Next, :Reset])

wrap_root_file(
    "TTree.h", "TTree", "gen/ttree",
    [:TTree, :Fill, :Branch, :GetEntries, :Write, :GetListOfBranches, :GetEntry, :GetEvent,
    :AddBranchToCache, :SetBranchStatus, :GetV1, :Draw, :GetBranch, :SetCacheSize,
    :SetBranchAddress,
    ],
    [:Branch5, :SetBranchAddress2, :SetBranchAddress3]
)

wrap_root_file(
    "TChain.h", "TChain", "gen/tchain",
    [:TChain, :AddFile]
)

wrap_root_file("TBranch.h", "TBranch", "gen/tbranch",
    [:TBranch, :Write, :SetAddress, :GetClassName, :GetListOfLeaves]
)
wrap_root_file("TLeaf.h", "TLeaf", "gen/tleaf",
    [:GetTypeName]
)


wrap_root_file("TH1D.h", "TH1D", "gen/th1d", [:TH1D])
wrap_root_file(
    "TH1.h", "TH1", "gen/th1",
    [:TH1, :Fill, :Write,
    :Integral,
    :GetEntries, :SetEntries,
    :GetBinContent, :GetBinError, :GetNbinsX, :GetNbinsY,
    :GetBinLowEdge, :GetBinWidth,
    :SetBinContent, :SetBinError,
    :SetDirectory, :Chi2Test,
    :Rebin, :GetRandom
    ]
)

wrap_root_file(
    "TH2.h", "TH2", "gen/th2",
    [
        :TH2, :Fill,
        :GetBinContent, :GetBinError, :GetNbinsX, :GetNbinsY, :GetBinLowEdge, :GetBinWidth,
        :SetBinContent, :SetBinError
    ]
)
wrap_root_file("TH2D.h", "TH2D", "gen/th2d",
    [
    :TH2D,
    :GetNbinsX, :GetNbinsY
])

wrap_root_file(
    "TH3.h", "TH3", "gen/th3",
    [
        :TH3, :Fill,
        :GetBinContent, :GetBinError, :GetNbinsX, :GetNbinsY, :GetNbinsZ, :GetBinLowEdge, :GetBinWidth,
        :SetBinContent, :SetBinError
    ]
)
wrap_root_file("TH3D.h", "TH3D", "gen/th3d",
    [
    :TH3D,
    :GetNbinsX, :GetNbinsY, :GetNbinsZ
])

wrap_root_file("TArrayD.h", "TArrayD", "gen/tarrayd", [:TArrayD, :GetAt, :SetAt])
wrap_root_file("TArray.h", "TArray", "gen/tarray", Symbol[])

wrap_root_file("TCollection.h", "TCollection", "gen/tcollection", [:TCollection, :GetEntries])
wrap_root_file("TList.h", "TList", "gen/tlist", [:TList, :At, :After], [:TList2])
wrap_root_file("TObjArray.h", "TObjArray", "gen/tobjarray", [:TObjArray])
wrap_root_file("TSeqCollection.h", "TSeqCollection", "gen/tseqcollection", [:TSeqCollection, :At])

#wrap_root_file("TUnfold.h", "TUnfold", "gen/tunfold", [
#    :TUnfold, :DoUnfold, :SetInput,
#    :GetOutput, :GetBias, :GetEmatrix,
#    :EHistMap, :ERegMode, :EConstraint
#])

#wrap_root_file("TUnfoldSys.h", "TUnfoldSys", "gen/tunfoldsys", [:TUnfoldSys, :DoUnfold, :SetInput, :GetOutput, :GetBias, :GetEmatrix])
