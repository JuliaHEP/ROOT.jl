Branch(tree::Union{ROOT.TTree, CxxRef{<:ROOT.TTree}}, bname::Union{Ref{Int8}, String, Array{Int8}}, addr, bufsize::Int32) = Branch(tree, bname, addr, bufsize, 99)
Branch(tree::Union{ROOT.TTree, CxxRef{<:ROOT.TTree}}, bname::Union{Ref{Int8}, String, Array{Int8}}, addr) = Branch(tree, bname, addr, 32000, 99) 
