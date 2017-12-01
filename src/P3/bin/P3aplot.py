import matplotlib.pyplot as plt
import read_plot as rp;

[x1,y1]=rp.read_plot("P3P1a.txt")
[x2,y2]=rp.read_plot("P3P2a.txt")
[x3,y3]=rp.read_plot("P3P3a.txt")

p1, = plt.plot(x1,y1,'--')
p2,= plt.plot(x2,y2,'.')
p3,=plt.plot(x3,y3,'-.')
plt.title("Mandelbrot Set Area as a function of grid size, h")
plt.legend([p1,p2,p3],["Serial","By rectangular region","Round Robin"],loc=0)
plt.show()
