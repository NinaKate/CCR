//
//  HPC03.cpp
//  
//
//  Created by Nina Stein on 9/5/17.
//
//

#include <stdio.h>
#include <mpi.h>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>
#include <iostream>

double apple (double x){
    double ans;
    double arg = 1-x*x;
    ans = sqrt(arg);
    return ans;
}
double orange (double x){
  double ans2;
  double temp = 1+x*x;
  ans2 = 1/temp;
  return ans2;
}

int main(int argc,char*argv[]){
  int n,rank,size,i;
  double mypi,pi,h,sum,x,t_start,t_stop;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  // n = 100000;
  // h = 1.0/(double)n;
  for (int j=1;j<size;j++){
    MPI_Barrier(MPI_COMM_WORLD);
    t_start=MPI_Wtime();
    if (rank==0){n = 100000*j;}
    MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    h = 1.0/(double)n;
    int maxtakes = j*10;
    for (int takes = 0;takes<maxtakes;takes++){
      sum =0.0;
      if (rank<j){
      for (i=rank+1;i<=n;i += j){
	x = h*((double)i-0.5);
	sum+=4*apple(x);
	//sum+=4*orange(x); //in case I decide I like the orange version better
      }}
      mypi=h*sum;
      MPI_Barrier(MPI_COMM_WORLD);
      MPI_Reduce(&mypi,&pi,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
      t_stop=MPI_Wtime();}
      if (rank==0){
	if (pi != 3.16){//this is me forcing the code to check the value so it does not skip the calculation
	  std::cout<<j<<'\t'<<(t_stop-t_start)/(maxtakes)<<std::endl;}

      }}
  
  MPI_Finalize();

    
    return 0;
}
