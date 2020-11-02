# 백준 4963 섬의 개수
# python solved by dfs
import sys
sys.setrecursionlimit(10**9)
ans = []
dx = [0, -1, 0, 1, 1, -1, 1, -1]
dy = [1, 0, -1, 0, 1, -1, -1, 1]
def dfs(x, y):
    visited[x][y] = 1
    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < col and 0 <= ny < row and visited[nx][ny] == 0 and _map[nx][ny] == _map[x][y]:
            dfs(nx,ny)

while True:
    row, col = map(int, sys.stdin.readline().split())
    if row == 0 and col == 0:
        break
    else:
        _map = [list(map(int, sys.stdin.readline().split())) for _ in range(col)]
        visited = [[0]*row for _ in range(col)]
        cnt = 0
        for i in range(col):
            for j in range(row):
                if _map[i][j] == 1 and visited[i][j] == 0:
                    dfs(i,j)
                    cnt += 1
        ans.append(cnt)

for i in ans:
    print(i)