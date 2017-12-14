# I am a comment, and I want to say that the variable CC will be 
# the compiler to use.                                                         
CC=mpicxx 
loc = ../bin/

all: P2P1a.mpi P2P3a.mpi

P2P1a.mpi: P2P1a.cpp
	$(CC) $^ -o $(loc)P2P1a.mpi

P2P3a.mpi: P2P3a.cpp
	$(CC) $^ -o $(loc)P2P3a.mpi

clean:
	rm -rf  $(loc)*.mpi
