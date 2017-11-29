#include <mpi.h>
#include <stdio.h>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std;
vector<float> compsq(float real,float imag){
  float rsq = real*real-imag*imag;
  float imsq = 2*real*imag;
  vector<float>endsq;
  endsq.push_back(rsq);
  endsq.push_back(imsq);
  return endsq;
}
void checkerr(int errval){
  if (errval != MPI_SUCCESS)
    printf("ERROR! ERROR! \n");
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
  MPI_Init(&argc,&argv);
  MPI_Comm_set_errhandler(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
  ierr=MPI_Comm_size(MPI_COMM_WORLD,&size);
  checkerr(ierr);
  ierr=MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  checkerr(ierr);
  float recsize = 4.0/size; //I am just doing vertical strips (it's simpler)
  //  if (rank==0){std::cout<<recsize<<std::endl;}
   for (int i=4;i<10;i++){
  float h = pow(2,-i);//spacing between grid points
    int Ntot = 4.0/h; //number of grid points across the x-axis
    int Nperproc=Ntot/size; //number of grid points per processor
    int Nleftover=size*(Ntot%size); //leftover grid points
    int Nstart = rank*Nperproc;
    int Nend = Nstart+Nperproc;
    if(rank==size){
      Nend = Ntot;}
    float Ny = 2.0/h;
    float x=-2+rank*recsize;
    float y=-1;
    vector<float>real;
    vector<float>imaginary;
    int numpts = 0;
    for (int i=rank; i<Ntot;i+=size){
      for (int j = 0;j<Ny;j++){
	if (Mandelbrot(x,y,1000)==true){
	  real.push_back(x);
	  imaginary.push_back(y);
	  //                cout<<x<<","<<y<<endl;
	  numpts +=1;
	}
	y = -1 + h*j;
      }
      x = -2 + h*i;
    }
    //int maxpts = 3333;
    //printf("Alright, so processor %d of %d has found %d points, of a maximum of %d \n",rank,size,numpts,maxpts);
    // long ptstotal;
    float myarea = numpts*h*h;
    float area = 0;
    ierr = MPI_Reduce(&myarea,&area,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
    checkerr(ierr);
    if(rank==0){
  
      std::cout<<h<<'\t'<<area<<std::endl;
    }}
  MPI_Finalize();
  return(0);
}
