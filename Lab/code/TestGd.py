
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


f = open("house_price.txt", "r")

text = f.read()
text = text.split("\n")
myList = [i.split('\t') for i in text] 
myList = [[int(y) for y in x] for x in myList]

data = np.asarray(myList)


N = data.shape[0]

x1 = data[:, 0].reshape(-1, 1)
y1 = data[:, 1].reshape(-1, 1)

xmin = np.array([[x1.min()] for x in range(100)])
x = (x1-xmin)/(x1.max() - x1.min())

ymin = np.array([[y1.min()] for y in range(100)])
y = (y1-ymin)/(y1.max() - y1.min())

plt.scatter(x, y)
plt.xlabel('mét vuông')
plt.ylabel('giá')



x = np.hstack((np.ones((N, 1),dtype=int), x))
w = np.array([0.,0.]).reshape(-1,1)
print(np.dot(x,w))
numOfIteration = 2000
cost = np.zeros((numOfIteration,1))

learning_rate = 0.01
for i in range(1, numOfIteration):
    r = np.dot(x, w) - y
    w[0] -= learning_rate*np.sum(r)
    cost[i] = 0.5*np.sum(r*r)
    w[1] -= learning_rate*np.sum(np.multiply(r, x[:,1].reshape(-1,1)))
    if i%100 == 0 : 
        print("gia tri cua cost:", cost[i], "trong lan traing thu:", i)
    if i == 800 :
        learning_rate = 0.001

    
predict = np.dot(x, w)
plt.plot((x[0][1], x[N-1][1]),(predict[0], predict[N-1]), 'r')
plt.show()

