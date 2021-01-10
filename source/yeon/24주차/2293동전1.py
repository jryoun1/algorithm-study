# 백준 2293 동전1
# python solved by dp
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
coins = []
dp = [0] * (K+1)
dp[0] = 1
for _ in range(N):
    coins.append(int(input()))

for coin in coins:
    for money in range(1, K+1):
        if money - coin >= 0:
            dp[money] += dp[money - coin]
print(dp[K])