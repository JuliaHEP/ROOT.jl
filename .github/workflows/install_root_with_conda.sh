#!/bin/sh

MINIFORGE_RELEASE=25.3.0-3

OS=$(uname -s)
[ "$OS" = Darwin ] && OS=MacOSX
install_script="Miniforge3-$OS-$(uname -m).sh"
curl -fsSLo "$install_script" "https://github.com/conda-forge/miniforge/releases/download/$MINIFORGE_RELEASE/$install_script"
[ -e "$HOME/conda" ] && { echo "$HOME/conda already exists." 1>&2; exit 1; }
sh "$install_script" -b -p "$HOME/conda_for_rootjl"
PATH="$PATH:$HOME/conda_for_rootjl/bin"
conda config --set channel_priority strict
conda install -c conda-forge root=6.32.8 -y
echo "$HOME/conda_for_rootjl/bin"
