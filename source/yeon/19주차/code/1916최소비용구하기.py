# 백준 1916 최소 비용 구하기
# python solved by heapq, dijkstra
import sys
from heapq import heappop, heappush
input = sys.stdin.readline
INF = 100000000
N = int(input())
M = int(input())
bus = [[] for _ in range(N+1)]
for _ in range(M):
    start, dst, cost = map(int, input().split())
    bus[start].append([dst, cost])

start, dst = map(int, input().split())
heap = []
dp = [INF] * (N+1)
dp[start] = 0
heappush(heap, [0, start])

while heap:
    mid = heappop(heap)
    for end in bus[mid[1]]:
        if dp[end[0]] > mid[0] + end[1]:
            dp[end[0]] = mid[0] + end[1]
            heappush(heap, [dp[end[0]], end[0]])

print(dp[dst])