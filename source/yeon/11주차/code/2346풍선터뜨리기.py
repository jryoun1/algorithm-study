# 백준 2346 풍선 터뜨리기 
# python solved by deque
from collections import deque
N = int(input())
numbers = list(map(int,input().split()))
dq = deque()
ans = []

for i in range(1, N+1):
    dq.append(i)

cnt, target = 0, numbers[0]
ans.append(dq.popleft())
while dq:
    # when numbers are bigger than 1
    # it has to move to right side
    # in case of 1, it doesn't have to move at all
    if target > 0 :
        dq.rotate(-target + 1)
    # when numbers are smaller than 0 
    # it has to move to left side
    elif target < 0 : 
        dq.rotate(-target)
    # get cnt which is index of numbers
    temp = dq.popleft()
    cnt = temp - 1
    dq.appendleft(temp)

    ans.append(dq.popleft())
    target = numbers[cnt]    
print(*ans)

# from collections import deque
# N = int(input())
# numbers = list(map(int,input().split()))
# dq = deque()
# ans = []

# for i in range(1, N+1):
#     dq.append(i)

# cnt, target = 0, numbers[0]
# ans.append(dq.popleft())
# while dq:
#     if target > 0 :
#         while target - 1 > 0:
#             temp = dq.popleft()
#             dq.append(temp)
#             target -= 1
#     elif target < 0 : 
#         while target + 1 <= 0:
#             temp = dq.pop()
#             dq.appendleft(temp)
#             target += 1
#     temp = dq.popleft()
#     cnt = temp - 1
#     dq.appendleft(temp)
        
#     ans.append(dq.popleft())
#     target = numbers[cnt] 

# print(*ans)