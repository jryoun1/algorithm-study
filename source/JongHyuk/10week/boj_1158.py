N,K=map(int,input().split(' '))

circle=[i for i in range(1,N+1)]
index=0
res=[]
while circle:
    index+=(K-1)
    index=index%len(circle)
    res.append(str(circle.pop(index)))

print("<%s>" %(", ".join(res)))



