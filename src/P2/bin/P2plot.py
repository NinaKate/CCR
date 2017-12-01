
import matplotlib.pyplot as plt
import read_plot as rp;


[y,x]=rp.read_plot("P2a.txt")


plt.plot(x,y)
plt.title("Ping Pong Performance as a function of message size in bytes")
plt.show()
