import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("burgers.dat")

dataM = np.reshape(data, (-1, 30))

plt.figure()
for dat in dataM:
    plt.plot(np.linspace(0,4,num=401),dataM)
plt.savefig("burgers.pdf")
