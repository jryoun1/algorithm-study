# 백준 4485 녹색 옷 입은 애가 젤다지?
# python solved by dijkstra
import sys
from heapq import heappop, heappush
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
cnt = 1
def bfs(a, b, cave, visited, N, dp):
    visited[a][b] = 1
    heap = []
    heappush(heap, [cave[a][b], a, b])
    while heap:
        c, x, y = heappop(heap)
        for i in range(4):
            nx, ny = x + dx[i] , y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == 0:
                dp[nx][ny] = min(dp[nx][ny], dp[x][y]+cave[nx][ny])
                heappush(heap,[dp[nx][ny], nx, ny])
                visited[nx][ny] = 1
    return dp[N-1][N-1]

while True:
    N = int(sys.stdin.readline())
    if N == 0: break
    cave = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
    visited = [[0] * N for _ in range(N)]
    dp = [[100000000] * N for _ in range(N)]
    dp[0][0] = cave[0][0]
    k = bfs(0,0, cave, visited, N, dp)
    print("Problem {0}: {1}".format(cnt, k))
    cnt += 1
