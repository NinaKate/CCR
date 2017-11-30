# I am a comment, and I want to say that the variable CC will be 
# the compiler to use.                                                         
CC=mpicxx

loc = ../execs/
all: P1.mpi

P1.mpi: P1.cpp 
	$(CC) $^  -o $(loc)P1.mpi

clean:
	rm -rf $(loc)*
