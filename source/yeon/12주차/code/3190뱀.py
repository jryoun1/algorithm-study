# 백준 3190 뱀 
# python solved by deque, rotation matrix 
import math 
from collections import deque
# 회전 변환 행렬 R(x') = [cos() - sin()] [x]
#              (y')   [sin() + cos()] [y]
def R(x):
    return [[round(math.cos(x)), - round(math.sin(x))], [round(math.sin(x)), round(math.cos(x))]]

def Rotation(str, d):
    result = []
    if str == 'L' : # left
        rMatrix = R(math.radians(90))
    else: # right 
        rMatrix = R(math.radians(-90))
    
    # 회전 변환 행렬에 d 곱해서 계산하기  
    for i in range(len(rMatrix)):
        temp = 0
        for j in range(len(rMatrix[0])):
            temp += rMatrix[i][j] * d[j]
        result.append(temp)
    
    return result

N = int(input())
arr = [[0 for _ in range(N)] for _ in range(N)]
snake = [[0 for _ in range(N)] for _ in range(N)]
snake[0][0] = 1

# 사과 위치는 1로 표시
K = int(input())
for _ in range(K):
    row, col = map(int, input().split())
    arr[row - 1][col - 1] = 1

# 뱀의 이동 경로 
L = int(input())
trace = deque()
for _ in range(L):
    x, d = input().split()
    trace.append((int(x), d))
time, rotation = trace.popleft() # x초와 방향 

x, y, second = 0, 0, 1 # 뱀의 시작위치와 시간초
direction = [0, 1] # 처음 이동하는 방향
tail = deque() # 뱀의 꼬리

while True :
    if second - 1 == time:
        direction = Rotation(rotation, direction)
        if trace:
            time, rotation = trace.popleft()
        else: # 더 이상 방향 전환이 없는 경우 time -1 로 설정
            time = -1 
    tail.append([x,y])
    x, y = x + direction[0], y + direction[1]
    
    if (0 > x or x >= N) or (0 > y or y >= N): # 벽에 부딪히는 경우 종료
        break
    if snake[x][y] == 1: # 뱀의 몸통과 부딪히는 경우 
        break

    if arr[x][y] == 0 : # 사과가 없는 경우
        s_x, s_y = tail.popleft()
        snake[s_x][s_y] = 0 # 뱀의 꼬리가 움직이므로 0으로 위치 변경
    else : # 사과가 있는 경우
        arr[x][y] = 0 # 사과를 먹었으므로 1에서 0으로 변경
    
    snake[x][y] = 1
    second += 1

print(second)