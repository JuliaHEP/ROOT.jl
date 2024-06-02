using ROOT
const R = ROOT # A shortcut

x = collect(1.:10.)
y = x.^2
g = R.TGraph(convert(Int32, length(x)), x, y)
c = R.TCanvas()
Draw(g, "A*")
Fit(g, "pol2")
Draw(g)

#Save the Canvas in an image file
R.SaveAs(c, "demo_TGraph.png")
