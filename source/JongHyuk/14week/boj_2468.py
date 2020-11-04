from sys import stdin
import sys
sys.setrecursionlimit(100000)
N=int(stdin.readline())
_max=-1
height=[]
for _ in range(N):
    tmp=list(map(int,stdin.readline().split()))
    height.append(tmp)
    #입력받은 수 중 최대값을 찾기위함
    _max=max(max(tmp),_max)
dx=[-1,1,0,0]
dy=[0,0,1,-1]

ans=1
def dfs(x,y,h):
    for i in range(4):
        tmp_x=x+dx[i]
        tmp_y=y+dy[i]
        if 0<=tmp_x<N and 0<=tmp_y<N and not visited[tmp_x][tmp_y] and height[tmp_x][tmp_y]>h:
            visited[tmp_x][tmp_y]=True
            dfs(tmp_x,tmp_y,h)


#높이를 1씩 증가시키며 최고높이까지 반복한다
for h in range(1,_max):
    visited=[[False]*N for _ in range(N)]
    safe_area=0
    for i in range(N):
        for j in range(N):
            if height[i][j]>h and not visited[i][j]:
                safe_area+=1
                visited[i][j]=True
                dfs(i,j,h)
    #안전구역의 갯수를 safe_area에 저장한 뒤,
    #매 높이마다 최댓값으로 갱신
    ans=max(ans,safe_area)
print(ans)
