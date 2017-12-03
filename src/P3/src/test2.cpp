#include <iostream>
#include <stdio.h>

int main(){
  float h = 0.005;
  int Nx = 4/h; //number of grid points per side in x                                                      
  int Ny = 2/h;
  int Ntot = Nx*Ny;
  int medcheck=0;
  int coarsecheck=0;
  float x=-2;
  float y=-1;
  int numpts = 0;
  for (int i=0; i<Nx;i++){
      medcheck = i%10; //this will only be zero every 0.05 in x and y, so those are my medium points  
      coarsecheck = i%20; //this one is only zero every 0.1 in x and y, my coarse points.
      if (coarsecheck ==0){std::cout<<i<<" is in all three sets"<<std::endl;}
      else if (medcheck ==0){std::cout<<i<<" is in the fine and medium sets"<<std::endl;}
      else {std::cout<<i<<" is in only the fine set"<<std::endl;}
  }
  return 0;
}
