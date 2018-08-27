# this code cannot be run directly
# do 'source /user/ninastei/CCR/plc-2.0/bin/clik_profile.sh' from your sh shell or put it in your profile

function addvar () {
local tmp="${!1}" ;
tmp="${tmp//:${2}:/:}" ; tmp="${tmp/#${2}:/}" ; tmp="${tmp/%:${2}/}" ;
export $1="${2}:${tmp}" ;
} 

if [ -z "${PATH}" ]; then 
PATH=/user/ninastei/CCR/plc-2.0/bin
export PATH
else
addvar PATH /user/ninastei/CCR/plc-2.0/bin
fi
if [ -z "${PYTHONPATH}" ]; then 
PYTHONPATH=/user/ninastei/CCR/plc-2.0/lib/python2.7/site-packages
export PYTHONPATH
else
addvar PYTHONPATH /user/ninastei/CCR/plc-2.0/lib/python2.7/site-packages
fi
if [ -z "${LD_LIBRARY_PATH}" ]; then 
LD_LIBRARY_PATH=/user/ninastei/CCR/plc-2.0/lib
export LD_LIBRARY_PATH
else
addvar LD_LIBRARY_PATH /user/ninastei/CCR/plc-2.0/lib
fi
if [ -z "${LD_LIBRARY_PATH}" ]; then 
LD_LIBRARY_PATH=/user/ninastei/CCR/plc-2.0
export LD_LIBRARY_PATH
else
addvar LD_LIBRARY_PATH /user/ninastei/CCR/plc-2.0
fi
CLIK_PATH=/user/ninastei/CCR/plc-2.0
export CLIK_PATH

CLIK_DATA=/user/ninastei/CCR/plc-2.0/share/clik
export CLIK_DATA

CLIK_PLUGIN=rel2015
export CLIK_PLUGIN

