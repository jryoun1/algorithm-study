# 백준 1254 팰린드롬 만들기
import sys
input = sys.stdin.readline

S = input().strip()
n = len(S)
for i in range(n):
    if S[i:] == S[i:][::-1]:
        print(n + i)
        break