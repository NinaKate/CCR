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
  MPI_Init(&argc,&argv);//cannot error check this one because I cannot change the error handler until it succeeds
  MPI_Comm_set_errhandler(MPI_COMM_WORLD,MPI_ERRORS_RETURN);//cannot error check this one because if it fails, I have not successfully changed error handler
  ierr = MPI_Comm_size(MPI_COMM_WORLD,&size);
  func = "MPI_Comm_size";
  errchk(ierr,func);
  ierr=MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  func="MPI_Comm_rank";
  errchk(ierr,func);
  // n = 100000000; //number of points to do
  // h = 1.0/(double)n;//spacing between points
  for (int j=1;j<=size;j++){//j is how many cores I am using
    ierr=MPI_Barrier(MPI_COMM_WORLD);//to make sure no one starts the next loop before everyone is ready to start
    func = "MPI_Barrier";
    errchk(ierr,func);
    t_start=MPI_Wtime();
    if (rank==0){n = 100000000;}
    ierr = MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
    func = "MPI_Bcast";
    errchk(ierr,func);
    ierr=MPI_Barrier(MPI_COMM_WORLD);
    func="MPI_Barrier";
    errchk(ierr,func);
    h = 1.0/(double)n;
    int maxtakes = j*j;
    for (int takes = 0;takes<maxtakes;takes++){
      sum =0.0;
      if (rank<j){//so only do the next bit if your rank is less than j
      for (i=rank+1;i<=n;i += j){
	x = h*((double)i-0.5);
	//sum+=4*apple(x);
	sum+=4*orange(x); //in case I decide I like the orange version better
      }}
      mypi=h*sum;
      ierr=MPI_Barrier(MPI_COMM_WORLD);//and to ensure that we don't reduce before everyone is ready
      func = "MPI_Barrier";
      errchk(ierr,func);
      ierr = MPI_Reduce(&mypi,&pi,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
      func = "MPI_Reduce";
      errchk(ierr,func);}
      t_stop=MPI_Wtime();
      if (rank==0){
	if (pi != 3.16){//this is me forcing the code to check the value so it does not skip the calculation
	  double time = (t_stop-t_start)/(double)maxtakes;
	  std::cout<<j<<'\t'<<time<<std::endl;}
	else{std::cout<<"ERROR! ERROR! TRADITIONAL JAPANESE PI DETECTED??"<<std::endl;}

      }}
  
  MPI_Finalize();
    return 0;
}
