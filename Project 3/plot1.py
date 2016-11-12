import numpy as np
import matplotlib.pyplot as plt
import mpl_toolkits.mplot3d.axes3d as p3
import matplotlib.animation as animation


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



number_of_frames = steps/100 + 1
system = np.zeros((number_of_planets, 3, number_of_frames))

indices = np.linspace(0, steps, number_of_frames)

for i in xrange(len(indices)-1):
    system[:,:,i] = system1[:,:,int(indices[i])]
from numpy import *
def plot():
    def update_lines(num, dataLines, lines) :
        for line, data in zip(lines, dataLines) :
            line.set_data(data[0:2, num-1:num])
            line.set_3d_properties(data[2,num-1:num])
        return lines
    
    # Attach 3D axis to the figure
    fig = plt.figure()
    ax = p3.Axes3D(fig)
    n = number_of_frames
    m = n
    N = number_of_planets

    data = [i for i in range(N)]
    lines = [i for i in range(N)]
    for i in range(N):
        data[i] = [system[i]]
        lines[i] = [ax.plot(data[i][0][0,0:1], 
        data[i][0][1,0:1], data[i][0][2,0:1], 'o')[0]]

    # Set the axes properties
    if len(system) == 3:
        ax.set_xlim3d([-10, 10])
        ax.set_xlabel('X')

        ax.set_ylim3d([-10, 10])
        ax.set_ylabel('Y')

        ax.set_zlim3d([-10, 10])
        ax.set_zlabel('Z')

    elif len(system) == 14:
        ax.set_xlim3d([-40, 40])
        ax.set_xlabel('X')

        ax.set_ylim3d([-40, 40])
        ax.set_ylabel('Y')

        ax.set_zlim3d([-40, 40])
        ax.set_zlabel('Z')
    else:
        ax.set_xlim3d([-2, 2])
        ax.set_xlabel('X')

        ax.set_ylim3d([-2, 2])
        ax.set_ylabel('Y')

        ax.set_zlim3d([-2, 2])
        ax.set_zlabel('Z')
    ax.set_title('Celestial movements')

    # Creating the Animation object
    ani = [i for i in range(N)] 
    for i in range(N):
        ani[i] = animation.FuncAnimation(fig, 
        update_lines, m, fargs=(data[i], lines[i]),
        interval=50, blit=False)
    if len(system) == 14:    
        plt.legend(["The sun","Mercury", "Venus", "The Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto","The Moon", "52 Europa", "Halley's comet", "Hale-Bopp"])    
    elif len(system) == 10:    
        plt.legend(["The sun","Mercury", "Venus", "The Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"])
 
    elif len(system) == 3:    
        plt.legend(["The sun", "The Earth", "Jupiter"])
   
    else:
        plt.legend(["The Earth"])
    plt.show()
    return system    
plot()

if len(system1) == 1:
    for i in xrange(number_of_planets):
        plt.plot(system1[i,0,:], system1[i,1,:])
        plt.xlabel("[AU]")
        plt.ylabel("[AU]")
        #plt.title("Earth-Sun system seen from x and y coordinates")
else:
    for i in xrange(number_of_planets):
        if i == 0:
            plt.plot(system1[i,0,:], system1[i,1,:], "yo")
            plt.xlabel("[AU]")
            plt.ylabel("[AU]")
        else:
            plt.plot(system1[i,0,:], system1[i,1,:])
            plt.xlabel("[AU]")
            plt.ylabel("[AU]")
        #plt.title("Earth-Sun system seen from x and y coordinates")

if len(system1) == 14:    
    plt.legend(["The sun","Mercury", "Venus", "The Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "The Moon", "52 Europa", "Halley's comet", "Hale-Bopp"])    
#    plt.title("The celestial bodies of our solarsystem in the xy-plane")
    plt.axis([-40, 40, -40, 40])
elif len(system1) == 10:    
    plt.legend(["The sun","Mercury", "Venus", "The Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"])    
#    plt.title("The celestial bodies of our solarsystem in the xy-plane")
    plt.axis([-40, 40, -40, 40])

elif len(system1) == 3:
    plt.legend(["The sun","The Earth", "Jupiter"])
#    plt.title("The Earth-Sun-Jupiter system in the xy-plane")
    plt.axis([-10, 10, -10, 10])
elif len(system1) == 1:
    plt.legend(["The Earth"])
#    plt.title("The Earth circulating the sun in the xy-plane")
    plt.axis([-5, 5, -5, 5])
else:
    plt.legend(["The sun","The Earth"])
#    plt.title("The Earth-Sun system in the xy-plane, v = 2$\\pi$")
    plt.axis([-5, 5, -5, 5])
plt.show()

