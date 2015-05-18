#!/bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
DYLD_LIBRARY_PATH=$JULIA_HOME:$DYLD_LIBRARY_PATH $DIR/rjulia $@
