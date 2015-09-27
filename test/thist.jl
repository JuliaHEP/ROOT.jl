using ROOT
using Base.Test

hi = TH1D("my_hist", "My Hist", Int32(10), -30.0, 30.0)
@test bytestring(GetName(hi)) == "my_hist"
@test GetNbinsX(hi) == Int32(10)

n=1000000
for i=1:n
	Fill(hi, randn())
end
@test GetEntries(hi) == Int32(n)
@test_approx_eq_eps Integral(hi) Int32(n) 100
println("my_hist entries=$(GetEntries(hi)) mean=$(GetMean(hi)) rms=$(GetRMS(hi))")

@test_approx_eq_eps GetMean(hi) 0.0 0.1
#warn("Disabling RMS test!")
#@test_approx_eq_eps GetRMS(hi) 1.0 0.1

sw2 = ROOT.GetSumw2(hi)
@test sw2.p != 0
println(sw2)

#@test GetSize(sw2) == 12
#@test all([GetAt(sw2, Int32(i-1)) for i=1:GetSize(sw2)] .> 0)

@test GetEntries(hi) == n

Integral(hi)::Float64

bx = Float64[0.0, 1.0, 2.0]
by = Float64[0.0, 1.0]

hi2 = TH2D("my_hist2", "My Hist", Int32(2), pointer(bx), Int32(1), pointer(by))::TH2D
@test bytestring(GetName(hi2))=="my_hist2"
@test GetNbinsX(hi2) == 2
@test GetNbinsY(hi2) == 1

Fill(hi2, 0.0, 0.0, 0.5)
@test GetEntries(hi2) == 1
@test Integral(hi2) == 0.5
