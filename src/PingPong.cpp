#include <iostream>
#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
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
  }
  //else{printf("Successfully accomplished %s",functname);}
}

int main(int argc,char*argv[]){
  int rank,size,ierr,target,max_volleys;
  long messagelength;
  double t_start,t_stop;
  char*func;
  //   std::vector<double>ball;
  MPI_Status status;
  MPI_Comm Comm =MPI_COMM_WORLD;
  MPI_Init(NULL,NULL);
  MPI_Comm_set_errhandler(Comm,MPI_ERRORS_RETURN);
  ierr=MPI_Comm_size(Comm,&size);
  func="MPI_Comm_size";
  errchk(ierr,func);
  ierr=MPI_Comm_rank(Comm,&rank);
  func="MPI_Comm_rank";
  errchk(ierr,func);
  //  printf("this is processor %d of %d, reporting for duty!",rank,size);
  //for (int j=0;j<7;j++){
  //messagelength=pow(10,j);
  messagelength = 1;
  // ball.resize(messagelength);
   double *ball=new double[messagelength];
  for (int i=0;i<messagelength;i++){
    ball[i]=0.0;}
  max_volleys=10;
  target = (rank+1)%2;
  t_start = MPI_Wtime();
  int volleys=0;
  while(volleys<=max_volleys){
    if(rank ==volleys % 2){
      volleys++;
      ball[0]=double(volleys);
      ierr=MPI_Send(&ball,messagelength,MPI_DOUBLE,target,0,Comm);
      func="MPI_Send\n";
      errchk(ierr,func);
      printf("%d sent the ball, volley count %d,to %d \n",rank,volleys,target);
}else{
      ierr=MPI_Recv(&ball,messagelength,MPI_DOUBLE,target,0,Comm,MPI_STATUS_IGNORE);
      func="MPI_Recv\n";
      errchk(ierr,func);
      volleys = int(ball[0]);
      printf("%d received the ball, volley count %d, from %d \n",rank,volleys,target);
    }
  }
  t_stop=MPI_Wtime();
  if(rank==0){std::cout<<"To you, from failing hands, we throw the ball. it took "<<(t_stop-t_start)/max_volleys<<" per volley, for a message of "<<8*messagelength<<" bytes."<<std::endl;}
   delete[] ball;
  //}

  ierr=MPI_Finalize();
return 0;
}
