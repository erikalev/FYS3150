import numpy as np
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
"""
E_final = 0.0
M_final = 0.0
Mabs_final = 0.0
success_final = 0.0
max_cycles = 0
infile = open("build-cpp-Desktop-Release/final_values.txt", "r")
for line in infile:
    words = line.split()
    E_final = float(words[0])/400.0
    Mabs_final = float(words[1])/400.0
    max_cycles = int(words[2])
infile.close()
"""
"""
infile = open("build-cpp-Desktop-Release/temp_values.txt", "r")
E = np.zeros(max_cycles)
Mabs = np.zeros(max_cycles)
success = np.zeros(max_cycles)
i = 0
E_list = np.zeros(max_cycles)
bin_value = []
for line in infile:
    words = line.split()
    E[i] = float(words[0])/float(words[3])/400.0
    Mabs[i] = float(words[1])/float(words[3])
    success[i] = float(words[2])/400.0
    E_list[i] = float(words[4])
    if float(words[4]) not in bin_value:
        bin_value.append(float(words[4]))
    i += 1
    
binwidth = 4
plt.hist(E_list, bins=np.arange(min(E_list), max(E_list) + binwidth, binwidth), normed=1)
plt.xlabel("E")
plt.ylabel("P(E)")
plt.legend(["T = 1.0"])
plt.show()

infile = open("build-cpp-Desktop-Release/temp_values_T24.txt", "r")
ET24 = np.zeros(max_cycles)
MabsT24 = np.zeros(max_cycles)
successT24 = np.zeros(max_cycles)
i = 0

for line in infile:
    words = line.split()
    ET24[i] = float(words[0])/float(words[3])/400.0
    MabsT24 = float(words[1])/float(words[3])
    successT24[i] = float(words[2])/400.0
    i += 1
infile.close()

cycles = np.linspace(1, max_cycles, max_cycles)

plt.plot(np.log10(cycles), E, np.log10(cycles), ET24)
#plt.plot(cycles, E, cycles, ET24)
plt.ylabel("$<E>$")
#plt.ylabel("<|M|>")
plt.xlabel("log10(Monte Carlo cycles)")
plt.legend(["T = 1", "T = 2.4"])
plt.show()

plt.plot(np.log10(cycles), success)#, np.log10(cycles), successT24)#, np.log10(cycles), successT24)
plt.xlabel("Number of Monte Carlo cycles")
plt.ylabel("Accepted configurations/Suggested configurations")
plt.legend(["T = 1"])
plt.show()
plt.plot(np.log10(cycles), successT24)#, np.log10(cycles), successT24)#, np.log10(cycles), successT24)
plt.xlabel("Number of Monte Carlo cycles")
plt.ylabel("Accepted configurations/Suggested configurations")
plt.legend(["T = 2.4"])
plt.show()
"""
infile1 = open("build-cpp-Desktop-Debug/E_values20.txt", "r")
infile2 = open("build-cpp-Desktop-Debug/M_values20.txt", "r")
infile3 = open("build-cpp-Desktop-Debug/Cv_values20.txt", "r")
infile4 = open("build-cpp-Desktop-Debug/chi_values20.txt", "r")

N = 11
T = np.linspace(2.2, 2.3, N)

E40 = np.zeros(N)
M40 = np.zeros(N)
Cv40 = np.zeros(N)
chi40 = np.zeros(N)
i = 0
for line in infile1:
    words = line.split()
    E40[i] = float(words[0])
    i+=1
i=0
for line in infile2:
    words = line.split()
    M40[i] = float(words[0])
    i+=1
i=0
for line in infile3:
    words = line.split()
    Cv40[i] = float(words[0])
    i+=1
i=0
for line in infile4:
    words = line.split()
    chi40[i] = float(words[0])
    i+=1
"""
infile5 = open("build-cpp-Desktop-Release/E_values60.txt", "r")
infile6 = open("build-cpp-Desktop-Release/M_values60.txt", "r")
infile7 = open("build-cpp-Desktop-Release/Cv_values60.txt", "r")
infile8 = open("build-cpp-Desktop-Release/chi_values60.txt", "r")


E60 = np.zeros(N)
M60 = np.zeros(N)
Cv60 = np.zeros(N)
chi60 = np.zeros(N)
i = 0
for line in infile5:
    words = line.split()
    E60[i] = float(words[0])
    i+=1
i=0
for line in infile6:
    words = line.split()
    M60[i] = float(words[0])
    i+=1
i=0
for line in infile7:
    words = line.split()
    Cv60[i] = float(words[0])
    i+=1
i=0
for line in infile8:
    words = line.split()
    chi60[i] = float(words[0])
    i+=1
"""
plt.plot(T, E40)
plt.xlabel("T")
plt.ylabel("Cv")
plt.show()
