#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <chrono>
using namespace std;
int main(){
  unsigned int n;
  for (int i=0;i<15;i++){
    n=(pow(4.0,i));
  double *A = new double[n];
  double *B = new double[n];
  double C = 0;
  
  auto begin = std::chrono::high_resolution_clock::now();
  for (int i = 0;i<n;++i){
    C+= A[i] * B[i];}
  auto end = std::chrono::high_resolution_clock::now();
  double t = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
  t = t*pow(10,-9);
  double N = 8*n;
  double flops = 2*n/t;
  flops = flops*pow(10,-6);
  cout<<N<<'\t'<<flops<<'\n'<<endl;
  delete[] A;
  delete[] B;

  }
 return 0;
}
