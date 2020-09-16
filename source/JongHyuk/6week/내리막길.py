# # dfs
# dx=[-1,1,0,0]
# dy=[0,0,-1,1]
# q=set()
# M,N=map(int,input().split(' '))
# board=[]
# for _ in range(M):
#     board.append(list(map(int,input().split(' '))))
# ans=0
# q.add((0,0))
# while q:
#     tmp_x,tmp_y=q.pop()
#     if tmp_x==M-1 and tmp_y==N-1:
#         ans+=1
#         continue
#     for i in range(4):
#         x=tmp_x+dx[i]
#         y=tmp_y+dy[i]
#         if x>=0 and y>=0 and x<M and y<N:
#             if board[x][y]<board[tmp_x][tmp_y]:
#                 q.add((x,y))
                
# print(ans)



import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
def dfs(x, y):
    if x == 0 and y == 0:
        return 1
    if dp[x][y] == -1:
        dp[x][y] = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < m and 0 <= ny < n:
                if s[x][y] < s[nx][ny]:
                    dp[x][y] += dfs(nx, ny)
    return dp[x][y]
m, n = map(int, input().split())
s = [list(map(int, input().split())) for i in range(m)]
dp = [[-1] * n for i in range(m)]
print(dfs(m - 1, n - 1))