# 백준 11403 경로찾기 
# python solved by floyd warshall
import sys
input = sys.stdin.readline
def floydWarshall():
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if graph[i][k] == "1" and graph[k][j] == "1":
                    graph[i][j] = "1"
N = int(input())
graph = [ input().split() for _ in range(N)]
floydWarshall()
for i in range(N):
    print(*graph[i])