#include <mpi.h>
#include <iostream>
#include <stdio.h>
int main(int argc, char *argv[]){
  int rank, size,ierr,errclass;

  MPI_Init(&argc,&argv);
  //rank=MPI_COMM_WORLD.Get_rank();
  //size=MPI_COMM_WORLD.Get_size();
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  std::cout<<"this is a test"<<std::endl;
  printf("Hello world! I am %d of %d",rank,size);
  MPI_Finalize();
  return 0;
}
