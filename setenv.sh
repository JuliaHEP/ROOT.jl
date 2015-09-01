DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
export JULIA_LIB=`find $MY_JULIA_HOME/usr/lib -name "libjulia*" | head -n1`
export JULIAREPL_LIB=`find $DIR -name librepl | head -n1`
export LD_LIBRARY_PATH=$MY_JULIA_HOME/usr/lib/julia/:$LD_LIBRARY_PATH #on linux
export DYLD_LIBRARY_PATH=$MY_JULIA_HOME/usr/lib/julia/:$DYLD_LIBRARY_PATH #on osx
export PATH=$DIR:$PATH
