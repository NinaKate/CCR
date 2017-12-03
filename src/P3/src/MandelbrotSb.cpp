#include <stdio.h>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std;
vector<float> compsq(float real,float imag){
  float rsq = real*real-imag*imag;
  float imsq = 2*real*imag;
  vector<float>endsq;
  endsq.push_back(rsq);
  endsq.push_back(imsq);
  return endsq;
}
bool Mandelbrot(float ci,float cj, int N){
  float zm = 0;
  bool mand = true;
  vector<float>zvec;
  zvec.push_back(0);
  zvec.push_back(0);
  vector<float> c;
  c.push_back(ci);
  c.push_back(cj);
  float zsq;
  for (int n = 0;n<N;n++){
    vector<float>temp;
    temp = compsq(zvec[0],zvec[1]);
    zvec[0] = temp[0]+ci;
    zvec[1] = temp[1]+cj;
    zm = pow((zvec[0]*zvec[0] + zvec[1]*zvec[1]),0.5);
    if (zm>=2){
      mand = false;
      break;
    }
  }
  return mand;
}
int main(){
  ofstream coarse;
  ofstream med;
  ofstream fine;
  coarse.open("../bin/MandelbrotSbcoarse.txt");
  med.open("../bin/MandelbrotSbmed.txt");
  fine.open("../bin/MandelbrotSbfine.txt");
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
      x = -2 + h*i;
      for (int j = 0;j<Ny;j++){
	y = -1 + h*j;
	medcheck = i%10+j%10; //this will only be zero every 0.05 in x and y, so those are my medium points
	coarsecheck = i%20+j%20; //this one is only zero every 0.1 in x and y, my coarse points. 
	if (Mandelbrot(x,y,10000)==true){
	  fine<<x<<'\t'<<y<<std::endl;
	  if (coarsecheck==0){coarse<<x<<'\t'<<y<<std::endl;}
	  if (medcheck==0){med<<x<<'\t'<<y<<std::endl;}

	}
	}
       
    }
    

  coarse.close();
  med.close();
  fine.close();
  return(0);
}
