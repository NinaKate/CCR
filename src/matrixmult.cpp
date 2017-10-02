#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;
int main(){
  int n;
  cout<<"Please tell me the size of the vectors you want to test me on "<<endl;
  cin>>n;
  double *A = new double[n];
  double *B = new double[n];
  double C = 0;
  clock_t t;
  t = clock();
  for (int i = 0;i<n;++i){
    C+= A[i] * B[i];
}
  t = clock()-t;
  double T = (double)t/CLOCKS_PER_SEC;
  cout<<"The time it took to multiply two "<<n<<" long vectors is "<<T<<endl;
  delete[] A;
  delete[] B;


 return 0;
}
