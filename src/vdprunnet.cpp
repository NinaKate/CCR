#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <chrono>
//#include "cblas.h"

extern "C" {
  double ddot_(const int *N, const double *a, const int *inca, const double *b, const int *incb);}
using namespace std;
int main(){
  unsigned int n;
  const int inc = 1;
  for (int i=0;i<25;i++){
    n=(pow(2.0,i));
    const int m = n;
    double *A = new double[n];
  double *B = new double[n];
  double C = 0;
  for (int k=0;k<n;k++){
    A[k]=1.0;
    B[k]=1.0;}  
  auto begin = std::chrono::high_resolution_clock::now();
  for (int j =0;j<100;j++){
    C = ddot_(&m,A,&inc,B,&inc);}
  auto end = std::chrono::high_resolution_clock::now();
  double t = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
  t = t*pow(10,-9)/100;
  double N = 8*n;
  double flops = 2*n/t;
  flops = flops*pow(10,-6);
  cout<<N<<'\t'<<flops<<'\n'<<endl;
  if (C==n){}
  else{cout<<"SOMETHING WENT WRONG"<<endl;}
  delete[] A;
  delete[] B;

  }
 return 0;
}
