using ROOT

x = range(0, 10, length=50)
y = x.^2

g = ROOT.TGraph(x, y)
c = ROOT.TCanvas()
Draw(g, "A*")
Fit(g, "pol2")
Draw(g)

#Save the Canvas in an image file
SaveAs(c, "demo_TGraph.png")