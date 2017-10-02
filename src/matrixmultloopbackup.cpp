#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;
int main(){
  int Nmax=10;
  for (int N=0;N<Nmax;N++){
    int n = pow(2,N);
  double **A = new double*[n];
  double **B = new double*[n];
  double **C = new double*[n];
  for (size_t i = 0; i<n;i++){
    A[i] = new double[n];
    B[i] = new double[n];
    C[i] = new double[n];
  }
    
    
  //clock_t t;
  //t = clock();
  auto begin = std::chrono::high_resolution_clock::now();
  for (int i = 0; i<n;++i){
    for (int j = 0; j<n;++j){
      for (int k=0;k<n;++k){
	C[i][j]+=A[i][k]*B[k][j];}
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  
  //t = clock()-t;
  // double T = (double)t;
  double bytes = pow(n,2)*3*8;
  //cout<<bytes<<'\t'<<T <<'\t'<<CLOCKS_PER_SEC<<'\n'<<endl;
  cout<<bytes<<'\t'<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()<<'ns'<<'\n';
  for (size_t i = n-1; i>0;--i){
    delete[] C[i];
    delete[] B[i];
    delete[] A[i];
  }
  delete[] C;
  delete[] B;
  delete[] A;
  } return 0;
}
