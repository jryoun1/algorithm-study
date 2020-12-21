# 백준 11404 플로이드
# python solved by floyd warshall
import sys
input = sys.stdin.readline
INF = 100000000
def floydWarshall():
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if i == j: 
                    city[i][j] = 0
                if city[i][j] > city[i][k] + city[k][j]:
                    city[i][j] = city[i][k] + city[k][j]
N = int(input())
M = int(input())
city = [[INF] * (N) for _ in range(N)]
for _ in range(M):
    a, b, c = map(int,input().split())
    if c < city[a-1][b-1]:
        city[a-1][b-1] = c 
floydWarshall()
for i in range(N):
    for j in range(N):
        if city[i][j] == INF:
            print(0, end =" ")
        else:
            print(city[i][j], end=" ")
    print(end="\n")