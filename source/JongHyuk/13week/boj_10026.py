from collections import deque
import sys
N=int(input())
sys.setrecursionlimit(100000)
arr=[]
b_count=0
count=0
for _ in range(N):
    arr.append(list(input()))
flag=[[0]*N for _ in range(N)]
dx=[-1,1,0,0]
dy=[0,0,-1,1]

def bfs(i,j):
    queue=deque()
    queue.append([i,j])
    find_color=arr[i][j]        
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            tmp_x=x+dx[i]
            tmp_y=y+dy[i]
            if 0<=tmp_x<N and 0<=tmp_y<N and flag[tmp_x][tmp_y]==0 and arr[tmp_x][tmp_y]==find_color:
                flag[tmp_x][tmp_y]=1
                queue.append([tmp_x,tmp_y])
    if find_color=='B':
        global b_count
        b_count+=1

for i in range(N):
    for j in range(N):
        if flag[i][j]==0:
            bfs(i,j)
            flag[i][j]=1
            count+=1

print(count,count-b_count)

