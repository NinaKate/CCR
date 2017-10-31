#include <mpi.h>
//#include <iostream>
#include <stdio.h>
using namespace std;

int main( int argc,char *argv[])
{

  int rank,size,len;
  char procname[MPI_MAX_PROCESSOR_NAME];
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Get_processor_name(procname,&len);
  printf("Hello, world, my name is Alice! Parallel is fun. Something process %d of %d on %s \n",rank,size,procname);

  MPI_Finalize();
  return 0;

}
