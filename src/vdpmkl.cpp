#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <chrono>
#include </util/academic/intel/17.0/compilers_and_libraries_2017/linux/mkl/include/mkl_cblas.h>


using namespace std;
int main(){
  unsigned int n;
  const int inc = 1;
  for (int i=0;i<29;i++){
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
    C = cblas_ddot(n,A,1,B,1);}
  auto end = std::chrono::high_resolution_clock::now();
  double t = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
  t = t*pow(10,-9)/100;
  double N = 8*n;
  double flops = 2*n/t;
  flops = flops*pow(10,-6);
  cout<<N<<'\t'<<flops<<'\n'<<endl;
  delete[] A;
  delete[] B;

  }
 return 0;
}
