from sys import stdin
n,m=map(int,stdin.readline().split())
graph=[[] for _ in range(n+1)]
for _ in range(m):
    s,e,w=map(int,stdin.readline().split())
    graph[s].append([e,w])
shortest_route=[float('inf') for _ in range(n+1)]
#1에서 출발하므로 0으로 초기화
shortest_route[1]=0
flag=True
#벨만포드 알고리즘
#최악의 경우를 고려해 n번 돌린다.
for i in range(n):
    #해당 정점에서 갈수 있는 정점 까지의 거리를 갱신해준다.
    for j in range(1,n+1):
        for now,weight in graph[j]:
            if shortest_route[now]>shortest_route[j]+weight:
                shortest_route[now]=shortest_route[j]+weight
                #무한루프가 형성 되면
                if i == n-1:
                    flag=False
if flag:
    for ans in shortest_route[2:]:
        print(ans if ans != float('inf') else -1)
else:
    print(-1)
