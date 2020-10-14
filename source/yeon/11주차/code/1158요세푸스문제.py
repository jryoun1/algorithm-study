# 백준 1158 요세푸스 문제
# python solved by deque
from collections import deque
N, k = map(int,input().split())
dq = deque()

for i in range(1,N+1):
    dq.append(i)
ans = []
while dq:
    # python deque는 rotate 라는 함수가 존재, 즉 원형큐 처럼 사용가능
    # dq = [1, 2, 3]으로 주어졌다고 예를 들면
    # rotate(-n)일 경우 왼쪽으로 회전
    # => dq.rotate(-1) = [2, 3, 1]
    # rotate(n)일 경우 오른쪽으로 회전
    # => dq.rotate(1) = [3, 1, 2]
    dq.rotate(-k+1)
    ans.append(dq.popleft())

print('<',end="")
print(', '.join(map(str,ans)),end="")
print('>')

# from collections import deque
# N, k = map(int,input().split())
# dq = deque()
# for i in range(1,N+1):
#     dq.append(i)
# ans = []
# while dq:  
#     for i in range(k - 1):
#         temp = dq.popleft()
#         dq.append(temp)
#     ans.append(dq.popleft())
# print('<',end="")
# print(', '.join(map(str,ans)),end="")
# print('>')