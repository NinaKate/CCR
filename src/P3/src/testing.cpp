#include <iostream>
#include <fstream>
using namespace std;
int main(){
  ofstream myfirstfile;
  ofstream mysecondfile;
  int test = 42;
  myfirstfile.open("samedirectory.txt");
  mysecondfile.open("../bin/diffdirectory.txt");
  myfirstfile <<"datapoint 1 \n"<<std::endl;
  mysecondfile<<"a reference\n";
  std::cout<<"Just demonstrating that this does not have to go to the file"<<std::endl;
  myfirstfile<<"datapoint 2 of "<<test<<" \n";
  mysecondfile<<"and another reference\n";
  myfirstfile.close();
  mysecondfile.close();
  return 0;
}