using ROOT

println("Reading back the file created with write_tree3.jl using TTreeReader.\n")

f = ROOT.TFile!Open("test3.root")
f != C_NULL || error("File not found.")

reader = ROOT.TTreeReader("tree", f)
Muon_pt = ROOT.TTreeReaderArray{Float32}(reader, "Muon_pt")
Muon_eta = ROOT.TTreeReaderArray{Float32}(reader, "Muon_eta")
Muon_phi = ROOT.TTreeReaderArray{Float32}(reader, "Muon_phi")

ievt = 0
while Next(reader)
    global ievt += 1
    println("Event ", ievt)

    println("Muon multiplicity: ", length(Muon_pt))
    println("Muon pt: ",  join(Muon_pt,", "))
    println("Muon eta: ", join(Muon_eta, ","))
    println("Muon phi: ", join(Muon_phi, ","))
    
    println()
end
