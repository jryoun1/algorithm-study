# 백준 1520 내리막길 
# python solved by dfs + dp 
# make python recursive depth as 10^9 if not runtime error occur
from sys import setrecursionlimit 
setrecursionlimit(10**9)

dx = [1,0,-1,0]
dy = [0,1,0,-1]

def dfs(x, y):
    # if x,y get to the dst return 1
    if x == M-1 and y == N-1 : return 1
    # if x,y out of bound return 0
    if x<0 or x>M or y<0 or y>N : return 0
    # if x,y had been to the place before return dp[x][y]
    if dp[x][y] != -1 : return dp[x][y]

    dp[x][y] = 0
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < M and 0 <= ny < N : 
            if arr[nx][ny] < arr[x][y] :
                dp[x][y] += dfs(nx,ny)
    return dp[x][y]

M, N = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(M)]
dp = [[-1] * N for _ in range(M)]
print(dfs(0,0))
print(dp)