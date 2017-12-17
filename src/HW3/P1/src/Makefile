# I am a comment, and I want to say that the variable CC will be 
# the compiler to use.                                                         
CC=mpicxx -O0
loc = ../bin/

all: P1P1a.mpi P1P3a.mpi

P1P1a.mpi: P1P1a.cpp
	$(CC) $^ -o $(loc)P1P1a.mpi

P1P3a.mpi: P1P3a.cpp
	$(CC) $^ -o $(loc)P1P3a.mpi

clean:
	rm -rf  $(loc)*.mpi
