#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <chrono>
using namespace std;
int main(){
  unsigned int n;
  for (int i=0;i<23;i++){
    n=(pow(2.0,i));
  double *A = new double[n];
  double *B = new double[n];
  double C = 0;
  for(int k=0;k<n;k++){
    A[k]=1.0;
    B[k]=1.0;}
  auto begin = std::chrono::high_resolution_clock::now();
  for(int j = 0; j<100;j++){
  for (int i = 0;i<n;++i){
    C+= A[i] * B[i];}}
  auto end = std::chrono::high_resolution_clock::now();
  double t = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
  t = t*pow(10.,-9.)/100.;
  double N = 8*n;
  double flops = 2*n/t;
  flops = flops*pow(10.,-6.);
  cout<<N<<'\t'<<flops<<'\n'<<endl;
  if(C==100*n){}
  else{cout<<"WE HAVE A PROBLEM"<<endl;}
  delete[] A;
  delete[] B;

  }
 return 0;
}
