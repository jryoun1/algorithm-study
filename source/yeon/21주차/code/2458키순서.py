# 백준 키 순서
# python solved by floyd warshall
import sys
input = sys.stdin.readline
def floydWarhall():
    for k in range(1, N+1): # 기준 노드
        for i in range(1, N+1): # 출발 노드
            for j in range(1, N+1): # 도착 노드
                if i == j: continue 
                if graph[i][k] == 1 and graph [k][j] == 1:
                    graph[i][j] = 1

N, M = map(int, input().split())
graph = [[0] * (N+1) for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b] = 1
floydWarhall()
ans = 0
for i in range(1,N+1):
    count = 0
    for j in range(1, N+1):
        count += graph[i][j] + graph[j][i]
    if count == N - 1:
        ans +=1
print(ans)