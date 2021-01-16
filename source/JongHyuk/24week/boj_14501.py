'''
마지막 날짜부터 dp를 유지하며 역으로 내려오면서 각각의 날짜(i)에 해당하는
dp[i]에는 i일로부터 마지막 날까지 얻을 수 있는 최대 금액들이 갱신되어 지게 된다.
'''

from sys import stdin
n=int(stdin.readline())
lst=[]
for _ in range(n):
    t,p=map(int,stdin.readline().split())
    lst.append([t,p])
dp=[0 for _ in range(n+1)]
for i in range(n-1,-1,-1):
    if lst[i][0]+i<=n:
        dp[i]=max((lst[i][1]+dp[lst[i][0]+i]),dp[i+1])
    else:
        dp[i]=dp[i+1]
print(dp[0])