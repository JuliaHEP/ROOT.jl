# Script drawing a detector geometry (here ATLAS).
#    
# Adapted to Julia from the ROOT tutorial geom/fromAtlas.C
# authors: Rene Brun (C++ version), Philipe Gras (Julia version)

using ROOT

scriptpath = Base.PROGRAM_FILE
isempty(scriptpath) && (scriptpath = "geomAtlas.jl")
 
const geo = ROOT.TGeoManager!Import("http://root.cern/files/atlas.root")
#DefaultColors(geo)
SetMaxVisNodes(geo, 5000)
#SetVisLevel(geo, 4)

c = ROOT.TCanvas()
#Draw(GetVolume(geo, "ATLS"), "ogl")
if isinteractive()
    #Beware this will crash is not in interactive mode
    #(same as in batch mode of C++ ROOT)
    Draw(GetVolume(geo, "ATLS"), "ogl")
else
    Draw(GetVolume(geo, "ATLS"))
    SaveAs(c, "atlas.png")
    @info "This script is better run in interative mode, use julia -i option or execute include(\"$scriptpath\") from the Julia REPL"
end

