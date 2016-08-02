dir = dirname(dirname(@__FILE__))

runner(x) = run(`$(dir)/deps/usr/bin/julia $(dir)/test/$(x)`)

for fi in ["rootcxx.jl"]
    runner(fi)
end
