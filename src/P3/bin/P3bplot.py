
import matplotlib.pyplot as plt
import read_plot as rp;
import sys

prefix=str(sys.argv[1])
coarse= prefix+"bcoarse.txt"
medium=prefix+"bmed.txt"
fine = prefix+"bfine.txt"
[x1,y1]=rp.read_plot(coarse)
[x2,y2]=rp.read_plot(medium)
[x3,y3]=rp.read_plot(fine)
fig,(ax1,ax2,ax3)=plt.subplots(3)
ca = 10*10
ax1.scatter(x1,y1,s=ca,marker='s')
#ax1.set_title("Coarse grid plot, h=0.25")
ma = 4*4
ax2.scatter(x2,y2,s=ma,marker='s')
#ax2.set_title("Medium grid plot, h=0.05")
ax3.scatter(x3,y3,s=0.1*0.1)
#ax3.set_title("Fine grid plot, h = 0.005")
plt.show()
