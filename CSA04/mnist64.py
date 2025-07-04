import sys
import numpy as np
import matplotlib.pyplot as plt

if (len(sys.argv) < 66):
    print ("Not enough command line arguments")
    exit(1)
imagefile = sys.argv[1]

# read the data file
data = np.loadtxt(sys.stdin)
data = data.astype(int)

plt.rcParams['figure.figsize'] = (20, 20)
plt.rc('xtick', labelsize=20) 
plt.rc('ytick', labelsize=20) 
plt.rcParams['axes.facecolor']='white'
plt.rcParams['savefig.facecolor']='white'
images = np.zeros((64,28,28),dtype=int);
for i in range(64):
    images[i] = np.asarray(data[int(sys.argv[2+i])]).reshape(28,28)
f, axarr = plt.subplots(8,8)
for i in range(8):
    for j in range(8):
        axarr[i][j].imshow(images[i*8+j],cmap='gray',vmin=0, vmax=255, interpolation='none')
plt.savefig(imagefile,bbox_inches='tight')

