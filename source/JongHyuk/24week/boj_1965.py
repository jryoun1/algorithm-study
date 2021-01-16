'''
주어진 상자들 각각에 대하여 해당 상자가 포함할 수 있는 최대 상자갯수로 dp를 
갱신시켜준다.
'''
from sys import stdin
n=int(stdin.readline())
box_size=list(map(int,stdin.readline().split()))
dp=[1]+[0 for _ in range(n-1)]
for i in range(1,n):
    #해당 상자의 앞상자들 중에서 크기가 작은 상자들의 dp들을
    #임시로 저장하기 위한 tmp리스트
    tmp=[]
    for j in range(0,i):
        if box_size[j]<box_size[i]:
            tmp.append(dp[j])
    #현재 상자도 카운트하여 dp에 넣어준다
    if tmp:
        dp[i]=max(tmp)+1
    else:
        dp[i]=1
print(dp[-1])
