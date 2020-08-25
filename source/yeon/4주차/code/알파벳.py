# 백준 1978 알파벳 
# python solved by bfs & backtracking

# left, down, right, up
dx = [-1,0,1,0]
dy = [0,-1,0,1] 

def bfs(x:int, y:int):
    global answer
    q = set([(x,y,board[x][y])])

    while q:
        x,y,ans = q.pop()
        #check left, down, right, up 
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            # if nx, ny are in the boundary and 
            # not in ans which saves the visited alpahbet 
            # then append it to ans, and get the answer
            if((0 <= nx < R) and (0 <= ny < C) and (board[nx][ny] not in ans)):
                q.add((nx,ny,ans + board[nx][ny]))
                answer = max(answer, len(ans)+1)

R, C = map(int,input().split()) #input = sys.stdin.readline()
board = [list(input().strip()) for _ in range(R)]
answer = 1
bfs(0,0)
print(answer)