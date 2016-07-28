isdir("$JULIA_HOME/../../ui") || error("Need to deploy ROOT.jl on top of a source install of julia")
cp("repl.patch", "$JULIA_HOME/../../repl.patch"; remove_destination=true)
cd("$JULIA_HOME/../..")
readstring(`git reset --hard HEAD`)
readstring(`rm -f ui/root-ui.cc $JULIA_HOME/../../rjulia $JULIA_HOME/rjulia`)
readstring(`git apply --ignore-whitespace repl.patch`)
cd("$JULIA_HOME/../../ui")
readstring(`make`) |> println
readstring(`ln -s $JULIA_HOME/rjulia $JULIA_HOME/../../rjulia`)
