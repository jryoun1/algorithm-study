# 백준 1238 파티
import sys
from heapq import heappop, heappush
input = sys.stdin.readline
INF = 10000000
N, M, X = map(int, input().split())
distance = [[] for _ in range(N)]
for _ in range(M):
    start, end, time = map(int, input().split())
    distance[start-1].append([end-1, time])

ans = [0] * N
for i in range(N): 
    heap = []
    dp = [INF] * N
    dp[i] = 0
    heappush(heap, [0, i])

    while heap:
        mid = heappop(heap)
        for end in distance[mid[1]]:
            if dp[end[0]] > mid[0] + end[1]:
                dp[end[0]] = mid[0] + end[1]
                heappush(heap, [dp[end[0]], end[0]])
    
    if i == X-1:
        for j in range(N):
            ans[j] += dp[j]
    else:
        ans[i] += dp[X-1]

print(max(ans))