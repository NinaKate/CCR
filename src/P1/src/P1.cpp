#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include "errchk.hpp"

int main(int argc, char *argv[]){
  int rank, size,ierr;
  char* func;
  MPI_Init(&argc,&argv);
  MPI_Comm_set_errhandler(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
  ierr=MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  func="MPI_Comm_rank";
  errchk(ierr,func);
  ierr=MPI_Comm_size(MPI_COMM_WORLD,&size);
  func="MPI_Comm_size";
  errchk(ierr,func);
  printf("Hello! This is process %d of %d, reporting for duty. \n",rank,size);
  ierr=MPI_Finalize();
  func="MPI_Finalize";
  errchk(ierr,func);
  return(0);

}
