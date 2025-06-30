# Geometry detector assembly example
# Adapted to Julia ROOT Tutorial geom/assembly.C
# authors: Andrei Gheata (C++ version) and Philippe Gras (Julia version)

using ROOT
using CxxWrap

scriptpath = Base.PROGRAM_FILE
isempty(scriptpath) && (scriptpath = "assembly.jl")

# Definition of a simple geometry
geom = ROOT.TGeoManager("Assemblies", "Geometry using assemblies")

# define some materials
matVacuum = ROOT.TGeoMaterial("Vacuum", 0,0,0)
matAl = ROOT.TGeoMaterial("Al", 26.98,13,2.7)

# define some media
Vacuum = ROOT.TGeoMedium("Vacuum", 1, ConstCxxPtr(matVacuum))
Al = ROOT.TGeoMedium("Aluminium",2, ConstCxxPtr(matAl))
 
# make the top container volume
top = ROOT.MakeBox(geom, "TOP", CxxPtr(Vacuum), 1000., 1000., 100.)
SetTopVolume(geom, top)
 
# Make the elementary assembly of the whole structure
tplate = ROOT.TGeoVolumeAssembly("TOOTHPLATE")
 
ntooth = 5
xplate = 25.
yplate = 50.
xtooth = 10.
ytooth = 0.5 * yplate / ntooth
dshift = 2. * xplate + xtooth
 
plate = MakeBox(geom, "PLATE", CxxPtr(Al), xplate, yplate, 1)

const kBlue = 600
SetLineColor(plate, kBlue)
tooth = MakeBox(geom, "TOOTH", CxxPtr(Al), xtooth, ytooth, 1)
SetLineColor(tooth, kBlue)
AddNode(tplate, plate, 1)
for i in 1:ntooth
    xt = xplate + xtooth
    yt = (4 * i - 3) * ytooth - yplate
    AddNode(tplate, tooth, i, move!(ROOT.TGeoTranslation(xt, yt, 0)))
    xt = - xplate - xtooth;
    yt = - yplate + (4 * i - 3) * ytooth;
    AddNode(tplate, tooth, ntooth + 1, move!(ROOT.TGeoTranslation(xt, yt, 0)))
end
 
rot1 = ROOT.TGeoRotation()
RotateX(rot1, 90)


# Make a hexagone cell out of 6 tooth plates. These can zip together
# without generating overlaps (they are self-contained)
cell = ROOT.TGeoVolumeAssembly("CELL")
for i in 1:5
    phi =  60. * i
    phirad = phi * π / 180.0
    xp =   dshift * sin(phirad)
    yp = - dshift * cos(phirad)
    rot = ROOT.TGeoRotation(rot1)
    RotateZ(rot, phi)
    AddNode(cell, CxxPtr(tplate), i + 1 , move!(ROOT.TGeoCombiTrans(xp, yp, 0, move!(rot))))
end
 
# Make a row as an assembly of cells, then combine rows in a honeycomb
# structure. This again works without any need to define rows as
# "overlapping"
row = ROOT.TGeoVolumeAssembly("ROW")
ncells = 5

for i in 1:ncells
    ycell = (2 * i - 1) * (dshift + 10)
    AddNode(row, CxxPtr(cell), ncells + i, move!(ROOT.TGeoTranslation(0, ycell, 0)))
    AddNode(row, CxxPtr(cell), ncells + 1 - i, move!(ROOT.TGeoTranslation(0, - ycell, 0)))
end
 
dxrow = 3. * (dshift + 10.) * tan(30. * π / 180.)
dyrow = dshift + 10.0

nrows = 5
for i in 1:nrows
    xrow = 0.5 * (2 * i - 1) * dxrow
    yrow = 0.5 * dyrow
    ((i % 2) == 1) && (yrow = -yrow)
    AddNode(top, CxxPtr(row), nrows + i, move!(ROOT.TGeoTranslation(xrow, yrow, 0)))
    AddNode(top, CxxPtr(row), nrows + 1 -i, move!(ROOT.TGeoTranslation(-xrow, -yrow, 0)))
end
 
# close the geometry
CloseGeometry(geom)
 
SetVisLevel(geom, 4)
SetVisOption(geom, 0)

if isinteractive()
    #Beware this will crash is not in interactive mode
    #(same as in batch mode of C++ ROOT)
    Draw(top, "ogl") 
else
    c = ROOT.TCanvas()
    Draw(top)
    SaveAs(c, "assembly.png")
    @info "This script is better run in interative mode, use julia -i option or execute include(\"$scriptpath\") from the Julia REPL"
end
