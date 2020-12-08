from sys import stdin
import heapq
V,E=map(int,stdin.readline().split())
K=int(stdin.readline())
graph=[[] for _ in range(V+1)]
#그래프 리스트의 인덱스는 해당 번호의 정점을 의미하며
#각각의 인덱스에 갈수있는 정점과 비용을 넣어준다
for _ in range(E):
    s,e,w=map(int,stdin.readline().split())
    graph[s].append([e,w])
# print(graph)
inf=100000000
#출발점에서 출발점으로의 최소비용은 0 이므로 이를 세팅해주고,
#나머지 정점들의 비용을 매우 큰 수로 설정한다(갱신해주기 위함)
shortest_route=[0]+[inf for _ in range(V)]
shortest_route[K]=0
q=[]
heapq.heappush(q,[0,K])
#큐를돌며 현재 정점(a)에서 갈수 있는 정점(b)들을 살펴보면서
#최솟값으로 비용을 갱신해나간다.
while q:
    weight,now=heapq.heappop(q)
    #애초에 조건에 맞지 않으면 for문을 돌지않는다.
    if shortest_route[now]<weight:
        continue
    for loc,cost in graph[now]:
        w=cost+weight
        if w<shortest_route[loc]:
            shortest_route[loc]=w
            heapq.heappush(q,[w,loc])
# print(shortest_route)
for i in range(1,len(shortest_route)):
    print(shortest_route[i] if shortest_route[i]!= inf else "INF")
