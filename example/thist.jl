using ROOT

hi = TH1D("my_hist", "My Hist", 10, -3.0, 3.0)
for i=1:1000000
	Fill(hi, randn())
end

println("i=", Integral(hi), " e=", GetEntries(hi))
