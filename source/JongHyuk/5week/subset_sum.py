from itertools import combinations
N,S=map(int,input().split())
num=[]
ans=0
num=list(map(int,input().split(' ')))
for i in range(1,N+1):
    tmp_lst=list(map(sum,list(combinations(num,i))))
    for sub_sum in tmp_lst:
        if sub_sum==S:
            ans+=1
print(ans)

