using CxxWrap
using ROOT
const R = ROOT # A shortcut

# Defines a TGraph with the points to fit
x = collect(1.:10.); y = map(x -> x^2 * (1 + 0.1*randn()), x)
g = R.TGraph(convert(Int32, length(x)), x, y)

f_jl(x,y) = x[1]^y[1]
f_x = @safe_cfunction(Float64, (ConstCxxPtr{Float64}, ConstCxxPtr{Float64})) do x, p
    f_jl(unsafe_wrap(Vector{Float64}, x.cpp_object, 1), unsafe_wrap(Vector{Float64}, p.cpp_object, 1))
end
tf1 = R.TF1("func", f_x, 0., 10., 1, 1, 0)

#Fit(g, "func")
Fit(g, CxxPtr(tf1))

c = R.TCanvas()
Draw(g, "A*")

#Save the Canvas in an image file
R.SaveAs(c, "demo_fit_with_jl_func.png")
