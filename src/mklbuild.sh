#!
module load mkl
source $MKL/bin/mklvars.sh intel64
module load intel/17.0

icpc -O3 -std=c++11 -mkl mmlmkl.cpp -o mmlmkl3

icpc -std=c++11 -mkl mmlmkl.cpp -o mmlmkld

icpc -O3 -std=c++11 -mkl vdpmkl.cpp -o vdpmkl3

icpc -std=c++11 -mkl vdpmkl.cpp -o vdpmkld
