
import matplotlib.pyplot as plt
import read_plot as rp;


[x,y]=rp.read_plot("P2P1a.txt")
yb = [0.0]*len(x)
for i in range(0,len(x)):
    yb[i]=y[0]/y[i]

fig,(ax1,ax2)=plt.subplots(2)
ax1.semilogy(x,y)
ax1.set_title("Time as a function of Core Count")
ax2.semilogy(x,yb)
ax2.set_title("Speedup as a function of Core Count")

#p2,=plt.plot(x,yb)
#plt.legend([p1,p2],["Time","Speedup"])
#plt.title("Time and Speedup as a function of core count")
plt.show()
