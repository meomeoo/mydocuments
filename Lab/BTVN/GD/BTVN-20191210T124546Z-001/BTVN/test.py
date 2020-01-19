import pandas as pd
import numpy as np
 
data = pd.read_csv('data_house_new.csv').values 
data =  data.astype('float')
length = len(data)

new = np.ones(length, dtype = float)
data[:,0]=new 

x1min = np.array([data[:,1].min() for x in range(length)])
data[:,1] =(data[:,1] - x1min)/(data[:,1].max()-data[:,1].min())
x2min = np.array([data[:,2].min() for x in range(length)])
data[:,2] =(data[:,2] - x2min)/(data[:,2].max()-data[:,2].min())
x3min = np.array([data[:,3].min() for x in range(length)])
data[:,3] =(data[:,3] - x3min)/(data[:,3].max()-data[:,3].min())
x4min = np.array([data[:,4].min() for x in range(length)])
data[:,4] =(data[:,4] - x4min)/(data[:,4].max()-data[:,4].min())
x5min = np.array([data[:,5].min() for x in range(length)])
data[:,5] =(data[:,5] - x5min)/(data[:,5].max()-data[:,5].min())
x6min = np.array([data[:,6].min() for x in range(length)])
data[:,6] =(data[:,6] - x6min)/(data[:,6].max()-data[:,6].min())
x7min = np.array([data[:,7].min() for x in range(length)])
data[:,7] =(data[:,7] - x7min)/(data[:,7].max()-data[:,7].min())

x = data[range(1159),0:7]
y = data[range(1159),7].reshape(-1,1)

xtest = data[range(1159,length),0:7]
ytest = data[range(1159,length),7].reshape(-1,1)
w = np.array([0. for x in range(7)]).reshape(-1,1)

loop = 10000000
cost = np.zeros((loop,1))
learning_rate = 0.0001
for i in range(1,10):
    r = np.dot(x,w) - y
    w[0] -= learning_rate*np.sum(r)/length
    cost[i] = 0.5*np.sum(r*r)/length
    w[1] -= learning_rate*np.sum(np.multiply(r, x[:,1].reshape(-1,1)))/length
    w[2] -= learning_rate*np.sum(np.multiply(r, x[:,2].reshape(-1,1)))/length
    w[3] -= learning_rate*np.sum(np.multiply(r, x[:,3].reshape(-1,1)))/length
    w[4] -= learning_rate*np.sum(np.multiply(r, x[:,4].reshape(-1,1)))/length
    w[5] -= learning_rate*np.sum(np.multiply(r, x[:,5].reshape(-1,1)))/length
    w[6] -= learning_rate*np.sum(np.multiply(r, x[:,6].reshape(-1,1)))/length
    if i%1 == 0 : 
        print("gia tri cua cost:", cost[i],   "trong lan traing thu:", i)
    

print(w)

