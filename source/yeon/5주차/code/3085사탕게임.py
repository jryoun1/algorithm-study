# 벡즌 3085 사탕게임
# python solved by bfs
dx = [1,0]
dy = [0,1]

def bfs(x:int, y:int):
    global answer
    # to remove overlap case
    # save [x,y] as set
    q = set([(x,y)])
    while q:
        x, y = q.pop()
        # because checking every element in row, col
        # based on swaped point and swaping point 
        # it doesn't have to check left, down (just check right, up)
        for i in range (2):
            nx, ny = x + dx[i] , y + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                q.add((nx,ny))
                board[x][y], board[nx][ny] = board[nx][ny], board[x][y]
                col_cnt, row_cnt, col_cnt1, row_cnt1= 1,1,1,1
                # count after change 
                for a in range(N-1):
                    # if the element is continously same
                    if board[nx][a] == board[nx][a+1]:
                        col_cnt += 1
                    # if element is not same as right before element
                    else : col_cnt = 1
                    if board[a][ny] == board[a+1][ny]:
                        row_cnt += 1
                    else : row_cnt = 1
                    if board[x][a] == board[x][a+1]:
                        col_cnt1 += 1
                    else : col_cnt1 = 1
                    if board[a][y] == board[a+1][y]:
                        row_cnt1 += 1
                    else : row_cnt1 = 1
                    answer = max(answer,max(max(col_cnt,row_cnt),max(col_cnt1,row_cnt1)))
                # swap again after check one case
                board[x][y], board[nx][ny] = board[nx][ny], board[x][y]

N = int(input())
board = [list(input()) for _ in range(N)]
answer = 0
bfs(0,0)
print(answer)