using ROOT
using Cxx
using Base.Test
# using Profile

function test_TH1D_new()
  tfile = TFile("test1.root", "RECREATE")
  h = TH1D_new("a", "a", 100, -5.0, 5.0)::TH1DPtr

  for i=1:100000
    icxx"""$h->Fill($(randn()));"""
  end
  icxx"""$tfile->Write();"""
  icxx"""$tfile->Close();"""
  return true
end

function test_TH1D_value()
  tfile = TFile("test2.root", "RECREATE")
  h = TH1D_stack("a", "a", 100, -5.0, 5.0)::TH1DValue

  for i=1:100000
    icxx"""$h.Fill($(randn()));"""
  end
  icxx"""$tfile->Write();"""
  icxx"""$tfile->Close();"""
  return true
end

function test_TH1D_uniq()
  tfile = TFile("test3.root", "RECREATE")
  h = TH1D_uniq("a", "a", 100, -5.0, 5.0)::TH1DUPtr
  #need to tell ROOT not to take this object to TFile internals,
  #because it won't correctly use std::move, so julia will still try to GC this object
  icxx"""$h->SetDirectory(0);"""
  for i=1:100000
    icxx"""$h->Fill($(randn()));"""
  end
  icxx"""$h->Write();"""
  # icxx"""$h.reset();"""  #need to call this if didn't do h->SetDirectory(0), otherwise ROOT will try to self-delete 
  icxx"""$tfile->Close();"""
  return true
end

function allocate_many_uniq()
  arr = TH1DUPtr[]
  for i=1:10000
    h = TH1D_uniq("", "", 100, -5.0, 5.0)::TH1DUPtr
    icxx"""$h->SetDirectory(0);"""
    push!(arr, h)
  end
  return true
end

function allocate_loop()
  for i=1:100
    allocate_many_uniq()
  end
end

@show @time test_TH1D_new()
@show @time test_TH1D_value()
@show @time test_TH1D_uniq()
@show @time allocate_many_uniq()
@show @time allocate_loop()
# Profile.clear_malloc_data()

@show @time test_TH1D_new()
@show @time test_TH1D_new()

@show @time test_TH1D_value()
@show @time test_TH1D_value()

@show @time test_TH1D_uniq()
@show @time test_TH1D_uniq()

@show @time allocate_many_uniq()
@show @time allocate_many_uniq()

@show @time allocate_loop()
@show @time allocate_loop()


#Looks like move semantics don't work correctly, h1 stays valid
h1 = TH1D_uniq("a", "a", 100, -5.0, 5.0)
println(icxx"""$h1.get();""")
h2 = icxx"""std::move($h1);"""
println(icxx"""$h1;""")
println(icxx"""$h2;""")
println(h1==h2)
println(unsafe_string(icxx"""$h1->GetName();"""))
println(unsafe_string(icxx"""$h2->GetName();"""))