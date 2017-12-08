
import matplotlib.pyplot as plt
import read_plot as rp;


[x,y]=rp.read_plot("P1P1a.txt")
yb = [0.0]*len(x)
for i in range(0,len(x)):
    yb[i]=y[0]/y[i]
fig,(ax1,ax2)=plt.subplots(2)
ax1.semilogy(x,y)
ax1.set_title("Runtime vs Core Count for Lexicographic Mandelbrot, grid spacing 0.01")
ax2.plot(x,yb)
ax2.set_title("Speedup vd Core Count for Lexicographic Mandelbrot, grid spacing 0.01")
#plt.legend([p1,p2],["Time","Speedup"])
#plt.title("Time and Speedup as a function of core count, grid spacing 0.01")
plt.show()
