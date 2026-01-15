"""
"""
function demo()
    println("""Executing:

   h = $(@__MODULE__).TH1D("h", "Normal distribution", 100, -5, 5)
   FillRandom(h, "gaus")
   c = $(@__MODULE__).TCanvas()
   Fit(h, "gaus")
   """)
    
    h = ROOT.TH1D("h", "Normal distribution", 100, -5, 5)
    FillRandom(h, "gaus")
    c = ROOT.TCanvas()
    Fit(h, "gaus")
    c
end

