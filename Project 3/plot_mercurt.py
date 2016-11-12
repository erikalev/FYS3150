import numpy as np
import matplotlib.pyplot as plt

infile = open("build-Cpp-Desktop-Release/perihelion.txt", "r")
perihelionNewton = []

for line in infile:
    words = line.split()
    perihelionNewton.append(float(words[0])*180*3600/np.pi)
infile.close()

infile = open("build-Cpp-Desktop-Release/perihelionGR.txt", "r")
perihelionGR = []

for line in infile:
    words = line.split()
    perihelionGR.append(float(words[0])*180*3600/np.pi)
infile.close()

infile = open("build-Cpp-Desktop-Release/perihelionGR_1mill.txt", "r")
perihelionGR_1mill = []

for line in infile:
    words = line.split()
    perihelionGR_1mill.append(float(words[0])*180*3600/np.pi)
infile.close()
infile = open("build-Cpp-Desktop-Release/perihelion_1mill.txt", "r")
perihelionNewton_1mill = []

for line in infile:
    words = line.split()
    perihelionNewton_1mill.append(float(words[0])*180*3600/np.pi)
infile.close()
infile = open("build-Cpp-Desktop-Release/perihelion_100k.txt", "r")
perihelionNewton_100k = []

for line in infile:
    words = line.split()
    perihelionNewton_100k.append(float(words[0])*180*3600/np.pi)
infile.close()


infile = open("build-Cpp-Desktop-Release/perihelionGR_100k.txt", "r")
perihelionGR_100k = []
for line in infile:
    words = line.split()
    perihelionGR_100k.append(float(words[0])*180*3600/np.pi)
infile.close()

print perihelionNewton[-1]-perihelionGR[-1]
print perihelionNewton_1mill[-1]-perihelionGR_1mill[-1]
print perihelionNewton_100k[-1]-perihelionGR_100k[-1]

time = np.linspace(0, 100, 415)
plt.plot(time, perihelionNewton, time, perihelionGR)
plt.xlabel("Time [Years]")
plt.ylabel("Angle [Arcseconds]")
plt.legend(["Without GR correction", "With GR-correction"])
plt.show()

plt.plot(time, perihelionNewton_1mill, time, perihelionGR_1mill)
plt.xlabel("Time [Years]")
plt.ylabel("Angle [Arcseconds]")
plt.legend(["Without GR correction", "With GR-correction"])
plt.show()

plt.plot(time, perihelionNewton_100k, time, perihelionGR_100k)
plt.xlabel("Time [Years]")
plt.ylabel("Angle [Arcseconds]")
plt.legend(["Without GR correction", "With GR-correction"])
plt.show()
