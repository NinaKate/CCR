
import matplotlib.pyplot as plt
import read_plot as rp;


[x2,y2]=rp.read_plot("P3P2c.txt")
[x3,y3]=rp.read_plot("P3P3c.txt")


p2,= plt.plot(x2,y2,'.')
p3,=plt.plot(x3,y3,'-.')
plt.title("Time to calculate mandelbrot set area as a function of processors used")
plt.legend([p2,p3],["By rectangular region","Round Robin"],loc=0)
plt.show()
