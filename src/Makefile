# I am a comment, and I want to say that the variable CC will be 
# the compiler to use.                                                         
CC=g++ -std=c++11
# Hey!, I am comment number 2. I want to say that CFLAGS will be the           
# options I'll pass to the compiler.                                           
LIBS=-I$(/lib64) -L$(/lib64) -lblas
sof = /lib64/libblas.so
head =  ./cblas.h

#This is me saying I want the version of std used to be c++11
all: vdprunnet  vdprunnet.o  vectordprun

vdprunnet: vdprunnet.o $(sof) 
	$(CC) $^ $(LIBS) -o vdprunnet

vdprunnet.o: vdprunnet.cpp cblas.h
	$(CC) -c vdprunnet.cpp

vectordprun: vectordprun.cpp
	$(CC) $^ -o vdprun
clean:
	rm -rf *o vdprunnet
