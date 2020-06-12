import numpy as np
import pandas as pd

df = pd.DataFrame(np.random.randn(10, 4), columns=['A', 'B', 'C', 'D'])

print(df)
print(df[0:-1])
