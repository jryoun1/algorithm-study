# 백준 1219 오민식의 고민
# python solved by bellman-ford & dfs & bfs
import sys
input = sys.stdin.readline
INF = -100000000
# dfs로 처음에 S에서 연결되어있는 곳은 true로 저장
def dfs(start):
    visited[start] = True
    for next_node, cost in adj[start]:
        if visited[next_node] == False:
            dfs(next_node)

def bellmanFord():
    for i in range(N):
        for j in range(N):
            for next_node, cost in adj[j]:
                if distance[j] != -INF and distance[next_node] < cost + distance[j]:
                    distance[next_node] = cost + distance[j]
                    # 음수싸이클이 있는 경우
                    if i == N-1:
                        # 음수싸이클이 E까지 연결이 되어있는지 check + 음수싸이클이 S랑 연결되어있는지 check
                        if check(next_node) and visited[next_node]:
                            print("Gee")
                            return False                        
    return True
# 음수싸이클의 한 점이 E까지 연결이 되어있는지 check
def check(end):
    visit = [False] * N
    q = [end]
    while q:
        a = q.pop()
        if a == E:
            return True
        visit[a] = True
        for next_node, cost in adj[a]:
            if visit[next_node] == False:
                q.append(next_node)
    return False

N, S, E, M = map(int, input().split())
adj = [[] for _ in range(N)]
for _ in range(M):
    s, e, cost = map(int, input().split())
    adj[s].append([e,-cost])
earning = list(map(int,input().split()))
visited = [False] * N
distance = [INF] * N
# 미리 해당 지역까지 도착해서 벌어들이는 돈을 해당 거리에 가는 cost에 더해놓음
for i in range(N):
    for j in range(len(adj[i])):
        adj[i][j][1] += earning[adj[i][j][0]]

dfs(S)
## 만약 시작 지점에서 end 지점으로 갈 수 없는 경우에는 굳이 bellman 포드 할 필요도 없이 gg 출력하고 끝
if visited[E] == False:
    print("gg")
else:
    distance[S] = earning[S]
    negative_cycle = bellmanFord()
    # 만약 해당 경로에 싸이클이 없는 경우
    if negative_cycle:
        print(distance[E])

