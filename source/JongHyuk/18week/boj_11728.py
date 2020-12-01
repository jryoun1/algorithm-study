from sys import stdin
N,M=map(int,stdin.readline().split())
A=list(map(int,stdin.readline().split()))
B=list(map(int,stdin.readline().split()))
res=[]
a_ptr,b_ptr=0,0
#리스트별로 포인터를 따로두고, 
#차례로 해당리스트의 해당포인터에 해당하는 원소들을 비교하며
#오름차순으로 res리스트에 넣어준다.
#각 리스트는 오름차순으로 정렬 되있으므로 둘중에 하나라도 포인터가 해당 리스트의 끝까지 가게되면
#res에 나머지 리스트를 그대로 이어붙이기만하면 정답이다.
while a_ptr<N and b_ptr<M:
    if A[a_ptr]<=B[b_ptr]:
        res.append(A[a_ptr])
        a_ptr+=1
    else:
        res.append(B[b_ptr])
        b_ptr+=1
if a_ptr==N:
    res=res+B[b_ptr:]
else:
    res=res+A[a_ptr:]
print(*res)

