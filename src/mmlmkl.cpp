#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <chrono>
#include </util/academic/intel/17.0/compilers_and_libraries_2017/linux/mkl/include/mkl_cblas.h>
using namespace std;
int main(){
 
 int Nmax=14;
 double alpha,beta;
 alpha = 1.0;
 beta = 0.0;
  for (int N=0;N<Nmax;N++){
    int n = pow(2,N);
    unsigned int m = n*n;
  double *A = new double[m];
  double *B = new double[m];
  double *C = new double[m];
  for (int l=0;l<m;l++){
    A[l]=1.0;
    B[l]=1.0;
    C[l]=0.0;}    
 
  //clock_t t;
  //t = clock();
  auto begin = std::chrono::high_resolution_clock::now();
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,n, n, n, 1, A, n, B, n, 0, C, n);;
  auto end = std::chrono::high_resolution_clock::now();
  
  //t = clock()-t;
  // double T = (double)t;
  double bytes = pow(n,2)*8;
  double ops = 2*pow(n,3);
  double t = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
  double flops = ops / (t*pow(10,-9)) *pow(10,-6);
  //cout<<bytes<<'\t'<<T <<'\t'<<CLOCKS_PER_SEC<<'\n'<<endl;
  cout<<bytes<<'\t'<<flops<<'\n';
  for (int l=0;l<m;l++){
    A[l]=C[l];}
  delete[] C;
  delete[] B;
  delete[] A;
  } return 0;
}
