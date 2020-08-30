# 백준 미로 탐색
# python solved by bfs using deque
from collections import deque
dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs(x:int, y:int):
    q.append([x,y])
    while q:
        x,y = q.popleft()
        if x == N - 1 and y == M - 1:
            print(visited[x][y])
            break
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < M:
                if visited[nx][ny] == 0 and maze[nx][ny] == 1 :
                    visited[nx][ny] = visited[x][y] +1
                    q.append([nx,ny])


N, M = map(int,input().split())
maze = [list(map(int,input())) for _ in range(N)]
visited = [[0] * M for _ in range(N)]
visited[0][0] = 1
q = deque()
bfs(0,0)
