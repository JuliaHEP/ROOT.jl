module ROOT

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

root_cast{T <: ROOTObject, K <: ROOTObject}(o::T, to::Type{K}) = to(root_pointer(o))

@root_object(TFile)
@root_object(TDirectory)
@root_object(TCollection)
@root_object(TList)
@root_object(TBranch)
@root_object(TObject)
@root_object(TTree)

typealias Option_t ASCIIString
typealias Int_t Int32
typealias Long_t Int64
typealias Long64_t Int64

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

		#replace C-Uint8 with julia ASCIIString
		jt = t
		if eval(t) == Ptr{Uint8}
			jt = :(ASCIIString)
		end
		if eval(t) == Int32
			jt = :(Int64)
		end
		if eval(t) == ASCIIString
			t = :(Ptr{Uint8})
		end

		jlarg = Expr(symbol("::"))
		push!(jlarg.args, n)
		push!(jlarg.args, jt)

		if t in ROOT_OBJECTS
			n = :(root_pointer($(n)))
			t = :(Ptr{Void})
		end

		push!(avals.args, n)
		push!(aargs.args, t)

		push!(jlargs.args, jlarg)
	end
	return avals, aargs, jlargs
end

#macro to make methods from 
#@method libname Type ReturnType julia__function__name (c_arg1, ...) c__function__name
macro method(lib, tgt, jlfunc, ret, args, cfunc)

	avals, aargs, jlargs = argument_replace(args)

	#C function name target_func
	cfname = "$(tgt)_$(cfunc)"

	#create a function "stub"
	ex = quote
		function $jlfunc(x::$tgt,)
			@assert(x.p != C_NULL)
			ccall(
				($cfname, $lib),
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
	append!(ex.args[2].args[2].args[4].args, [:(x.p)]) #object itself
	append!(ex.args[2].args[2].args[4].args, avals.args)
	#println(ex)
	eval(ex)
end

#macro to make constructors from 
#@constructor libname Type (c_arg1, ...) c__function__name
# => :ccall( (c__function__name, libname), Ptr{Void}, (args...), argsvals...)
macro constructor(lib, cls, args, cfunc)

	avals, aargs, jlargs = argument_replace(args)

	#C function name target_func
	cfname = "$(cls)_$(cfunc)"

	#create a function "stub"
	ex = quote
		function $cls()
			ccall(
				($cfname, $lib),
				$(eval(cls)), (),
			)
		end
	end

	#Note, this is fragile. if the stub is changed, the argument indices will also
	#splice julia function args
	append!(ex.args[2].args[1].args, jlargs.args)
	append!(ex.args[2].args[2].args[2].args[3].args, aargs.args)
	append!(ex.args[2].args[2].args[2].args, avals.args)
	#println(ex)
	eval(ex)
end

include("../gen/tdirectory.jl")
include("../gen/tfile.jl")
include("../gen/ttree.jl")
include("../gen/tobject.jl")

export TFile, TTree, TObject
export Write, Close, Fill, Branch
end