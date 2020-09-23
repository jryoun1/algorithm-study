# 백준 10942 팰린드롬
# python solved by dynamic programming
import sys

N = int(input())
arr = [int(i) for i in sys.stdin.readline().split()]
dp = [[0 for _ in range(N)] for _ in range(N)]

# if s and e is same it's always be palindrome 
# this is case of just one element
for i in range(N):
    dp[i][i] = 1

# if the range of s and e is 2 
# and if element of s and e are same then it's palindrome
for i in range(N-1):
    if arr[i] == arr[i+1]:
        dp[i][i+1] = 1

# if the range of s and e is over than 2 (3~)
# we can just compare the first and last element and see
# if there's palidrome between the range from dp[][] 
for l in range(2,N):
    for i in range(N-l):
        if arr[i] == arr[i+l] and dp[i+1][i+l-1] == 1 :
            dp[i][i+l] = 1


M = int(input())
for _ in range(M):
    s, e = [int(i) for i in sys.stdin.readline().split()]
    print(dp[s-1][e-1])