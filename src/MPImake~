# I am a comment, and I want to say that the variable CC will be 
# the compiler to use.                                                         
CC=g++ -std=c++11
# Hey!, I am comment number 2. I want to say that CFLAGS will be the           
# options I'll pass to the compiler.                                           
LIBS=-I$(/lib64) -L$(/lib64) -lblas
sof = /lib64/libblas.so.3.4.2
head =  ./cblas.h

#This is me saying I want the version of std used to be c++11
all: vdprunnet  vdprunnet.o  vdpr0 vdpr3 vdprnt.o vdprnt

vdprunnet: vdprunnet.o $(sof) 
	$(CC) $^ $(LIBS) -o vdprunnet

vdprunnet.o: vdprunnet.cpp cblas.h
	$(CC) -c vdprunnet.cpp

vdpr0: vectordprun.cpp
	$(CC) -O0 $^ -o vdpr0.o

vdpr3: vectordprun.cpp
	$(CC) -O3 $^ -o vdpr3.o

vdprnt: vdpnettest.o $(sof)
	$(CC) $^ $(LIBS) -o vdprnt

vdprnt.o: vdpnettest.cpp cblas.h
	$(CC) -c vdpnettest.cpp

clean:
	rm -rf *o vdprunnet
