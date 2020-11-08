# 백준 9663 N-Queen
# python solved by back-tracking
N = int(input())
ans = 0
colCheck, rightDiagonalCheck, leftDiagonalCheck = [False] * N, [False] * (2*N-1), [False] * (2*N-1)

def dfs(row):
    global ans
    # Row 가 마지막 줄까지 왔다면 정답이 되는 것이므로 정답 하나 추가
    if row == N:
        ans += 1
        return 
    for col in range(N):
        # 만약 세로줄, 오른쪽 대각선, 왼쪽 대각선이 표시되어 있지 않다면 해당 대각선 표시 후 다음 행으로 이동 
        if not (colCheck[col] or rightDiagonalCheck[row + col] or leftDiagonalCheck[row - col + N - 1]):
            colCheck[col] = rightDiagonalCheck[row + col] = leftDiagonalCheck[row - col + N -1] = True
            dfs(row+1)
            colCheck[col] = rightDiagonalCheck[row + col] = leftDiagonalCheck[row - col + N -1] = False
dfs(0)
print(ans)


# dx = [0, -1, 0, 1, 1, -1, -1, 1]
# dy = [1, 0, -1, 0, -1, 1, -1, 1]
# def dfs(x: int, y: int):
#     stack.append((x,y))
#     chessBoard[x][y] = 1
    
#     for i in range(8):
#         nx, ny = x + dx[i], y + dy[i]
#         if 0 <= nx < N and 0 <= ny < N and chessBoard[nx][ny] == 0:
#             dfs(nx, ny)
#     chessBoard[x][y] = 0


# N = int(input())
# chessBoard = [[0] * N for _ in range(N)]
# stack = []
# dfs(0,0)

# print(chessBoard)