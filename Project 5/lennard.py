import numpy as np
import matplotlib.pyplot as plt

sigma = 3.405
epsilon = 1000
r = np.linspace(0.01, 4*sigma, 100000)
y = 4*epsilon*((sigma/r)**12 - (sigma/r)**6)
print (sigma/r)**12
plt.plot(r, y)
plt.show()
