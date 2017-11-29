#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
int main(int argc, char** argv) {
  const int PING_PONG_LIMIT = 10;
  MPI_Status status;
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // We are assuming at least 2 processes for this task
  if (world_size != 2) {
    fprintf(stderr, "World size must be two for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int ping_pong_count = 0;
  int partner_rank = (world_rank + 1) % 2;
  int n = 10;
  std::vector<double> ping_pong;
  ping_pong.resize(n);
  for (int i=0;i<n;i++){ping_pong[i]=0.0;}
  while (ping_pong_count < PING_PONG_LIMIT) {
    if (world_rank == ping_pong_count % 2) {
      // Increment the ping pong count before you send it
      ping_pong_count++;
      ping_pong[0]=double(ping_pong_count);
      MPI_Send(&ping_pong[0], n, MPI_DOUBLE, partner_rank, 0, MPI_COMM_WORLD);
      printf("%d sent and incremented ping_pong_count %d to %d\n",
             world_rank, ping_pong_count, partner_rank);
    } else {
      MPI_Recv(&ping_pong[0], n, MPI_DOUBLE, partner_rank, 0, MPI_COMM_WORLD,
               &status);
      ping_pong_count=int(ping_pong[0]);
      printf("%d received ping_pong_count %d from %d\n",
             world_rank, ping_pong_count, partner_rank);
    }
  }
  MPI_Finalize();
}
