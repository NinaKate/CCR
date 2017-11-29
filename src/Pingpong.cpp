#include <iostream>
#include <stdio.h>
#include <mpi.h>
#include <string.h>
void errchk(int errcode,char* functname){
  if (errcode!=MPI_SUCCESS){
    int errclass;
    MPI_Error_class(errcode,&errclass);
    if (errclass==MPI_ERR_BUFFER){
      printf("Invalid buffer pointer in function call %s",functname);}
    else if (errclass==MPI_ERR_COUNT){
      printf("Invalid count argument in function call %s",functname);}
    else if (errclass==MPI_ERR_TYPE){
      printf("Invalid datatype argument in function call %s",functname);}
    else if (errclass==MPI_ERR_TAG){
      printf("Invalid tag argument in function call %s",functname);}
    else if (errclass==MPI_ERR_COMM){
      printf("Invalid communicator in function call %s",functname);}
    else if (errclass==MPI_ERR_RANK){
      printf("Invalid rank in function call %s",functname);}
    else if (errclass==MPI_ERR_REQUEST){
      printf("Invalid request (handle) in function call %s",functname);}
    else if (errclass==MPI_ERR_ROOT){
      printf("Invalid root in function call %s",functname);}
    else if (errclass==MPI_ERR_GROUP){
      printf("Invalid group in function call %s",functname);}
    else if (errclass==MPI_ERR_OP){
      printf("Invalid operation in function call %s",functname);}
    else if (errclass==MPI_ERR_TOPOLOGY){
      printf("Invalid topology in function call %s",functname);}
    else if (errclass==MPI_ERR_DIMS){
      printf("Invalid dimension argument in function call %s",functname);}
    else if (errclass==MPI_ERR_ARG){
      printf("Invalid argument of some other kind in function call %s",functname);}
    else if (errclass==MPI_ERR_UNKNOWN){
      printf("SOMETHING WEIRD went wrong in function call %s",functname);}
    else if (errclass==MPI_ERR_TRUNCATE){
      printf("Message truncated on receive in function call %s",functname);}
    else if (errclass==MPI_ERR_OTHER){
      printf("Some other (known) error in function call %s",functname);}
    else if (errclass==MPI_ERR_INTERN){
      printf("Internal MPI error in function call %s",functname);}
    else if (errclass==MPI_ERR_IN_STATUS){
      printf("Status error in function call %s, look in the status array",functname);}
    else if (errclass==MPI_ERR_PENDING){
      printf("Operation incomplete in function call %s",functname);}
    else if (errclass==MPI_ERR_KEYVAL){
      printf("Invalid keyval used in function call %s",functname);}
    else{
      printf("Something has gone wrong in a way unanticipated by this list of error classes in fun\
ction call %s. Sorry.",functname);}
  }}

int main(int argc,char*argv[]){
  int rank,size,ierr,target;
  double ball;
  char*func;
  MPI_Status status;
  MPI_Comm Comm =MPI_COMM_WORLD;
  double t_start,t_stop;
  MPI_Init(&argc,&argv);
  MPI_Comm_set_errhandler(Comm,MPI_ERRORS_RETURN);
  ierr=MPI_Comm_size(Comm,&size);
  func="MPI_Comm_size";
  errchk(ierr,func);
  ierr=MPI_Comm_rank(Comm,&rank);
  func="MPI_Comm_rank";
  errchk(ierr,func);
  int volleys=0;
  int maxvolley=100;
  if (rank==0)
    ball = 42.0;
  t_start = MPI_Wtime();
  while(volleys<maxvolley){
  if (rank==0){
    ierr=MPI_Send(&ball,1,MPI_DOUBLE,1,9,Comm);
    func="MPI_Send to 1 from 0 \n";
    errchk(ierr,func);
  }
  
  if (rank==1){
    ierr=MPI_Recv(&ball,1,MPI_DOUBLE,0,9,Comm,&status);
    func="MPI_Recv by 1 from 0 \n";
    errchk(ierr,func);
    std::cout<<"Proc 1 Ball get! Ball value is "<<ball<<"!"<<std::endl;
    ball=ball+1.0;
    ierr=MPI_Send(&ball,1,MPI_DOUBLE,0,9,Comm);
    func="MPI_Send to 0 from 1\n";
    errchk(ierr,func);
    std::cout<<"Ball Passed on! Ball value is "<<ball<<"!"<<std::endl;
    }
  
  if (rank==0){
    ierr=MPI_Recv(&ball,1,MPI_DOUBLE,1,9,Comm,&status);
    func="MPI_Recv by 1 from 0\n";
    errchk(ierr,func);
    std::cout<<"Proc 0 Ball get! Ball value is "<<ball<<" !"<<std::endl;
    ball=ball+1;
  }
  volleys+=1;
 }
  t_stop=MPI_Wtime();
  if(rank==0)
    std::cout<<"To you, from failing hands, we throw the ball. it took "<<(t_stop-t_start)/maxvolley<<" per volley."<<std::endl;
  ierr=MPI_Finalize();
return 0;
}
