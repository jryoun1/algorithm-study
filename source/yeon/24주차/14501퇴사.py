# 백준 14501 퇴사
# python solved by dp
import sys
input = sys.stdin.readline

N = int(input())
t, p = [0] * 16, [0] * 16
dp = [0] * 16
ans = 0
for index in range(N):
    ti, pi = map(int, input().split())
    t[index] = ti
    p[index] = pi

for i in range(N+1):
    ans = max(dp[i], ans) 
    if i + t[i] > N: continue
    dp[i + t[i]] = max(ans + p[i], dp[i + t[i]])
print(ans)
