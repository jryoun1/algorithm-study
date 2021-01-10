# 백준 1010 다리놓기
# python solved by dp
import sys
input = sys.stdin.readline

T = int(input())
dp = [[0]*30 for _ in range(30)]
for i in range(0,30):
    dp[0][i] = i+1
    dp[i][i] = 1
    for j in range(1,i+1):
        dp[j][i] = dp[j][i-1] + dp[j-1][i-1]

for _ in range(T):
    N, M = map(int, input().split())
    print(dp[N-1][M-1])