import sys
import numpy as np
import matplotlib.pyplot as plt

# the name of the data, hull, and output files are command line arguments
if (len(sys.argv) < 4):
    print ("Command Usage: python3",sys.argv[0],"datafile","hullfile","outfile")
    exit(1)
datafile = sys.argv[1]
hullfile = sys.argv[2]
outfile = sys.argv[3]

# read the data file
data = np.loadtxt(datafile)

# read the edge list
edges = np.loadtxt(hullfile,dtype='int')

# plot the data
plt.gca().set_aspect('equal')
plt.scatter(data[:,0],data[:,1],s=10,color='black')

# plot the edges
num_edges = len(edges)
for edge in edges:
    p1 = data[edge[0]]
    p2 = data[edge[1]]
    plt.plot([p1[0],p2[0]],[p1[1],p2[1]],color='red')

# save the plot as an image
plt.savefig(outfile)
