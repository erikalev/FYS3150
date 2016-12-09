# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
T_values = []
D_list = []
T_equilibrium = []
T_index = [513, 515, 517, 520, 530, 540, 545, 550]

timesteps = [i for i in range(60000)]
for index in T_index:
    filename = "/home/erik/FYS3150/build-molecular-dynamics-fys3150-Desktop-Release/statistics_" + str(index) + ".txt"
    infile = open(filename, "r")    
    N = 60000
    T_values.append(index)
    t = np.zeros(N)
    density = np.zeros(N)
    Diffusion = 0
    r2  = np.zeros(N)
    totalE  = np.zeros(N)
    K = np.zeros(N)
    V  = np.zeros(N)
    T = np.zeros(N)
    i = 0
    
    for line in infile:
        words = line.split()
        t[i] = float(words[0])
        density[i] = float(words[1])
        r2[i] = float(words[2])
        totalE[i] = float(words[3])
        K[i] = float(words[4])
        V[i] = float(words[5])
        T[i] = float(words[6])*119.735
        i+=1
        if i == N:
            break
    infile.close()
    T_sum = np.mean(T[int(N*8.0/10.0):N])
    T_equilibrium.append(index)

    D = 0
    r_val = r2[int(N*4.0/5.0):]
    t_val = t[int(N*4.0/5.0):]
    D = (r_val[-1] - r_val[0])/(t_val[-1] - t_val[0])
    D_list.append(D/6)

    plt.plot(timesteps, r2)    
    plt.xlabel("$time steps$")
    plt.ylabel("$<r^2(t)>$ [Angstrom^2]")
    infile.close()

plt.show()
plt.plot(T_equilibrium, D_list, "o")
plt.xlabel("Temperature")
plt.ylabel("Diffusion coefficient")
plt.show()
