# 백준 2573 빙산
# python solved by dfs
# 시간초과, 메모리 초과 수정 필요 
import sys
from collections import deque
sys.setrecursionlimit(10**6)
dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

def dfs(x, y):
    visited[x][y] = True
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < row and 0 <= ny < col and visited[nx][ny] == 0 and _map[nx][ny] > 0:
            dfs(nx,ny)

row, col = map(int,input().split())
_map = [list(map(int,input().split())) for _ in range(row)]
totalCount = 0
dq = deque()

while True :
    cnt = 0
    visited = [[False] * col for _ in range(row)]
    # check how many iceberg exist
    for i in range(1,row-1):
        for j in range(1,col-1):
            if _map[i][j] > 0 and visited[i][j] == 0:
                dfs(i,j)
                cnt += 1
    # 주변 바다 카운트  
    for i in range(1,row-1):
        for j in range(1,col-1):
            if _map[i][j] > 0:
                seaCount = 0
                for k in range(4):
                    ni, nj = i + dx[k], j + dy[k]
                    if 0 <= ni < row and 0 <= nj < col and _map[ni][nj] == 0:
                        seaCount +=1    
                dq.append((i,j,seaCount))
    
    while dq:
        x, y, seaCnt = dq.popleft()
        if _map[x][y] >= seaCnt :
            _map[x][y] -= seaCnt
        else:
            _map[x][y] = 0

    if cnt > 1:
        print(totalCount)
        break
    elif cnt == 0:
        print(0)
    totalCount += 1