using ROOT
using Base.Test

hi = TH1D("my_hist", "My Hist", 10, -3.0, 3.0)
for i=1:1000000
	Fill(hi, randn())
end

Integral(hi)::Float64
@test GetEntries(hi)==1000000
