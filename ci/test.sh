#!/bin/bash
set -e

which gcc
gcc -dumpversion

which g++
g++ -dumpversion

which python
python --version

which root
root -l -q

which julia
julia --version
