#include("../src/histroot.jl")

using ROOT, Histograms, ROOT.ROOTHistograms
using Base.Test

h = Histogram([-Inf, 0,1,2,3,4, Inf])
for i=1:100
    hfill!(h, 0.3)
end
th = to_root(h, "hist1")
@test from_root(th) == h
#Print(th, "ALL")

h = Histogram([-Inf, 0,1,2,3,4, Inf])
for i=1:100
    hfill!(h, 0.3, 0.1)
end
th = to_root(h, "hist2")
@test from_root(th) == h


nh = NHistogram({[-Inf, 0,1,2, Inf], [-Inf, 0,1,2, Inf]})
for i=1:100
    hfill!(nh, {0.3, 0.3})
end
th = to_root(nh, "nhist")
nh2 = from_root(th)
@test size(nh) == size(nh2)
@test all(nh2.baseh.bin_entries .== nh.baseh.bin_entries)
@test all(nh2.baseh.bin_contents .== nh.baseh.bin_contents)
@test all(contents(nh) .== contents(nh2))
@test all(entries(nh) .== entries(nh2))
