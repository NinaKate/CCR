
SHELL = /bin/sh
FORTRAN  = ['/usr/bin/gfortran'] -DGFORTRAN -ffixed-line-length-0 -ffree-line-length-0 -m64 -fPIC -shared
OPTS     =
DRVOPTS  = $(OPTS)
NOOPT    = -g -O0
TIMER    = INT_CPU_TIME

BLASLIB      = ../../libblas_clik.so
ARCH = ['/usr/bin/gfortran'] 
ARCHFLAGS = -DGFORTRAN -ffixed-line-length-0 -ffree-line-length-0 -m64 -shared -o
RANLIB = echo
LAPACKLIB    = liblapack_clik.so

