dir = Pkg.dir("ROOT")
cmd = "include(\"$(dir)/test/runtests.jl\")"
run(`$(dir)/julia -e $cmd`)
