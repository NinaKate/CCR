
import matplotlib.pyplot as plt
import read_plot as rp;


[x,y]=rp.read_plot("P1P3a.txt")
yb = [0.0]*len(x)
yc = [0.0]*len(x)
for i in range(0,len(x)):
    yb[i]=y[0]/y[i]
    yc[i]=yb[i]*x[i]
fig,(ax1,ax2,ax3)=plt.subplots(3)
ax1.plot(x,y)
ax1.set_title("Runtime vs Core Count for Lexicographic Mandelbrot, with 800 grid points per processor")

ax2.plot(x,yb)
ax2.set_title("Speedup vs Core Count for Lexicographic Mandelbrot, 800 grid points per processor")

ax3.plot(x,yc)
ax3.set_title("Speedup*Core Count vs Core Count for Lexicographic Mandelbrot, 800 grid points per processor")
plt.show()
