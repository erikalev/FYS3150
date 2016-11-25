import numpy as np
import matplotlib.pyplot as plt
t_values = [500., 550., 600., 650., 700., 710., 720., 730., 740., 750., 760., 770., 780., 790., 800., 850., 900., 950., 1000.];
T_equilibrium = [i/2 for i in t_values]
print "statistics_" + str(0) + ".txt"
D_list = []
for index in xrange(19):
    infile = open("../build-molecular-dynamics-fys3150-Desktop-Release/statistics_" + str(index) + ".txt", "r")
    N = 5000
    t = np.zeros(N)
    density = np.zeros(N)
    Diffusion = 0
    r2  = np.zeros(N)
    totalE  = np.zeros(N)
    K = np.zeros(N)
    V  = np.zeros(N)
    i = 0
    for line in infile:
        words = line.split()
        t[i] = float(words[0])
        density[i] = float(words[1])
        r2[i] = float(words[2])
        totalE[i] = float(words[3])
        K[i] = float(words[4])
        V[i] = float(words[5])
        i+=1
        if i == N:
            break
    infile.close()
    t_val = t[int(N*4.0/5.0):]
    r_val = r2[int(N*4.0/5.0):]
    D_list.append((r_val[-1]-r_val[0])/(t_val[-1] - t_val[0]))

    plt.plot(t, r2)
    plt.xlabel("$time$ $[s]$")
    plt.ylabel("$<r^2(t)>$ $[m^2]$")

plt.show()

plt.plot(T_equilibrium, D_list)
plt.xlabel("Temperature")
plt.ylabel("Diffusion coefficient")
plt.show()
