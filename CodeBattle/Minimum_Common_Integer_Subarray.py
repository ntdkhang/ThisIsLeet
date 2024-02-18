arr=[2,4,2,3,5]

idx, n=collections.defaultdict(list),len(arr)

for i,j in enumerate(arr):
    idx[j]+=[i]

res=[float('inf')]*n

for num in idx:
    x=[-1]+idx[num]+[n]
    y=max(j-i for i,j in zip(x[:-1],x[1:]))
    res[y-1]=min(res[y-1],num)

for i in range(1,n):
   res[i]=min(res[i],res[i-1])

return res
