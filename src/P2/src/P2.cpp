#include <iostream>
#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "errchk.hpp"

int main(int argc,char*argv[]){
  int rank,size,ierr,target,max_volleys;
  long messagelength;
  double t_start,t_stop;
  char*func;
  std::vector<double>ball;
  MPI_Status status;
  MPI_Comm Comm =MPI_COMM_WORLD;
  MPI_Init(&argc,&argv);
  MPI_Comm_set_errhandler(Comm,MPI_ERRORS_RETURN);
  ierr=MPI_Comm_size(Comm,&size);
  func="MPI_Comm_size";
  errchk(ierr,func);
  ierr=MPI_Comm_rank(Comm,&rank);
  func="MPI_Comm_rank";
  errchk(ierr,func);
  //  printf("this is processor %d of %d, reporting for duty!",rank,size);
  for (int j=0;j<20;j++){
  messagelength=pow(2,j);
  //messagelength = 1;
  ball.resize(messagelength);
  // double *ball=new double[messagelength];
  for (int i=0;i<messagelength;i++){
    ball[i]=0.0;}
  max_volleys=10;
  target = (rank+1)%2;
  t_start = MPI_Wtime();
  int volleys=0;
  while(volleys<=(2*max_volleys)){
    if(rank ==volleys % 2){
      volleys++;
      ball[0]=double(volleys);
      ierr=MPI_Send(&ball[0],messagelength,MPI_DOUBLE,target,0,Comm);
      func="MPI_Send\n";
      errchk(ierr,func);
      //printf("%d sent the ball, volley count %d,to %d \n",rank,volleys,target);
}else{
      ierr=MPI_Recv(&ball[0],messagelength,MPI_DOUBLE,target,0,Comm,&status);
      func="MPI_Recv\n";
      errchk(ierr,func);
      volleys = int(ball[0]);
      //printf("%d received the ball, volley count %d, from %d \n",rank,volleys,target);
    }
  }
  t_stop=MPI_Wtime();
  if(rank==0){std::cout<<(t_stop-t_start)/max_volleys<<'\t'<<8*messagelength<<std::endl;}
  // delete[] ball;
  }

  ierr=MPI_Finalize();
return 0;
}
