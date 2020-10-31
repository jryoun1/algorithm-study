# 백준 2468 안전영역
# python solved by dfs
import sys
sys.setrecursionlimit(10**9)
def dfs(height, x, y):
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < N and 0 <= ny < N and location[nx][ny] > height and visited[nx][ny] == 0:
            visited[nx][ny] = 1
            dfs(height, nx, ny)

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
N = int(input())
location = [list(map(int,input().split())) for _ in range(N)]
ans, height = 0, 0 # 비가 안올경우도 있으므로 height는 0부터 시작
maxHeight = max(max(location))

while height <= maxHeight:
    cnt = 0
    visited = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if location[i][j] > height and visited[i][j] == 0:
                dfs(height,i,j)
                cnt += 1
    ans = max(ans, cnt)
    height += 1

print(ans)

# # 백준 2468 안전영역
# # python solved by bfs
# from collections import deque
# def bfs(b,a, height):
#     dq = deque()
#     dq.append((a,b))
#     visited[b][a] = 1
#     while dq:
#         x, y = dq.popleft()
#         for i in range(4):
#             nx, ny = x + dx[i], y + dy[i]
#             if 0 <= nx < N and 0 <= ny < N and location[ny][nx] > height and visited[ny][nx] == 0:
#                 dq.append((nx,ny))
#                 visited[ny][nx] = 1
# dx = [0, 1, 0, -1]
# dy = [1, 0, -1, 0]
# N = int(input())
# location = [list(map(int,input().split())) for _ in range(N)]
# ans, height = 0, 0 # 비가 안올경우도 있으므로 height는 0부터 시작
# maxHeight = max(max(location))

# while height <= maxHeight:
#     cnt = 0
#     visited = [[0] * N for _ in range(N)]
#     for i in range(N):
#         for j in range(N):
#             if location[i][j] > height and visited[i][j] == 0:
#                 bfs(i,j,height)
#                 cnt += 1
#     ans = max(ans, cnt)
#     height += 1

# print(ans)