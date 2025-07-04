import sys
import numpy as np
import matplotlib.pyplot as plt

# the name of the data, tri, and output files are command line arguments
if (len(sys.argv) < 4):
    print ("Command Usage: python3",sys.argv[0],"datafile","trifile","outfile")
    exit(1)
datafile = sys.argv[1]
trifile = sys.argv[2]
outfile = sys.argv[3]

# read the data file
data = np.loadtxt(datafile)

# read the triangle list
triangles = np.loadtxt(trifile,dtype='int')

# plot the data
plt.gca().set_aspect('equal')
plt.scatter(data[:,0],data[:,1],s=10,color='black')

# plot the triangles 
for triangle in triangles:
    p1 = data[triangle[0]]
    p2 = data[triangle[1]]
    p3 = data[triangle[2]]
    plt.plot([p1[0],p2[0],p3[0],p1[0]],[p1[1],p2[1],p3[1],p1[1]],linewidth=1,color='red')

# save the plot as an image
plt.savefig(outfile)
