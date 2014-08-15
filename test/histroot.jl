#include("../src/histroot.jl")

using ROOT, Histograms, ROOT.ROOTHistograms
using Base.Test

h = Histogram([-Inf, 0,1,2,3,4, Inf])
for i=1:100
    hfill!(h, 0.3)
end
th = to_root(h, "hist1")
@test from_root(th) == h

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


#tf = TFile("test/testhist.root")
#
#hd = load_hists_from_file("test/testhist.root")
#
#for k in keys(hd)
#    th = root_cast(TH1, Get(tf, k))
#    ents = entries(hd[k])
#    conts = contents(hd[k])
#    errs = errors(hd[k])
#
#    e1 = conts ./ sum(conts) .* GetEntries(th)
#    e1[isnan(e1)] = 0
#    e1[e1 .== Inf] = 1
#
#    e2 = conts.^2 ./ errs.^2
#    e2[isnan(e2)] = 0
#    e2[e2 .== Inf] = 1
#
#    for i=1:nbins(hd[k])
#        @test conts[i] == GetBinContent(th, int32(i-1))
#        @test_approx_eq_eps errs[i] GetBinError(th, int32(i-1)) 0.01
#    end
#end
