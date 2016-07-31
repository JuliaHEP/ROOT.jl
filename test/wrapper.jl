dir = dirname(dirname(@__FILE__))
cmd = "include(\"$(dir)/test/runtests.jl\")"
run(`$(dir)/julia -e $cmd`)
