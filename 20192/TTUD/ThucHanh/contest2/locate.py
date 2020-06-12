import numpy as np
test=int(input())
 
# n, m = map(int, input().split())
# x, y = input(),  input() 
map1=[]
map2=[]
dem = np.zeros((20001,20001), dtype=int)


while (test>0):
    n, m = [int(x) for x in input().split()] 
    for i in range (n):
        entries = list(map(int, input().split())) 
        for j in range(m):
            if(entries[j]==1): map1.append((i,j))
    # if ((0*(1,2))==()): print ("ok") numpy reshape ......
    # print(map1)
    for i in range (n):
        entries = list(map(int, input().split())) 
        for j in range(m):
            if(entries[j]==1): map2.append((i,j))

    for i in range(len(map1)):
        for j in range(len(map2)):
            dem[map1[i][0]-map2[j][0]+10000][map1[i][1]-map2[j][1]+10000] +=1

    # print(count_nonzero(dem==1))
    print(np.max(dem))
    test-=1