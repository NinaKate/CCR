#!
module load gcc/7.2.0

g++ -O0 matrixadd.cpp -o mmag0
echo The output for gcc, no optimization is:
./mmag0

g++ -O3 matrixadd.cpp -o mmag3
echo the output for gcc with maximal optimization is 
./mmag3

module unload gcc/7.2.0
module load intel/17.0

icpc -O0 matrixadd.cpp -o mmai0
echo the intel no-optimization result is
./mmai0

icpc -O3 matrixadd.cpp -o mmai3
echo the intel max optimization result is
./mmai3


