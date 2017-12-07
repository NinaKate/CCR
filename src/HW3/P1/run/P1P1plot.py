
import matplotlib.pyplot as plt
import read_plot as rp;


[x,y]=rp.read_plot("P1P1a.txt")
yb = [0.0]*len(x)
for i in range(0,len(x)):
    yb[i]=y[0]/y[i]

plt.plot(x,y)
plt.plot(x,yb)
plt.title("Time and Speedup as a function of core count")
plt.show()
