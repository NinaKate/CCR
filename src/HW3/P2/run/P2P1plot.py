
import matplotlib.pyplot as plt
import read_plot as rp;


[x,y]=rp.read_plot("P1P1a.txt")
yb = [0.0]*len(x)
for i in range(0,len(x)):
    yb[i]=y[0]/y[i]

p1,=plt.plot(x,y)
p2,=plt.plot(x,yb)
plt.legend([p1,p2],["Time","Speedup"])
plt.title("Time and Speedup as a function of core count, grid spacing 0.01")
plt.show()
