using Clang.cindex

ROOTSYS="/Users/joosep/Documents/root/"

function wrap_root_file(
	fname::ASCIIString, class::ASCIIString, ofname::ASCIIString,
	funcs::Vector{Symbol},
	exclude::Vector{Symbol}=Symbol[]
	)
	topcu = cindex.parse_header(
		"$ROOTSYS/include/$fname";
		cplusplus = true,
		args=["-I$ROOTSYS/include"]
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
			if to_wrap(declname) && ( (isa(decl, cindex.CXXMethod)) || isa(decl, cindex.Constructor))

				#check for public
				Clang.cindex.getCXXAccessSpecifier(decl)==1 || continue

			    id = (MethodCount[declname] = get(MethodCount, declname, 0) + 1)
			    if symbol("$(declname)$(id)") in exclude
			    	println("excluding $(name(c))::$(declname)::$(id)")
			    	continue
			    end
			    Clang.wt.wrap(of, decl, id)
			    Clang.wt.wrapjl(ofjl, ":libroot", decl, id)
			end 
		end
        for sup in Clang.wt.class_supers(c)
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
    [:Get, :Close, :TDirectory, :GetListOfKeys, :Cd, :mkdir]
)
wrap_root_file("TFile.h", "TFile", "gen/tfile",
    [:TFile, :Close, :Get, :Write]
)
wrap_root_file("TKey.h", "TKey", "gen/tkey", [:GetName, :ReadObj])

wrap_root_file(
	"TTree.h", "TTree", "gen/ttree",
	[:TTree, :Fill, :Branch, :GetEntries, :Write, :GetListOfBranches, :GetEntry,
	:AddBranchToCache, :SetBranchStatus, :GetV1, :Draw, :GetBranch, :SetCacheSize],
	[:Branch5]
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
	:GetEntries, :GetBinContent, :GetBinError, :GetNbinsX, :GetBinLowEdge, :GetBinWidth,
    :SetBinContent, :SetBinError,
    :SetDirectory
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
wrap_root_file("TH2D.h", "TH2D", "gen/th2d", [:TH2D])
wrap_root_file("TArrayD.h", "TArrayD", "gen/tarrayd", [:TArrayD, :GetAt, :SetAt])
wrap_root_file("TArray.h", "TArray", "gen/tarray", Symbol[])

wrap_root_file("TCollection.h", "TCollection", "gen/tcollection", [:TCollection, :GetEntries])
wrap_root_file("TList.h", "TList", "gen/tlist", [:TList, :At], [:TList2])	
wrap_root_file("TObjArray.h", "TObjArray", "gen/tobjarray", [:TObjArray])
wrap_root_file("TSeqCollection.h", "TSeqCollection", "gen/tseqcollection", [:TSeqCollection, :At])
