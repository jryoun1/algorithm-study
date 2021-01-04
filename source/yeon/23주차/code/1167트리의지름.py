# 백준 1167 트리의 지름
# python solved dfs 
import sys
input = sys.stdin.readline
N = int(input())
graph = [[] * (N+1) for _ in range(N+1)]

def dfs(start):
    for n, c in graph[start]:
        if dp[n] == 0:
            dp[n] = dp[start] + c
            dfs(n)

for _ in range(N):
    adj = list(map(int, input().split()))
    start = adj[0]
    adj = adj[1:-1]
    for j in range(0,len(adj), 2):
        dst, cost = adj[j], adj[j+1]
        graph[start].append([dst,cost])

dp = [0] * (N+1)
dfs(1)
dp[1] = 0

tmpMax, tmpIndex = 0, 0
for i in range(len(dp)):
    if tmpMax < dp[i]:
        tmpMax = dp[i]
        tmpIndex = i

dp = [0] * (N+1)
dfs(tmpIndex)
dp[tmpIndex] = 0
print(max(dp))