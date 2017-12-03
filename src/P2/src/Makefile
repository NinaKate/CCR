# I am a comment, and I want to say that the variable CC will be 
# the compiler to use.                                                         
CC=mpicxx

loc = ../execs/
all: P2.mpi

P2.mpi: P2.cpp 
	$(CC) $^  -o $(loc)P2.mpi

clean:
	rm -rf $(loc)*
