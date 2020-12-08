# 백준 1753 최단경로
# python solved by 
from heapq import heappop, heappush
import sys
input = sys.stdin.readline
INF = 100000000
V, E = map(int, input().split())
start = int(input())
distance = [[] for _ in range(V)]

for _ in range(E):
    u, v, w = map(int, input().split())
    distance[u-1].append([v-1,w]) # [[0: [1,2], [2,3]], [1: [2,4], [3,5]], [2: [3,6]], [3: ], [4: [0,1]]] 

heap = []
dp = [INF] * V
dp[start-1] = 0 # 자기 자신은 0 으로 만들어줌
heappush(heap, [0, start-1]) #heap에는 [거리, 노드 위치]순으로 저장

while heap:
    mid = heappop(heap) # 현재 가장 가까운 거리의 노드를 pop [거리, 노드 위치]
    for v in distance[mid[1]]: # 가장 가까운 노드에 연결된 모든 노드들 v에 대해서 
        if dp[v[0]] > mid[0] + v[1]: # 중간을 거쳐서 가는게 바로 v로 가는게 거리가 적다면 해당 거리 저장
            dp[v[0]] = mid[0] + v[1]
            heappush(heap, [dp[v[0]], v[0]]) # heap에 [갱신된 거리, 노드 위치] 삽입

for i in range(V):
    if dp[i] == INF:
        print("INF")
    else:
        print(dp[i])