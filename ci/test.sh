#!/bin/bash
set -e

gcc -dumpversion
g++ -dumpversion
ldd --version
python --version

root -l -q

julia --version
