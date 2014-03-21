using ROOT
using Base.Test

println(methods(TH1D))
hi = TH1D("my_hist", "My Hist", 10, -3.0, 3.0)
for i=1:1000000
	Fill(hi, randn())
end

Integral(hi)::Float64
@test GetEntries(hi)==1000000

bx = Float64[0.0, 1.0, 2.0]
by = Float64[0.0, 1.0]

println(methods(TH2D))
hi2 = TH2D("my_hist2", "My Hist", 2, pointer(bx), 1, pointer(by))::TH2D

Fill(hi2, 0.0, 0.0, 0.0)

