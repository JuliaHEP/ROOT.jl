using ROOT
const R = ROOT # A shortcut

# Defines a TGraph with the points to fit
x = collect(1.:10.); y = map(x -> x^2 * (1 + 0.1*randn()), x)
g = TGraphW(convert(Int32, length(x)), x, y)

# Function for the fit
f_jl(x,y) = x[1]^y[1]

println("\nFit a TGraph with a function defined in Julia.")
R.Fit(f_jl, g, "", "", 0., 10., 1, 1, 0)

#   embedded in ROOT TF1
println("Define a TF1 from a Julia function")
tf1 = R.TF1(f_jl, "func", 0., 10., 1, 1, 0)

println("\nRedo the fit using the TF1 function refered by its name.")
Fit(g, "func")

println("\nRedo the fit using the TF1 function refered by its instance.")
Fit(g, tf1)

c = R.TCanvas()
Draw(g, "A*")

#Save the Canvas in an image file
R.SaveAs(c, "demo_fit_with_jl_func_2.png")
