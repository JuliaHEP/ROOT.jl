using Base.Test
using ROOT

gROOT.set_batch(true)
gROOT.set_batch(false)
gROOT.set_batch(true)

@test gROOT.process_line("1;") == 1
@test gROOT.process_line("1.0;") == 1.0
