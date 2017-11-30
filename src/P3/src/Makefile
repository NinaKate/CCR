# I am a comment, and I want to say that the variable CC will be 
# the compiler to use.                                                         
CC=mpicxx
CC1=g++ -std=c++11

loc = ../execs/

all: P3P1a.o P3P1b.o P3P2a.mpi P3P2b.mpi P3P2c.mpi P3P3a.mpi

P3P1a.o: P3P1a.cpp
	$(CC1) $^  -o $(loc)P3P1a.o

P3P1b.o: P3P1b.cpp 
	$(CC1) $^  -o $(loc)P3P1b.o

P3P2a.mpi: P3P2a.cpp
	$(CC) $^ -o $(loc)P3P2a.mpi

P3P2b.mpi: P3P2b.cpp
	$(CC) $^ -o $(loc)P3P2b.mpi

P3P2c.mpi: P3P2c.cpp
	$(CC) $^ -o $(loc)P3P2c.mpi

P3P3a.mpi: P3P3a.cpp
	$(CC) $^ -o $(loc)P3P3a.mpi
clean:
	rm -rf $(loc)*.o $(loc)*.mpi
