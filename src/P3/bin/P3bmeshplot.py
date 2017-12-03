import matplotlib.pyplot as plt
import read_plot as rp;
import sys
import numpy as np
import scipy as sp

prefix=str(sys.argv[1])
coarse= prefix+"bcoarse.txt"
medium=prefix+"bmed.txt"
fine = prefix+"bfine.txt"
[x1,y1]=rp.read_plot(coarse)
[x2,y2]=rp.read_plot(medium)
[x3,y3]=rp.read_plot(fine)

#X1,Y1=np.ogrid[-1.0,1.0,0.1)
X1 = np.arange(-2.0,2.0,0.005)
Y1 = np.arange(-1.0,1.0,0.005)
Z1 = np.zeros((len(X1),len(Y1)))

for i in range(0,len(x3)):
	xi = int((2.0+x3[i])/0.005)
	yi = int((1.0+y3[i])/0.005)
	Z1[xi][yi]=1
plt.imshow(Z1.T,extent=[-2,2,-1,1])
plt.show();


