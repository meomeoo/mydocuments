
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


f = open("house_price.txt", "r")

text = f.read()
text = text.split("\n")
myList = [i.split('\t') for i in text] 
myList = [[int(y) for y in x] for x in myList]

data = np.asarray(myList)
data = data/10000
N = data.shape[0]

x = data[:, 0].reshape(-1, 1)
y = data[:, 1].reshape(-1, 1)


plt.scatter(x, y)
plt.xlabel('mét vuông')
plt.ylabel('giá')



x = np.hstack((np.ones((N, 1),dtype=int), x))
w = np.array([0.01,0.01]).reshape(-1,1)

numOfIteration = 1000
cost = np.zeros((numOfIteration,1))
learning_rate = 0.01
for i in range(1, numOfIteration):
    r = np.dot(x, w) - y
    w[0] -= learning_rate*np.sum(r)
    cost[i] = 0.5*np.sum(r*r)
    w[1] -= learning_rate*np.sum(np.multiply(r, x[:,1].reshape(-1,1)))
    print(cost[i])

predict = np.dot(x, w)
plt.plot((x[0][1], x[N-1][1]),(predict[0], predict[N-1]), 'r')
plt.show()

print(x[0][1])
print(x[N-1][1])
print(predict[0])
print(predict[N-1])
print(w)


