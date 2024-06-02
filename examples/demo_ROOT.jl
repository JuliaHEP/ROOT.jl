#Import the module.
# The iROOT module is required for interactive graphic display
# Loading the package trigger a loop that process ROOT graphic events.
using ROOT
const R = ROOT #a shortcut

# Create a ROOT histogram, fill it with random events, and fit it.
h = R.TH1D("h", "Normal distribution", 100, -5., 5.)
R.FillRandom(h, "gaus")

#Draw the histogram on screen
c = R.TCanvas()
R.Draw(h)

#Fit the histogram wih a normal distribution
R.Fit(h, "gaus")

#Save the Canvas in an image file
R.SaveAs(c, "demo_ROOT.png")

#Save the histogram and the graphic canvas in the demo_ROOT_out.root file.
f = R.TFile!Open("demo_ROOT_out.root", "RECREATE")
R.Write(h)
R.Write(c)
Close(f)
