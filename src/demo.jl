"""
"""
function demo()
    println("""Executing:

   h = $(@__MODULE__).TH1D("h", "Normal distribution", 100, -5, 5)
   $(@__MODULE__).FillRandom(h, "gaus")
   c = $(@__MODULE__).TCanvas()
   $(@__MODULE__).Fit(h, "gaus")
   """)
    
    h = TH1D("h", "Normal distribution", 100, -5, 5)
    FillRandom(h, "gaus")
    c = ROOT2.TCanvas()
    Fit(h, "gaus")
    c
end

