# 백준 1261 알고스팟
# python solved by bfs using deque
from collections import deque

# left, down, up, right
dx = [-1,0,0,1]
dy = [0,-1,1,0]

def bfs(x: int, y: int):
    q.append([x,y])
    while q:
        # deque를 사용해서 arr가 0인 nx,ny는 우선순위가 높게 하기 위해
        # appendleft를 하였기 때문에 popleft를 해준다. 
        x, y = q.popleft()

        for i in range(4):
            nx, ny = x + dx[i] , y + dy[i]

            if 0 <= nx < M and 0 <= ny < N :
                if dist[nx][ny] == -1:
                    if arr[nx][ny] == 0 :
                        q.appendleft([nx,ny])
                        dist[nx][ny] = dist[x][y]
                    elif arr[nx][ny] == 1:
                        q.append([nx,ny])
                        dist[nx][ny] = dist[x][y]+1

N, M = map(int,input().split())
arr = [list(map(int,input())) for _ in range(M)]
q = deque()
# 입력받은 arr의 원소가 1이냐 0이냐에 따라서 비용을 계산하는 리스트 
dist = [[-1] * N for _ in range(M)]
dist[0][0] = 0
bfs(0,0)

print(dist[M-1][N-1])