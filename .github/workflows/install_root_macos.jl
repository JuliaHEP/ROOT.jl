using Pkg
Pkg.activate(temp=true)
Pkg.add("Conda")
import Conda
Conda.add("root=6.32.8")
print("`\n", joinpath(Conda.ROOTENV, "bin"))
