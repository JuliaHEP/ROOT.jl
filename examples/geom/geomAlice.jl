# Script drawing a detector geometry (here ALICE).
#    
# Adapted to Julia from https://root.cern/doc/master/geomAlice_8C.html
# authors: Rene Brun (C++ version), Philipe Gras (Julia version)

using ROOT

scriptpath = Base.PROGRAM_FILE
isempty(scriptpath) && (scriptpath = "geomAlice.jl")

const geo = ROOT.TGeoManager!Import("http://root.cern/files/alice2.root")
DefaultColors(geo)
SetVisLevel(geo, 2)
GetVolume(geo, "HALL") |> InvisibleAll
GetVolume(geo, "ZDCC") |> InvisibleAll
GetVolume(geo, "ZDCA") |> InvisibleAll
GetVolume(geo, "L3MO") |> InvisibleAll
GetVolume(geo, "YOUT1") |> InvisibleAll
GetVolume(geo, "YOUT2") |> InvisibleAll
GetVolume(geo, "YSAA") |> InvisibleAll
GetVolume(geo, "RB24") |> InvisibleAll
GetVolume(geo, "RB26Pipe") |> InvisibleAll
GetVolume(geo, "DDIP") |> InvisibleAll
GetVolume(geo, "DCM0") |> InvisibleAll
GetVolume(geo, "BRS1") |> InvisibleAll
GetVolume(geo, "BRS4") |> InvisibleAll
GetVolume(geo, "Dipole") |> InvisibleAll
GetVolume(geo, "ZN1") |> InvisibleAll
GetVolume(geo, "Q13T") |> InvisibleAll
GetVolume(geo, "ZP1") |> InvisibleAll
GetVolume(geo, "QTD1") |> InvisibleAll
GetVolume(geo, "QTD2") |> InvisibleAll
GetVolume(geo, "QBS7") |> InvisibleAll
GetVolume(geo, "QA07") |> InvisibleAll
GetVolume(geo, "MD1V") |> InvisibleAll
GetVolume(geo, "QTD3") |> InvisibleAll
GetVolume(geo, "QTD4") |> InvisibleAll
GetVolume(geo, "QTD5") |> InvisibleAll
GetVolume(geo, "QBS3") |> InvisibleAll
GetVolume(geo, "QBS4") |> InvisibleAll
GetVolume(geo, "QBS5") |> InvisibleAll
GetVolume(geo, "QBS6") |> InvisibleAll

c = ROOT.TCanvas()
#Draw(GetVolume(geo, "ALIC"), "ogl")

if isinteractive()
    #Beware this will crash is not in interactive mode
    #(same as in batch mode of C++ ROOT)
    Draw(GetVolume(geo, "ALIC"), "ogl")
else
    Draw(GetVolume(geo, "ALIC"))
    SaveAs(c, "alice.png")
    @info "This script is better run in interative mode, use julia -i option or execute include(\"$scriptpath\") from the Julia REPL"
end

