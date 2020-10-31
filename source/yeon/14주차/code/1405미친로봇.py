# 백준 1405 미친로봇
# python solved by dfs
import sys
sys.setrecursionlimit(10**9)
def dfs(x, y, count):
    # 기저 조건 count개 만큼 확인했으면 return 1
    if count == N:
       return 1
    result = 0
    _map[x][y] = 1
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if _map[nx][ny] == 1:
            continue
        result += dfs(nx,ny,count+1) * probability[i]
    _map[x][y] = 0
    return result

# 순서대로 e, w, s, n
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
N, e, w, s, n =  map(int,input().split())
probability = [e/100, w/100, s/100, n/100]
_map = [[0] * (2*N + 1) for _ in range(2*N + 1)]

print(dfs(N,N,0))


