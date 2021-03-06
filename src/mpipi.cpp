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
  double mypi,pi,h,sum,x,sum2,mypio,pi2;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 
  for (int j=1;j<size;j++){
    if (rank==0){
      n = 10000;}
    MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
    sum = 0.0;
      if (rank<j){
      h=1.0/(double)n;
      for (i=myid+1;i<=n;i += numprocs){
	x = h*((double)i-0.5);
	sum+=4*apple(x);
	//sum+=4*orange(x); //in case I decide I like the orange version better
      }}
      mypi=h*sum;
      MPI_Reduce(&mypi,&pi,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
      if (myid==0){
	printf("pi is approx %.16f, or %.16f if I use the oranges approx, this is processor %d \n",pi,pi2,myid);}

	 
  
  MPI_Finalize();

    
    return 0;
}
