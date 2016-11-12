import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import argrelextrema

infile = open("build-Cpp-Desktop-Debug/variables.txt", "r")
number_of_planets = 0
steps = 0
for line in infile:
    words = line.split()
    steps = int(words[0])
    number_of_planets = int(words[1])
infile.close()

infile = open("build-Cpp-Desktop-Debug/positions.xyz", "r")
i = 0
dim = 0
step = -1
system1 = np.zeros((number_of_planets, 3, steps))

for line in infile:
    words = line.split()
    if len(words) == 1:
        i = 0
        step += 1        
    else:
        dim = 1
        for dim in xrange(1, len(words)):
            system1[i, dim-1, step] = float(words[dim])
        i += 1
infile.close()


"""
plt.plot(system1[0,0,:], system1[0, 1,:])
plt.show()
"""

length = np.zeros((steps))
perihelion = []
theta = []
perihelion.append(system1[0,:,0])
theta.append(np.arctan2(system1[0,1,0],system1[0,0,0]))

for i in xrange(steps):
    length[i] = np.linalg.norm(system1[0,:,i])

index = argrelextrema(length, np.less)

for i in index[0]:
    perihelion.append(system1[0,:,i])
    theta.append(np.arctan2(system1[0,1,i],system1[0,0,i]))
print theta

times = np.linspace(0, 1, len(theta))
plt.plot(times, theta)
plt.xlabel("Time [Yr]")
plt.ylabel("Angle $\\theta$")
plt.legend(["Theta with GR-correction"])
plt.show()

x = np.zeros(len(perihelion))
y = np.zeros(len(perihelion))
for i in xrange(len(perihelion)):
    x[i] = np.linalg.norm(perihelion[i])*np.cos(theta[i])
    y[i] = np.linalg.norm(perihelion[i])*np.sin(theta[i])
plt.plot(x, y, "o")
plt.xlabel("x-coordinate [AU]")
plt.ylabel("y-coordinate [AU]")
plt.axis("equal")
plt.legend(["Perihelion with GR-correction"])
plt.show()
