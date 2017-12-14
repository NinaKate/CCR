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
#include "errchk.hpp"
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
  int n,rank,size,i,ierr;
  double mypi,pi,h,sum,x,t_start,t_stop;
  char * func;
  MPI_Init(&argc,&argv);
  MPI_Comm_set_errhandler(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
  ierr = MPI_Comm_size(MPI_COMM_WORLD,&size);
  func = "MPI_Comm_size";
  errchk(ierr,func);
  ierr = MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  func = "MPI_Comm_rank";
  errchk(ierr,func);
  // n = 100000;
  // h = 1.0/(double)n;
  for (int j=1;j<=size;j++){
    ierr=MPI_Barrier(MPI_COMM_WORLD); //NOBODY STARTS UNTIL WE ARE ALL READY. 
    func = "MPI_Barrier";
    errchk(ierr,func); 
    t_start=MPI_Wtime();
    if (rank==0){n = 10000000*j;}
    ierr=MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
    func = "MPI_Bcast";
    errchk(ierr,func);
    h = 1.0/(double)n;
    int maxtakes = 3;//j*j;
    for (int takes = 0;takes<maxtakes;takes++){
      sum =0.0;
      if (rank<j){
      for (i = rank + 1 ; i <= n ;i += j){
	x = h*((double)i-0.5);
	sum+=4*apple(x);
	//sum+=4*orange(x); //in case I decide I like the orange version better
      }}
      mypi=h*sum;
      ierr=MPI_Barrier(MPI_COMM_WORLD);//Do not reduce until everyone is ready
      func = "MPI_Barrier";
      errchk(ierr,func);
      ierr = MPI_Reduce(&mypi,&pi,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
      func = "MPI_Reduce";
      errchk(ierr,func);
    }
    t_stop=MPI_Wtime();//this goes OUTSIDE the takes loop
      if (rank==0){
	if (pi != 3.16){//this is me forcing the code to check the value so it does not skip the calculation
	  double time = (t_stop-t_start)/(double)maxtakes;
	  std::cout<<j<<'\t'<<time<<std::endl;}

      }}
  
  MPI_Finalize();

    
  return (0);
}
