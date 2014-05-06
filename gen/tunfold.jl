# begin enum TUnfold_EConstraint
typealias TUnfold_EConstraint Uint32
const kEConstraintNone = 0
const kEConstraintArea = 1
# end enum TUnfold_EConstraint
# begin enum TUnfold_ERegMode
typealias TUnfold_ERegMode Uint32
const kRegModeNone = 0
const kRegModeSize = 1
const kRegModeDerivative = 2
const kRegModeCurvature = 3
const kRegModeMixed = 4
# end enum TUnfold_ERegMode
# begin enum TUnfold_EHistMap
typealias TUnfold_EHistMap Uint32
const kHistMapOutputHoriz = 0
const kHistMapOutputVert = 1
# end enum TUnfold_EHistMap
@constructor :libroot TUnfold (hist_A::Ptr{TH2}, histmap::Cuint, regmode::Cuint, constraint::Cuint, ) TUnfold1 (nothing, nothing, kRegModeSize, kEConstraintArea,  )
@method :libroot TUnfold DoUnfold Double_t (tau::Double_t, hist_y::Ptr{TH1}, scaleBias::Double_t, ) DoUnfold1 (nothing, nothing, 0.0,  )
@method :libroot TUnfold SetInput Int_t (hist_y::Ptr{TH1}, scaleBias::Double_t, oneOverZeroError::Double_t, ) SetInput1 (nothing, 0.0, 0.0,  )
@method :libroot TUnfold DoUnfold Double_t (tau::Double_t, ) DoUnfold2 (nothing,  )
@method :libroot TUnfold GetOutput Ptr{TH1D} (name::Ptr{Uint8}, title::Ptr{Uint8}, x0::Double_t, x1::Double_t, ) GetOutput1 (nothing, nothing, 0.0, 0.0,  )
@method :libroot TUnfold GetBias Ptr{TH1D} (name::Ptr{Uint8}, title::Ptr{Uint8}, x0::Double_t, x1::Double_t, ) GetBias1 (nothing, nothing, 0.0, 0.0,  )
@method :libroot TUnfold GetEmatrix Ptr{TH2D} (name::Ptr{Uint8}, title::Ptr{Uint8}, x0::Double_t, x1::Double_t, ) GetEmatrix1 (nothing, nothing, 0.0, 0.0,  )
@method :libroot TUnfold GetOutput None (output::Ptr{TH1}, binMap::Ptr{Int_t}, ) GetOutput2 (nothing, 0,  )
@method :libroot TUnfold GetEmatrix None (ematrix::Ptr{TH2}, binMap::Ptr{Int_t}, ) GetEmatrix2 (nothing, 0,  )
@subclass TUnfold TObject
