'''
목표치인 k원을 달성하기위해 1~k원 각각의 인덱스에 해당하는 dp리스트를 만들고,
주어진 동전으로 1~k원 각각을 만들 수 있는 가짓수를 갱신시켜나간다.
'''
from sys import stdin
n,k=map(int,stdin.readline().split())
coins=[]
for _ in range(n):
    coins.append(int(stdin.readline()))
dp=[1]+[0 for _ in range(k)]

for coin in coins:
    for i in range(coin,k+1,1):
        dp[i]+=dp[i-coin]
print(dp[-1])
