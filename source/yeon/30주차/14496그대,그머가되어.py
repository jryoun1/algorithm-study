# 백준 14496 그대, 그머가 되어
import sys
from heapq import heappop, heappush
INF = 10000000
input = sys.stdin.readline
a,b = map(int, input().split())
N,M = map(int, input().split())
character = [[] for _ in range(N)]
for _ in range(M):
    start, end = map(int, input().split())
    character[start-1].append([end-1, 1])
    character[end-1].append([start-1, 1])

heap = []
dp = [INF] * N
dp[a-1] = 0
heappush(heap, [0, a-1])

while heap:
    mid = heappop(heap)
    for end in character[mid[1]]:
        if dp[end[0]] > mid[0] + end[1]:
            dp[end[0]] = mid[0] + end[1]
            heappush(heap, [dp[end[0]], end[0]])
if dp[b-1] == INF:
    print(-1)
else:
    print(dp[b-1])