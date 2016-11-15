import numpy as np
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab

infile1 = open("build-cpp-Desktop-Debug/E_values20.txt", "r")
infile2 = open("build-cpp-Desktop-Debug/M_values20.txt", "r")
infile3 = open("build-cpp-Desktop-Debug/Cv_values20.txt", "r")
infile4 = open("build-cpp-Desktop-Debug/chi_values20.txt", "r")

N = 11
T = np.linspace(2.2, 2.3, N)

E20 = np.zeros(N)
M20 = np.zeros(N)
Cv20 = np.zeros(N)
chi20 = np.zeros(N)
i = 0
for line in infile1:
    words = line.split()
    E20[i] = float(words[0])
    i+=1
i=0
for line in infile2:
    words = line.split()
    M20[i] = float(words[0])
    i+=1
i=0
for line in infile3:
    words = line.split()
    Cv20[i] = float(words[0])
    i+=1
i=0
for line in infile4:
    words = line.split()
    chi20[i] = float(words[0])
    i+=1

infile5 = open("build-cpp-Desktop-Debug/E_values40.txt", "r")
infile6 = open("build-cpp-Desktop-Debug/M_values40.txt", "r")
infile7 = open("build-cpp-Desktop-Debug/Cv_values40.txt", "r")
infile8 = open("build-cpp-Desktop-Debug/chi_values40.txt", "r")

E40 = np.zeros(N)
M40 = np.zeros(N)
Cv40 = np.zeros(N)
chi40 = np.zeros(N)
i = 0
for line in infile5:
    words = line.split()
    E40[i] = float(words[0])
    i+=1
i=0
for line in infile6:
    words = line.split()
    M40[i] = float(words[0])
    i+=1
i=0
for line in infile7:
    words = line.split()
    Cv40[i] = float(words[0])
    i+=1
i=0
for line in infile8:
    words = line.split()
    chi40[i] = float(words[0])
    i+=1

infile9 = open("build-cpp-Desktop-Debug/E_values60.txt", "r")
infile10 = open("build-cpp-Desktop-Debug/M_values60.txt", "r")
infile11 = open("build-cpp-Desktop-Debug/Cv_values60.txt", "r")
infile12 = open("build-cpp-Desktop-Debug/chi_values60.txt", "r")

E60 = np.zeros(N)
M60 = np.zeros(N)
Cv60 = np.zeros(N)
chi60 = np.zeros(N)
i = 0
for line in infile9:
    words = line.split()
    E60[i] = float(words[0])
    i+=1
i=0
for line in infile10:
    words = line.split()
    M60[i] = float(words[0])
    i+=1
i=0
for line in infile11:
    words = line.split()
    Cv60[i] = float(words[0])
    i+=1
i=0
for line in infile12:
    words = line.split()
    chi60[i] = float(words[0])
    i+=1

infile13 = open("build-cpp-Desktop-Debug/E_values140.txt", "r")
infile14 = open("build-cpp-Desktop-Debug/M_values140.txt", "r")
infile15 = open("build-cpp-Desktop-Debug/Cv_values140.txt", "r")
infile16 = open("build-cpp-Desktop-Debug/chi_values140.txt", "r")

E140 = np.zeros(N)
M140 = np.zeros(N)
Cv140 = np.zeros(N)
chi140 = np.zeros(N)
i = 0
for line in infile13:
    words = line.split()
    E140[i] = float(words[0])
    i+=1
i=0
for line in infile14:
    words = line.split()
    M140[i] = float(words[0])
    i+=1
i=0
for line in infile15:
    words = line.split()
    Cv140[i] = float(words[0])
    i+=1
i=0
for line in infile16:
    words = line.split()
    chi140[i] = float(words[0])
    i+=1
infile17 = open("build-cpp-Desktop-Debug/E_values120.txt", "r")
infile18 = open("build-cpp-Desktop-Debug/M_values120.txt", "r")
infile19 = open("build-cpp-Desktop-Debug/Cv_values120.txt", "r")
infile20 = open("build-cpp-Desktop-Debug/chi_values120.txt", "r")

E120 = np.zeros(N)
M120 = np.zeros(N)
Cv120 = np.zeros(N)
chi120 = np.zeros(N)
i = 0
for line in infile17:
    words = line.split()
    E120[i] = float(words[0])
    i+=1
i=0
for line in infile18:
    words = line.split()
    M120[i] = float(words[0])
    i+=1
i=0
for line in infile19:
    words = line.split()
    Cv120[i] = float(words[0])
    i+=1
i=0
for line in infile20:
    words = line.split()
    chi120[i] = float(words[0])
    i+=1

infile21 = open("build-cpp-Desktop-Debug/E_values100.txt", "r")
infile22 = open("build-cpp-Desktop-Debug/M_values100.txt", "r")
infile23 = open("build-cpp-Desktop-Debug/Cv_values100.txt", "r")
infile24 = open("build-cpp-Desktop-Debug/chi_values100.txt", "r")

E100 = np.zeros(N)
M100 = np.zeros(N)
Cv100 = np.zeros(N)
chi100 = np.zeros(N)
i = 0
for line in infile21:
    words = line.split()
    E100[i] = float(words[0])
    i+=1
i=0
for line in infile22:
    words = line.split()
    M100[i] = float(words[0])
    i+=1
i=0
for line in infile23:
    words = line.split()
    Cv100[i] = float(words[0])
    i+=1
i=0
for line in infile24:
    words = line.split()
    chi100[i] = float(words[0])
    i+=1
infile25 = open("build-cpp-Desktop-Debug/E_values80.txt", "r")
infile26 = open("build-cpp-Desktop-Debug/M_values80.txt", "r")
infile27 = open("build-cpp-Desktop-Debug/Cv_values80.txt", "r")
infile28 = open("build-cpp-Desktop-Debug/chi_values80.txt", "r")

E80 = np.zeros(N)
M80 = np.zeros(N)
Cv80 = np.zeros(N)
chi80 = np.zeros(N)
i = 0
for line in infile25:
    words = line.split()
    E80[i] = float(words[0])
    i+=1
i=0
for line in infile26:
    words = line.split()
    M80[i] = float(words[0])
    i+=1
i=0
for line in infile27:
    words = line.split()
    Cv80[i] = float(words[0])
    i+=1
i=0
for line in infile28:
    words = line.split()
    chi80[i] = float(words[0])
    i+=1

a = 0
count = 0
Cv = [Cv20, Cv40, Cv60, Cv80, Cv100, Cv120, Cv140]
for i in xrange(len(Cv)):
    for j in xrange(len(Cv)):
        if i != j:
            a += (T[np.argmax(Cv[i])] - T[np.argmax(Cv[j])])/(1.0/((i+1)*20) - 1.0/((j+1)*20))       
            count += 1
a/=count
print a
Tc_limit = 0
count = 0
Cv = [Cv20, Cv40, Cv60, Cv80, Cv100, Cv120, Cv140]
for i in xrange(len(Cv)):
    Tc_limit += T[np.argmax(Cv[i])] - a/((i+1)*20)
    count += 1
Tc_limit/=count
print Tc_limit

"""
infile1 = open("build-cpp-Desktop-Debug/success.txt", "r")
success = []
cycles = []
for line in infile1:
    words = line.split()
    success.append(float(words[0]))
    cycles.append(float(words[1]))

infile1 = open("build-cpp-Desktop-Debug/success24.txt", "r")
success24 = []
for line in infile1:
    words = line.split()
    success24.append(float(words[0]))

print len(success24)
print len(cycles)
plt.plot(np.log10(cycles), success, np.log10(cycles), success24)
plt.legend(["T = 1.0", "T = 2.4"])
plt.ylabel("#accepted flips/ #suggested flips")
plt.xlabel("log10(Monte Carlo cycles)")
plt.show()
"""
plt.plot()
plt.plot(T, Cv20, T, Cv40, T, Cv60,T, Cv80, T, Cv100, T, Cv120, T, Cv140)
plt.xlabel("T")
plt.ylabel("Cv")
plt.axis([2.2, 2.3, 1, 2.8])
plt.legend(["L = 20", "L = 40", "L = 60", "L = 80", "L = 100", "L = 120", "L = 140"], loc=2)
plt.show()

plt.plot(T, chi20, T, chi40, T, chi60, T, chi80, T, chi100, T, chi120, T, chi140)
plt.xlabel("T")
plt.ylabel("$\\chi$")
plt.axis([2.2, 2.3, 0, 300])
plt.legend(["L = 20", "L = 40", "L = 60", "L = 80", "L = 100", "L = 120", "L = 140"], loc=2)
plt.show()

plt.plot(T, E20, T, E40, T, E60, T, E80, T, E100, T, E120, T, E140)
plt.xlabel("T")
plt.axis([2.2, 2.3, -1.5, -1.3])
plt.ylabel("E")
plt.legend(["L = 20", "L = 40", "L = 60", "L = 80", "L = 100", "L = 120", "L = 140"], loc=2)
plt.show()

plt.plot(T, M20, T, M40, T, M60, T, M80, T, M100, T, M120, T, M140)
plt.xlabel("T")
plt.ylabel("|M|")
plt.axis([2.2, 2.3, 0.2, 0.8])
plt.legend(["L = 20", "L = 40", "L = 60", "L = 80", "L = 100", "L = 120", "L = 140"], loc=3)
plt.show()

