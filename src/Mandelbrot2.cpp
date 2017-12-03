//
//  Mandelbrot.cpp
//  
//
//  Created by Nina Stein on 9/17/17.
//
//

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
    vector<vector<float> > plot;
    vector<float>point;
    float h = 0.25;
    point.push_back(h);
    //float h = 0.01;//spacing between grid points
    float Nx = 4/h; //number of grid points per side in x
    float Ny = 3/h;
    float x=-2;
    float y=-1;
    vector<float>real;
    vector<float>imaginary;
    int numpts = 0;
    for (int i=0; i<Nx;i++){
        for (int j = 0;j<Ny;j++){
            if (Mandelbrot(x,y,10000)==true){
                real.push_back(x);
                imaginary.push_back(y);
//                cout<<x<<","<<y<<endl;
                numpts +=1;
            }
            y = -1 + h*j;
        }
        x = -2 + h*i;
    }
    float area=numpts*h*h;
        point.push_back(area);
        plot.push_back(point);
        
        //printf("The area of the mandelbrot set is %f according to this, for a grid size of %f. And yeah, I have no idea what the units should be here. ",area,h);
        //std::cout<<h<<'\t'<<area<<std::endl;
        for (int i=0;i<numpts;i++){
            std::cout<<real[i]<<'\t'<<imaginary[i]<<std::endl;
        }
        
    return(0);
}
