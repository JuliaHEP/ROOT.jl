module ROOT

"ROOTSYS" in keys(ENV) || error("ROOTSYS not defined, call `source /path/to/root/thisroot.sh`")
import Base.length, Base.getindex

#abstract type that wraps a ROOT object through an opaque pointer
#should implement root_pointer(ROOTObject)::Ptr{Void},
#which returns pointer to ROOT object on heaps
abstract ROOTObject

#custom wrappers

#list of all T-objects that are replaced by Ptr{Void}
const ROOT_OBJECTS = Symbol[]

#define a ROOT TObject type, needed for correct dispatch
macro root_object(name)
	push!(ROOT_OBJECTS, name)
	eval(quote
		immutable $name <: ROOTObject
			p::Ptr{Void}
		end
		#$name(p::Ptr{Void}) = $name(p)
		root_pointer(x::$name) = x.p
	end)
end

macro subclass(child, parent)
end

root_cast{T <: ROOTObject, K <: ROOTObject}(to::Type{K}, o::T) =
	to(root_pointer(o))

@root_object(TObject)

@root_object(TFile)
@root_object(TDirectory)

@root_object(TCollection)
@root_object(TSeqCollection)
@root_object(TObjArray)
@root_object(TList)
@root_object(TKey)

@root_object(TBranch)
@root_object(TLeaf)
@root_object(TTree)

@root_object(TH1)
@root_object(TH1D)

@root_object(TH2)
@root_object(TH2D)

typealias Option_t Uint8
typealias Int_t Cint
typealias UInt_t Cuint
typealias Long_t Clong
typealias Long64_t Clong
typealias Double_t Cdouble
typealias Float_t Cfloat
typealias Bool_t Bool
const kFALSE = false
const kTRUE = true

const type_replacement = {
	:Option_t	=>	:Uint8,
	:Int_t		=>	:Cint,
	:UInt_t 	=>	:Cuint,
	:Long_t 	=> 	:Clong,
	:Long64_t 	=> 	:Clong,
	:Double_t 	=> 	:Cdouble,
	:Float_t 	=> 	:Cfloat,
	:Bool_t 	=> 	:Bool
}

#replaces argument list expressions from ROOT->Julia
#input:
#	:(a1::Ptr{Uint8}, ...)
#outputs:
#	:(a1, ...), => for ccall values
#	:(Ptr{Uint8}, ...), => for ccall types
#	:(a1::ASCIIString, ...), => for julia function arguments
function argument_replace(args::Expr)

	#println(args.args)

	#argument values
	avals = Expr(:tuple)
	#argument types
	aargs = Expr(:tuple)
	#value::Type with possible julia-side replacements
	jlargs = Expr(:tuple)

	#loop over argument list
	for a in args.args

		#must be typed argument
		(isa(a, Expr) && a.head == symbol("::")) || error("$a")

		#name, type
		n = a.args[1]
		t = a.args[2]
        #typeof(t) <: Symbol && println("replacing $n, $t::Symbol")
        #typeof(t) <: Expr && println("replacing $n, $t::Expr, $(t.head) $(t.args) $(map(typeof, t.args))")

		#replace C-Uint8 with julia ASCIIString
		jt = t
		if (eval(t) == Ptr{Uint8})
			jt = :(ASCIIString)
		end

		#cast ROOT Int32 to Int64 in julia arguments
		if eval(t) == Int32
			jt = :(Int64)
		end
		if eval(t) == ASCIIString
			t = :(Ptr{Uint8})
		end

		jlarg = Expr(symbol("::"))
		push!(jlarg.args, n)
		push!(jlarg.args, jt)
        
        if typeof(t) <: Symbol
		    if t in ROOT_OBJECTS
		    	n = :(root_pointer($(n)))
		    	t = :(Ptr{Void})
		    end
        elseif typeof(t) <: Expr
            #if t.head == :curly && t.args[1] == :Ptr
		    #	n = :(root_pointer($(n)))
		    #	t = :(Ptr{Void})
            #end
        end
        #println("found replacement $n::$t")

		push!(avals.args, n)
		push!(aargs.args, t)

		push!(jlargs.args, jlarg)
	end
	return avals, aargs, jlargs
end


function splice_kwargs(jlargs::Expr, defs::Expr)
	defs = eval(defs)
	#println(join(defs, ", "))
	for i=1:length(defs)
		d = defs[i]
		#println(jlargs.args[i])
		if eval(jlargs.args[i].args[2]) <: ASCIIString && typeof(d) <: Integer
			d = ""
		end

		if d != nothing
			jlargs.args[i] = Expr(:kw, jlargs.args[i], d)
		end
	end
	return jlargs
end

function define_lib(lib::Expr)
    lib = lib.args[1]

    if !isdefined(lib)
		q = quote
		const $(symbol(string(lib))) = joinpath(
			dirname(Base.source_path()), "..",
			$(string(lib))
		)
		end
		eval(q)
	end
end

#macro to make methods from 
#@method libname Type ReturnType julia__function__name (c_arg1, ...) c__function__name
macro method(lib, tgt, jlfunc, ret, args, cfunc, defs)
	define_lib(lib)

	avals, aargs, jlargs = argument_replace(args)
	jlargs = splice_kwargs(jlargs, defs)

	#C function name target_func
	cfname = "$(tgt)_$(cfunc)"

	r = eval(ret)
	#Replace C: Ptr{TObjets} => julia:: TObject
	if r <: Ptr && typeof(r)==DataType && r.parameters[1] in map(eval, ROOT_OBJECTS)
		ret = r.parameters[1]
	end

	if ret in keys(type_replacement)
		ret = type_replacement[ret]
	end

	#create a function "stub"
	ex = quote
		function $jlfunc(__obj::$tgt)
			@assert(__obj.p != C_NULL)
			ccall(
				($cfname, libroot),
				$(eval(ret)), (),
			)
		end
	end

	#Note, this is fragile. if the stub is changed, the argument indices will also
	#splice julia function args
	append!(ex.args[2].args[1].args, jlargs.args)
	#splice C function argument types
	append!(ex.args[2].args[2].args[4].args[3].args, [:(Ptr{Void})]) #object itself
	append!(ex.args[2].args[2].args[4].args[3].args, aargs.args) #args
	#splice C function argument values
	append!(ex.args[2].args[2].args[4].args, [:(__obj.p)]) #object itself
	append!(ex.args[2].args[2].args[4].args, avals.args)
    
    #println(ex)

	eval(ex)
end

#macro to make constructors from 
#@constructor libname Type (c_arg1, ...) c__function__name
# => :ccall( (c__function__name, libname), Ptr{Void}, (args...), argsvals...)
macro constructor(lib, cls, args, cfunc, defs)
	define_lib(lib)

	avals, aargs, jlargs = argument_replace(args)

	jlargs = splice_kwargs(jlargs, defs)

	#C function name target_func
	cfname = "$(cls)_$(cfunc)"

	#create a function "stub"
	ex = quote
		function $cls()
			ccall(
				($cfname, libroot),
				$(eval(cls)), (),
			)
		end
	end
    
    #println(ex)

	#Note, this is fragile. if the stub is changed, the argument indices will also
	#splice julia function args
	append!(ex.args[2].args[1].args, jlargs.args)
	append!(ex.args[2].args[2].args[2].args[3].args, aargs.args)
	append!(ex.args[2].args[2].args[2].args, avals.args)
	eval(ex)
end

include("../gen/groot.jl")
include("../gen/tobject.jl")

include("../gen/tcollection.jl")
include("../gen/tseqcollection.jl")
include("../gen/tlist.jl")
include("../gen/tkey.jl")

include("../gen/th1.jl")
include("../gen/th1d.jl")

include("../gen/th2.jl")
include("../gen/th2d.jl")

include("../gen/tdirectory.jl")
include("../gen/tfile.jl")

include("../gen/ttree.jl")
include("../gen/tbranch.jl")
include("../gen/tleaf.jl")

macro parent_func(func, src, dst)
	eval(quote
		$func(__obj::$src, args...) = $func(root_cast($dst, __obj), args...)
	end)
end

for f in [
	:Fill, :Integral, :GetEntries, :Print, :Write,
	:GetNbinsX, :GetBinContent, :GetBinError, :GetBinLowEdge, :GetBinWidth,
	:SetBinContent, :SetBinError
	]
	@eval @parent_func $f TH1D TH1
end

for f in [
	:SetBinContent, :SetBinError
	]
	@eval @parent_func $f TH2D TH1
end

for f in [
	:Fill, :Integral, :GetEntries, :Print, :Write,
	:GetNbinsX, :GetNbinsY, :GetBinContent, :GetBinError,
	]
	@eval @parent_func $f TH2D TH2
end

@parent_func Fill TTree TObject
@parent_func SetDirectory TH1D TH1
@parent_func SetDirectory TH2D TH1


for f in [
	:GetListOfKeys, :Cd, :mkdir
	]
	@eval @parent_func $f TFile TDirectory
end

@parent_func GetEntries TObjArray TCollection
@parent_func At TObjArray TSeqCollection
@parent_func At TObjArray TSeqCollection
@parent_func At TList TSeqCollection

Base.length(x::TCollection) = GetEntries(x)
@parent_func Base.length TObjArray TCollection
@parent_func Base.length TSeqCollection TCollection
@parent_func Base.length TList TCollection

#ROOT is zero-based, Julia one-based
Base.getindex(tc::TSeqCollection, n::Integer) = At(tc, n-1)
@parent_func Base.getindex TObjArray TSeqCollection
@parent_func Base.getindex TList TSeqCollection

ReadObj(x) = ReadObj(root_cast(TKey, x))

@linux_only begin
    #for some reason, libRIO is not properly loaded on linux
    const rio = joinpath(ENV["ROOTSYS"], "lib", "libRIO.so")
    process_line(".L $rio")
end

export TFile, TTree, TObject, TH1, TH1D, TH2D, TH2, TBranch, TKey, TLeaf, TDirectory
export Write, Close, Fill, Branch, Print
export GetListOfBranches, GetEntry
export GetListOfKeys, Get
export Cd, mkdir

export SetAddress, GetBranch, GetClassName, GetListOfLeaves
export GetTypeName

export SetCacheSize, AddBranchToCache, SetBranchStatus, Draw, GetV1
export ReadObj, GetName, ClassName
export Integral, GetEntries, GetNbinsX, GetNbinsY, GetBinContent, GetBinError, GetBinLowEdge, GetBinWidth
export SetBinContent, SetBinError
export SetDirectory
export root_cast
export process_line

end
