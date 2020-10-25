# 백준 1012 유기농 배추
# python solved by bfs
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
def bfs(b, a):
    stack = []
    stack.append((a,b))
    visited[b][a] = 1
    while stack:
        x, y = stack.pop()
        for i in range(4):
            nx , ny = x + dx[i] , y + dy[i]
            if 0 <= nx < M and 0 <= ny < N and visited[ny][nx] == 0:
                if _map[ny][nx] == _map[y][x]:
                    stack.append((nx,ny))
                    visited[ny][nx] = 1
T = int(input())
for _ in range(T):
    M, N, K = map(int,input().split())
    _map = [[0] * M for _ in range(N)]
    visited = [[0] * M for _ in range(N)]
    ans = 0
    # 배추 있는 위치 표시
    for _ in range(K):
        x, y = map(int,input().split())
        _map[y][x] = 1

    # 배추가 있는 곳에서 bfs 탐색 시작 
    for i in range(M):
        for j in range(N):
            if visited[j][i] == 0 and _map[j][i] == 1:
                ans += 1
                bfs(j,i)
    print(ans)




# 11724 연결 요소의 개수
# import sys
# N, M = map(int, sys.stdin.readline().split())
# def bfs(start):
#     stack = []
#     stack.extend(graph[start])
#     visited.add(start)
#     while stack:
#         _next = stack.pop()
#         if _next in visited:
#             continue
#         stack.extend(graph[_next])
#         visited.add(_next)

# visited = set()
# graph = dict()
# ans = 0
# for i in range(1, N + 1):
#     graph[i] = set()

# for i in range(M):
#     key, value = map(int, sys.stdin.readline().split())
#     if key in graph.keys():
#         graph[key].add(value)
#     if value in graph.keys():
#         graph[value].add(key)

# for i in range(1, N + 1):
#     if i not in visited:
#         bfs(i)
#         ans += 1
# print(ans)