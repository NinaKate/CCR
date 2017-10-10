#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;
int main(){
  int n;
  cout<<"Please provide N so I can create two NxN matrices "<<endl;
  cin>>n;
  short **A = new short*[n];
  short **B = new short*[n];
  short **C = new short*[n];
  for (size_t i = 0; i<n;i++){
    A[i] = new short[n];
    B[i] = new short[n];
    C[i] = new short[n];
  }
  for (size_t i=0;i<n;i++){
    for (size_t j=0;j<n;j++){
      A[i][j]=1;
      B[i][j]=1;
      C[i][j]=0;}}
  //first the row then column implementation
  clock_t t;
  t = clock();
  for (int i = 0; i<n;++i){
    for (int j = 0; j<n;++j){
      C[i][j]=A[i][j]+B[i][j];
    }
  }
  t = clock()-t;
  double T = (double)t/CLOCKS_PER_SEC;
  cout<<" the time it took to add two "<<n<<"x"<<n<<" matrices of integers with the rows loop inside the columns loop is " <<T<<endl;
  t = clock();
  for (int j = 0;j<n;++j)
    for (int i=0;i<n;++i){
      C[i][j]=A[i][j]+B[i][j];}
  t = clock()-t;
  T = (double)t/CLOCKS_PER_SEC;
  cout<<" the time it took to add two "<<n<<"x"<<n<<" matrices of integers with the columns loop inside the rows loop is "<<T<<endl;
  for (size_t i = n-1; i>0;--i){
    delete[] C[i];
    delete[] B[i];
    delete[] A[i];
  }
  delete[] C;
  delete[] B;
  delete[] A;
  return 0;
}
