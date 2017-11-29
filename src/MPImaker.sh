#!/bin/bash
../mpisetup.sh
mpicxx MandelbrotMPI.cpp -o ../execs/Mand.mpi

mpicxx MandelbrotMPI2.cpp -o ../execs/Mand2.mpi

mpicxx MandelbrotMPI3.cpp -o ../execs/Mand3.mpi


echo Just compiled Mandelbrot and Mandelbrot2 mpi codes
