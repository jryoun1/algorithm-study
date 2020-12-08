#1753과 동일한 방법
from sys import stdin
import heapq
N=int(stdin.readline())
M=int(stdin.readline())
graph=[[] for _ in range(N+1)]
for i in range(M):
    start,end,cost=map(int,stdin.readline().split())
    graph[start].append([end,cost])
start,end=map(int,stdin.readline().split())
route=[100000000 for _ in range(N+1)]

def dijkstra(start):
    route[start]=0
    q=[[0,start]]
    while q:
        c,s=heapq.heappop(q)
        if route[s]<c:
            continue
        for target,cost in graph[s]:
            weight=c+cost
            if weight<route[target]:
                route[target]=weight
                heapq.heappush(q,[weight,target])

dijkstra(start)
print(route[end])
