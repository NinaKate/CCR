
import matplotlib.pyplot as plt
import read_plot as rp;
import numpy as np

[x,y]=rp.read_plot("P1P1a.txt")
yb = [0.0]*len(x)
yc = [0.0]*len(x)
xt = [0.0]*len(x)
for i in range(0,len(x)):
    yb[i]=y[0]/y[i]
    xt[i]=1./x[i]
m, b = np.polyfit(xt, y, 1) #I'm doing a linear best fit to 1/p vs T(p)
for i in range(0,len(x)):
    yc[i] = b + m/x[i]#generate the best fit line to plot against the data to make sure it looks right
bestfit = "with a $T_s$ of "+str(b)+" and a $T_p$ of "+str(m)
fig,(ax1,ax2)=plt.subplots(2,figsize=(12,24))
p1,=ax1.semilogy(x,y)
p2,=ax1.semilogy(x,yc)
ax1.set_title("Runtime vs Core Count for Lexicographic Mandelbrot, grid spacing 0.01")
ax1.legend([p1,p2],["Data","Best Fit for Serial Fraction "+bestfit])
ax1.set_ylim(0.75,65)
ax2.plot(x,yb)
ax2.set_title("Speedup vs Core Count for Lexicographic Mandelbrot, grid spacing 0.01")
#plt.legend([p1,p2],["Time","Speedup"])
#plt.title("Time and Speedup as a function of core count, grid spacing 0.01")
plt.show()
