using ROOT
using Base.Test

r = rcpp(""".L ~/macro.cxx""")
println("r1 ", r)
@test r==0
r = rcpp_raw("""
double gx(int j) {
    return j+1;
}
double res = 0;
"""
)
println("r2 ", r)
@test r==0

r = rcpp_load_as("""
    res = (double)fx(2,1) + 0.1;
    &res;""",
    Float64,1
)
println("r3 ", r)
@test r==7.38


r = rcpp_load_as("""
    res = (double)gx(2) + 0.1;
    &res;""",
    Float64,1
)
println("r3 ", r)
@test r==3.1

r = rcpp_raw("""
class C {
    public:
        int x;
    C(int _x) {
        x = _x;
    }
};
"""
)

type C
    x::Int32
end

rcpp("""C c(100); c.x += 1;""")
c = rcpp_load_as("""&c;""", C, 1)
@test c.x == 101 
