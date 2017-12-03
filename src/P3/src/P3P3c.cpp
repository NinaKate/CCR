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
  int rank,size,ierr;
  char * func;
  MPI_Init(&argc,&argv);
  MPI_Comm_set_errhandler(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
  ierr=MPI_Comm_size(MPI_COMM_WORLD,&size);
  func = "MPI_Comm_size";
  errchk(ierr,func);
  ierr=MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  func="MPI_Comm_rank";
  errchk(ierr,func);
  double t_start,t_stop;
   for (int n=4;n<size;n++){
    float h = 0.01;
    int Nx = 4/h; //number of grid points across the x axis
    int Ny = 2/h;
    int Ntot = Nx*Ny;
    int numpts = 0;
    ierr=MPI_Barrier(MPI_COMM_WORLD);
    func = "MPI_Barrier";
    errchk(ierr,func);
    t_start=MPI_Wtime();
    if (rank<n){
    float x=-2;
    float y=-1;
    for (int i=rank; i<Ntot;i+=n){
      int xi = int(i/Ny);
      int yi = i%Ny;
      x = -2 + h*xi;
      y = -1 + h*yi;
	if (Mandelbrot(x,y,10000)==true){
	  numpts +=1;
	}
	
      }
     
    }
    float myarea = numpts*h*h;
    float area = 0;
    ierr=MPI_Barrier(MPI_COMM_WORLD);
    func = "MPI_Barrier";
    errchk(ierr,func);
    ierr = MPI_Reduce(&myarea,&area,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
    func="MPI_Reduce";
    errchk(ierr,func);
    t_stop=MPI_Wtime();
    if(rank==0){ std::cout<<n<<'\t'<<(t_stop-t_start)<<std::endl; }
   }
  MPI_Finalize();
  return(0);
}
