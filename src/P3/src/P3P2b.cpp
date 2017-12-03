#include <mpi.h>
#include <stdio.h>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>
#include "errchk.hpp"
using namespace std;
vector<float> compsq(float real,float imag){
  float rsq = real*real-imag*imag;
  float imsq = 2*real*imag;
  vector<float>endsq;
  endsq.push_back(rsq);
  endsq.push_back(imsq);
  return endsq;
}
bool Mandelbrot(float ci,float cj, int N){
  float zm = 0;
  bool mand = true;
  vector<float>zvec;
  zvec.push_back(0);
  zvec.push_back(0);
  vector<float> c;
  c.push_back(ci);
  c.push_back(cj);
  float zsq;
  for (int n = 0;n<N;n++){
    vector<float>temp;
    temp = compsq(zvec[0],zvec[1]);
    zvec[0] = temp[0]+ci;
    zvec[1] = temp[1]+cj;
    zm = pow((zvec[0]*zvec[0] + zvec[1]*zvec[1]),0.5);
    if (zm>=2){
      mand = false;
      break;
    }
  }
  return mand;
}
int main(int argc,char*argv[]){
  int rank,size,ierr,xi,yi;
  char * func;
  MPI_Init(&argc,&argv);
  MPI_Comm_set_errhandler(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
  ierr=MPI_Comm_size(MPI_COMM_WORLD,&size);
  func ="MPI_Comm_size";
  errchk(ierr,func);
  ierr=MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  func="MPI_Comm_rank";
  errchk(ierr,func);
 //I am just doing vertical strips (it's simpler)
 
    float h;
    std::cin>>h;//spacing between grid points; I use 0.005 for fine, 0.05 for medium, and 0.25 for coarse.
    int Nx = 4/h; //number of grid points across the x-axis
    int Ny = 2/h; //number of grid points across the y-axis
    int Ntot = Nx*Ny;
    int Nperproc=Ntot/size; //number of grid points per processor
    int Nleftover=(Ntot%size); //leftover grid points
    int Nstart = rank*Nperproc;
    int Nend = Nstart+Nperproc;
    if(rank==size-1){Nend = Ntot;}//I am assigning the leftover grid points to the last processor
    float x=-2;
    float y=-1;
    for (int i=Nstart; i<Nend;i++){
      xi = int(i/Ny);
      yi = i%Ny;
      x = -2 + h*xi;
      y = -1 + h*yi;
	if (Mandelbrot(x,y,10000)==true){
	  std::cout<<x<<'\t'<<y<<std::endl;
	}
	
      }
    

  MPI_Finalize();
  return(0);
}
