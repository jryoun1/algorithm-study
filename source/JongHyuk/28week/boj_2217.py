from sys import stdin
N=int(stdin.readline())
ans=0
max_weight=[]
for _ in range(N):
    max_weight.append(int(stdin.readline()))
max_weight.sort()
for i in range(N):
    tmp=max_weight[i]*(N-i)
    ans=max(tmp,ans)
print(ans)