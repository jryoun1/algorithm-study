# 백준 9461 파도반 수열
# python solved by dp
import sys
input = sys.stdin.readline

T = int(input())
dp = [0] * 100
dp[0],dp[1],dp[2],dp[3],dp[4] = 1,1,1,2,2
for i in range(5,100):
    dp[i] = dp[i-1] + dp[i-5]

for _ in range(T):
    num = int(input())
    print(dp[num-1])