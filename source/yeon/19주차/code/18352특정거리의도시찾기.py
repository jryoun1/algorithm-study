# 백준 18352 특정 거리의 도시 찾기
# python sovled by heapq, dijkstra
import sys
from heapq import heappush, heappop
input = sys.stdin.readline
INF = 100000000
N, M, K, X = map(int, input().split())
location = [[] for _ in range(N+1)]

for _ in range(M):
    start, dst = map(int, input().split())
    location[start].append([dst, 1])

heap = []
dp = [INF] * (N+1)
dp[X] = 0
heappush(heap, [0,X])

while heap:
    mid = heappop(heap)
    for dst in location[mid[1]]:
        if dp[dst[0]] > mid[0] + dst[1]:
            dp[dst[0]] = mid[0] + dst[1]
            heappush(heap, [dp[dst[0]], dst[0]])

cnt, ans = 0 , []
for i in range(1, N+1):
    if dp[i] == K:
        ans.append(i)
        cnt += 1

if cnt == 0:
    print(-1)
else:
    for city in sorted(ans):
        print(city)