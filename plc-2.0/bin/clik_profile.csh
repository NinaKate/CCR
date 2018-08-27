# this code cannot be run directly
# do 'source /user/ninastei/CCR/plc-2.0/bin/clik_profile.csh' from your csh shell or put it in your profile

 

if !($?PATH) then
setenv PATH /user/ninastei/CCR/plc-2.0/bin
else
set newvar=$PATH
set newvar=`echo ${newvar} | sed s@:/user/ninastei/CCR/plc-2.0/bin:@:@g`
set newvar=`echo ${newvar} | sed s@:/user/ninastei/CCR/plc-2.0/bin\$@@` 
set newvar=`echo ${newvar} | sed s@^/user/ninastei/CCR/plc-2.0/bin:@@`  
set newvar=/user/ninastei/CCR/plc-2.0/bin:${newvar}                     
setenv PATH /user/ninastei/CCR/plc-2.0/bin:${newvar} 
endif
if !($?PYTHONPATH) then
setenv PYTHONPATH /user/ninastei/CCR/plc-2.0/lib/python2.7/site-packages
else
set newvar=$PYTHONPATH
set newvar=`echo ${newvar} | sed s@:/user/ninastei/CCR/plc-2.0/lib/python2.7/site-packages:@:@g`
set newvar=`echo ${newvar} | sed s@:/user/ninastei/CCR/plc-2.0/lib/python2.7/site-packages\$@@` 
set newvar=`echo ${newvar} | sed s@^/user/ninastei/CCR/plc-2.0/lib/python2.7/site-packages:@@`  
set newvar=/user/ninastei/CCR/plc-2.0/lib/python2.7/site-packages:${newvar}                     
setenv PYTHONPATH /user/ninastei/CCR/plc-2.0/lib/python2.7/site-packages:${newvar} 
endif
if !($?LD_LIBRARY_PATH) then
setenv LD_LIBRARY_PATH /user/ninastei/CCR/plc-2.0/lib
else
set newvar=$LD_LIBRARY_PATH
set newvar=`echo ${newvar} | sed s@:/user/ninastei/CCR/plc-2.0/lib:@:@g`
set newvar=`echo ${newvar} | sed s@:/user/ninastei/CCR/plc-2.0/lib\$@@` 
set newvar=`echo ${newvar} | sed s@^/user/ninastei/CCR/plc-2.0/lib:@@`  
set newvar=/user/ninastei/CCR/plc-2.0/lib:${newvar}                     
setenv LD_LIBRARY_PATH /user/ninastei/CCR/plc-2.0/lib:${newvar} 
endif
if !($?LD_LIBRARY_PATH) then
setenv LD_LIBRARY_PATH /user/ninastei/CCR/plc-2.0
else
set newvar=$LD_LIBRARY_PATH
set newvar=`echo ${newvar} | sed s@:/user/ninastei/CCR/plc-2.0:@:@g`
set newvar=`echo ${newvar} | sed s@:/user/ninastei/CCR/plc-2.0\$@@` 
set newvar=`echo ${newvar} | sed s@^/user/ninastei/CCR/plc-2.0:@@`  
set newvar=/user/ninastei/CCR/plc-2.0:${newvar}                     
setenv LD_LIBRARY_PATH /user/ninastei/CCR/plc-2.0:${newvar} 
endif
setenv CLIK_PATH /user/ninastei/CCR/plc-2.0

setenv CLIK_DATA /user/ninastei/CCR/plc-2.0/share/clik

setenv CLIK_PLUGIN rel2015

