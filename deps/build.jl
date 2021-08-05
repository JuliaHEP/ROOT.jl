depsdir = dirname(@__FILE__)

function find_file(basepath, file)
    ret = split(readstring(`find $basepath -name $file`))
    ret = sort(ret, by=x->length(x))
    length(ret) > 0 || error("Could not find any matches")
    return first(ret) 
end

const ROOT_INCDIR = String(strip(read(`root-config --incdir`, String)))
const ROOT_LIBDIR = String(strip(read(`root-config --libdir`, String)))

depsfile_location = joinpath(splitdir(Base.source_path())[1],"deps.jl")

open(depsfile_location, "w") do depsfile
    print(depsfile,
        """
        const ROOT_INCDIR = "$ROOT_INCDIR"
        const ROOT_LIBDIR = "$ROOT_LIBDIR"
        """
    )
end
