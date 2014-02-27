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
			    Clang.wt.wrapjl(ofjl, ":libroot",decl, id)
			end 
		end
	end
	println(of, "} //extern C")
	close(of)
	close(ofjl)
end

mkpath("gen")
wrap_root_file("TObject.h", "TObject", "gen/tobject", [:Print, :Write, :GetName, :GetTitle, :ClassName])

wrap_root_file("TDirectory.h", "TDirectory", "gen/tdirectory", [:Get, :Close, :TDirectory, :GetListOfKeys])
wrap_root_file("TFile.h", "TFile", "gen/tfile", [:TFile, :Close, :Get, :Write])
wrap_root_file("TKey.h", "TKey", "gen/tkey", [:GetName, :ReadObj])

wrap_root_file("TTree.h", "TTree", "gen/ttree", [:TTree, :Fill, :Branch, :GetEntries, :Write, :GetListOfBranches], [:Branch5])
wrap_root_file("TBranch.h", "TBranch", "gen/tbranch", [:TBranch, :Write])

wrap_root_file("TH1D.h", "TH1D", "gen/th1d", [:TH1D])
wrap_root_file("TH1.h", "TH1", "gen/th1", [:TH1, :Fill, :Write, :Integral, :GetEntries, :GetBinContent, :GetBinError, :GetNbinsX])

wrap_root_file("TCollection.h", "TCollection", "gen/tcollection", [:TCollection, :GetEntries])
wrap_root_file("TList.h", "TList", "gen/tlist", [:TList, :At], [:TList2])	
wrap_root_file("TObjArray.h", "TObjArray", "gen/tobjarray", [:TObjArray])
wrap_root_file("TSeqCollection.h", "TSeqCollection", "gen/tseqcollection", [:TSeqCollection, :At])
