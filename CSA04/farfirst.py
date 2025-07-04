import sys
import numpy as np
import matplotlib.pyplot as plt

# read the points
p = np.loadtxt(sys.stdin,comments='#')

# set the aspect ratio to equal
plt.gca().set_aspect('equal')

# plot the centers (if additional command line arguments present)
if (len(sys.argv)-2 > 0):
    ctr = np.array([int(s) for s in sys.argv[2:]])
    dist_sq = np.zeros((len(ctr),len(p)))
    for i in range(len(ctr)):
        dist_sq[i] = np.sum((p-p[ctr[i]])*(p-p[ctr[i]]),axis=1)
    clu = np.argmin(dist_sq,axis=0)
    ex = np.argmax(np.min(dist_sq,axis=0))
    cost_sq = np.max(np.min(dist_sq,axis=0))
    plt.scatter (p[:,0],p[:,1],c=clu,cmap="tab10",s=10,alpha=0.5)
    plt.scatter (p[ctr,0],p[ctr,1],c=range(len(ctr)),cmap="tab10",s=100)
    plt.scatter (p[ctr,0],p[ctr,1],s=100,facecolors='none',edgecolors='black')    
    plt.scatter (p[ex,0],p[ex,1],s=50,facecolors='none', edgecolors='black')
#    plt.title ('Cost = %g' % np.sqrt(cost_sq))
else:
    plt.scatter (p[:,0],p[:,1],s=10,color='black')

#save the plot as an image
plt.savefig(sys.argv[1])
