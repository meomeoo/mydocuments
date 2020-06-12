from mxnet import np, npx
npx.set_np()

a = np.arange(6).reshape(3, 2)

A_sum = a.sum(axis=1)
sum_A = a.sum(axis=1, keepdims=True)

print(A_sum)
print(sum_A)