# 백준 14003 가장 긴 증가하는 부분수열 5
from bisect import bisect_left
# bisect_left => x와 동일한 값이 arr에 존재할 때 x와 동일한 값 위치를 리턴
# bisect_right => x와 동일한 값이 arr에 존재할 때 x와 동일한 값 바로 뒤 위치를 리턴
N = int(input())
a = list(map(int,input().split()))
stack = [a[0]]
dp = [0 for _ in range(N)]

for i in range(N):
    if stack[-1] < a[i]:
        stack.append(a[i])
        dp[i] = len(stack) - 1
    else:
        stack[bisect_left(stack,a[i])] = a[i]
        dp[i] = bisect_left(stack,a[i])

_max, ans = len(stack) , []
print(_max)
for i in range(N-1, -1, -1):
    if _max == 0:
        break
    if dp[i] == _max -1:
        ans.append(a[i])
        _max -= 1
print(*ans[::-1])


# 백준 11053 가장 긴 증가하는  부분 수열
# python solved by dp
# N = int(input())
# arr = list(map(int,input().split()))
# dp = [0 for _ in range(N)]
# for i in range(N):
#     for j in range(i):
#         if arr[i] > arr[j] and dp[i] < dp[j]:
#             dp[i] = dp[j]
#     dp[i] += 1

# print(max(dp))          
 
# 백준 1912 연속합
# python solved by dp
# N = int(input())
# arr = list(map(int,input().split()))
# dp = [0 for _ in range(N)]
# dp[0] = arr[0]

# for i in range(1,N):
#     dp[i] = max(dp[i-1] + arr[i], arr[i])

# print(max(dp))