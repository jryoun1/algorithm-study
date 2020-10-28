from sys import stdin
from collections import deque
N=int(stdin.readline())
apart=[]
for _ in range(N):
    apart.append(list(map(int,stdin.readline().strip())))
res=[]
visited=[[-1]*N for _ in range(N)]
dx=[-1,1,0,0]
dy=[0,0,-1,1]

def bfs(i,j):
    count=0
    q=deque()
    q.append([i,j])
    while q:
        x,y=q.popleft()
        for i in range(4):
            tmp_x=x+dx[i]
            tmp_y=y+dy[i]
            if 0<=tmp_x<N and 0<=tmp_y<N and visited[tmp_x][tmp_y]==-1 and apart[tmp_x][tmp_y]==1:
                count+=1
                visited[tmp_x][tmp_y]=1
                q.append([tmp_x,tmp_y])
    return count
for i in range(N):
    for j in range(N):
        if apart[i][j]==1 and visited[i][j]==-1:
            res.append(bfs(i,j))
            visited[i][j]=1
res.sort()
print(len(res))
for i in res:
    if i==0:
        print('1')
    else:
        print(i)



