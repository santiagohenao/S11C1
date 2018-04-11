import numpy as np
import matplotlib.pyplot as plt

data=np.genfromtxt("MIR.dat")

l=["t","S","R","I"]

plt.figure(figsize=(10,8))
for i in [1,2,3]:
    plt.plot(data[:,0],data[:,i],label=l[i])
    plt.scatter(data[:,0],data[:,i],s=3)
plt.legend(loc=4)
plt.grid("On")
plt.savefig("Solution.png",bbox_inches='tight')
