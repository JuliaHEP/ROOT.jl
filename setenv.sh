DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
#export JULIA_LIB=`find $MY_JULIA_HOME/usr/lib -name "libjulia*" | head -n1`
#export JULIAREPL_LIB=`find $DIR -name librepl | head -n1`
#echo $JULIA_LIB
#echo $JULIAREPL_LIB
#export LD_LIBRARY_PATH=$MY_JULIA_HOME/usr/lib/julia/:$LD_LIBRARY_PATH #on linux
#export DYLD_LIBRARY_PATH=$MY_JULIA_HOME/usr/lib/julia/:$DYLD_LIBRARY_PATH #on osx
LD_LIBRARY_PATH=$DIR:$MY_JULIA_HOME/usr/lib/:$LD_LIBRARY_PATH
DYLD_LIBRARY_PATH=$DIR:$MY_JULIA_HOME/usr/lib/:$DYLD_LIBRARY_PATH
export PATH=$DIR:$PATH
alias root-julia="root-julia -H $MY_JULIA_HOME/usr/lib"
