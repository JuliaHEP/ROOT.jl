#!/bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
export JULIA_LIB=`ls $JULIA_HOME/libjulia.*`
DYLD_LIBRARY_PATH=$JULIA_HOME:$DYLD_LIBRARY_PATH $DIR/rjulia $@
