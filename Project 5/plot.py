import numpy as np
import matplotlib.pyplot as plt
t_values = [500., 550., 600., 650., 700., 710., 720., 730., 740., 750., 760., 770., 780., 790., 800., 850., 900., 950., 1000.];
T_values = []
D_list = []
T_equilibrium = []

for index in xrange(300, 991, 10):
    filename = "/home/erik/MDDATA/build-molecular-dynamics-fys3150-Desktop-Release/statistics_" + str(index) + ".txt"
    print filename
    infile = open(filename, "r")    
    N = 2000
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

    T_equilibrium.append(sum(T[1000:])/len(T[1000:]))

    D = 0
    r_val = r2[int(N*4.0/5.0):]
    t_val = t[int(N*4.0/5.0):]
    
    #for i in xrange(1, len(r_val)):
        #D +=  (r_val[i]-r_val[i-1])/(t_val[i] - t_val[i-1])
    D = (r_val[-1] - r_val[0])/(t_val[-1] - t_val[0])
    #D_list.append(D/6.0/(len(r_val)-1))
    D_list.append(D/6)
    plt.plot(t, r2)
    plt.xlabel("$time$ $[s]$")
    plt.ylabel("$<r^2(t)>$ $[m^2]$")
    infile.close()

plt.ylabel("$Temperature$ $[K]$")
plt.xlabel("$time$ $[1.00224*10^{-13} s]$")
plt.show()
plt.plot([i/2 for i in T_values], D_list)
plt.xlabel("Temperature")
plt.ylabel("Diffusion coefficient")
plt.show()
