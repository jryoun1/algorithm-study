N=int(input())
k=int(input())
s,e=1,k
tmp=0
ans=0
while s<=e:
    m=(s+e)//2
    tmp=0
    for i in range(1,N+1):
        tmp+=min(m//i,N)
    if tmp>=k:
        e=m-1
    else:
        s=m+1
print(s)

