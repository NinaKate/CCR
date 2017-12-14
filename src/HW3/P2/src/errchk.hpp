#include <stdio.h>
#include <mpi.h>
#include <string.h>
void errchk(int errcode,char* functname){
  if (errcode!=MPI_SUCCESS){
    int errclass;
    MPI_Error_class(errcode,&errclass);
    if (errclass==MPI_ERR_BUFFER){
      printf("Invalid buffer pointer in function call %s\n",functname);}
    else if (errclass==MPI_ERR_COUNT){
      printf("Invalid count argument in function call %s\n",functname);}
    else if (errclass==MPI_ERR_TYPE){
      printf("Invalid datatype argument in function call %s\n",functname);}
    else if (errclass==MPI_ERR_TAG){
      printf("Invalid tag argument in function call %s\n",functname);}
    else if (errclass==MPI_ERR_COMM){
      printf("Invalid communicator in function call %s\n",functname);}
    else if (errclass==MPI_ERR_RANK){
      printf("Invalid rank in function call %s\n",functname);}
    else if (errclass==MPI_ERR_REQUEST){
      printf("Invalid request (handle) in function call %s\n",functname);}
    else if (errclass==MPI_ERR_ROOT){
      printf("Invalid root in function call %s\n",functname);}
    else if (errclass==MPI_ERR_GROUP){
      printf("Invalid group in function call %s\n",functname);}
    else if (errclass==MPI_ERR_OP){
      printf("Invalid operation in function call %s\n",functname);}
    else if (errclass==MPI_ERR_TOPOLOGY){
      printf("Invalid topology in function call %s\n",functname);}
    else if (errclass==MPI_ERR_DIMS){
      printf("Invalid dimension argument in function call %s\n",functname);}
    else if (errclass==MPI_ERR_ARG){
      printf("Invalid argument of some other kind in function call %s\n",functname);}
    else if (errclass==MPI_ERR_UNKNOWN){
      printf("SOMETHING WEIRD went wrong in function call %s\n",functname);}
    else if (errclass==MPI_ERR_TRUNCATE){
      printf("Message truncated on receive in function call %s\n",functname);}
  else if (errclass==MPI_ERR_OTHER){
    printf("Some other (known) error in function call %s\n",functname);}
  else if (errclass==MPI_ERR_INTERN){
    printf("Internal MPI error in function call %s\n",functname);}
  else if (errclass==MPI_ERR_IN_STATUS){
    printf("Status error in function call %s, look in the status array\n",functname);}
  else if (errclass==MPI_ERR_PENDING){
    printf("Operation incomplete in function call %s\n",functname);}
  else if (errclass==MPI_ERR_KEYVAL){
    printf("Invalid keyval used in function call %s\n",functname);}
  else{
    printf("Something has gone wrong in a way unanticipated by this list of error classes in fun\
ction call %s. Sorry. \n",functname);}
}}
