# 백준 2217 로프
# python
import sys
input = sys.stdin.readline

N = int(input())
ropes = list(int(input()) for _ in range(N))
ropes.sort()
ans = []
for i in range(N):
    ans.append(ropes[i]*(N - i))

print(max(ans))