import numpy as np 

D = 165*120 # original dimension 
d = 500 # new dimension 

# generate the projection matrix 
ProjectionMatrix = np.random.randn(D, d) 
print(ProjectionMatrix.shape) 