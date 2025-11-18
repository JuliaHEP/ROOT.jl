if !isdefined(Main, :RUNTESTS)
    using ROOT
    using CxxWrap
    using Test
end

objarray  = ROOT.TObjArray()

#Create array elements:
h1 = ROOT.TH1D("h1", "h1", 100, -1, 1)
h2 = ROOT.TH1D("h2", "h2", 100, -1, 1)

#Fill the array
Add(objarray, CxxPtr(h1))
Add(objarray, CxxPtr(h2))

#Test the array size
@test GetEntries(objarray) == 2

#Retrieve the array elements
h1_ = CxxWrap.CxxPtr{ROOT.TH1D}(At(objarray, 0))[]
h2_ = CxxWrap.CxxPtr{ROOT.TH1D}(At(objarray, 1))[]

#Check the retrieved elements are identical to the inserted ones
@test GetTitle(h1_) == "h1"
@test GetTitle(h2_) == "h2"

@test h1_.cpp_object == h1.cpp_object
@test h2_.cpp_object == h2.cpp_object
@test h1_.cpp_object != h2.cpp_object

SetBinContent(h1, 1, 100)
@test GetBinContent(h1, 1) == 100
@test GetBinContent(h1_, 1) == 100

SetBinContent(h2_, 1, 200)
@test GetBinContent(h2_, 1) == 200
@test GetBinContent(h2, 1) == 200

