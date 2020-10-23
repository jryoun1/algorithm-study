# 백준 10026 적록색약
# python solved by bfs
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def bfs(b, a):
    stack.append((a, b))
    visited[b][a] = 1 
    while stack:
        x, y = stack.pop()
        for i in range(4):
            nx, ny = x + dx[i] , y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and visited[ny][nx] == 0:
                if RGB[ny][nx] == RGB[y][x]:
                    stack.append((nx,ny))
                    visited[ny][nx] = 1

N = int(input())
RGB = [input() for _ in range(N)] # 일반인 배열
ans, blindAns = 0, 0
visited = [[0] * N for _ in range(N)]
stack = []

for i in range(N):
    for j in range(N):
        # bfs에 한번 들어가면 같은 알파벳은 다 1로 바뀌기 때문에
        # 0 인 것을 visited 에서 들어가면 구분할 수 있다. 
        if visited[i][j] == 0:
            ans += 1
            bfs(i,j)

# G를 R로 바꿔주어 적록색약 배열 만들기  
for i in range(N): 
    RGB[i] = RGB[i].replace("G","R")
# visited 배열 다시 0 으로 초기화
visited = [[0] * N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if visited[i][j] == 0:
            blindAns += 1
            bfs(i,j)

print(ans, blindAns)