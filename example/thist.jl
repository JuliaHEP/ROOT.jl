using ROOT
using Base.Test

#println(methods(TH1D))
hi = TH1D("my_hist", "My Hist", 10, -3.0, 3.0)
@test bytestring(GetName(hi)) == "my_hist"
@test GetNbinsX(hi) == 10

n=1000000
for i=1:n
	Fill(hi, randn())
end

@test GetEntries(hi) == n

Integral(hi)::Float64

bx = Float64[0.0, 1.0, 2.0]
by = Float64[0.0, 1.0]

#println(methods(TH2D))
hi2 = TH2D("my_hist2", "My Hist", 2, pointer(bx), 1, pointer(by))::TH2D
@test bytestring(GetName(hi2))=="my_hist2"
@test GetNbinsX(hi2) == 2
@test GetNbinsY(hi2) == 1

Fill(hi2, 0.0, 0.0, 0.5)
@test GetEntries(hi2) == 1
@test Integral(hi2) == 0.5
