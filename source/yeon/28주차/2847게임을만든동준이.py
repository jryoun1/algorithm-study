# 백준 2847 게임을 만든 동준이
# python 
import sys
input = sys.stdin.readline

N = int(input())
gameLevel = list(int(input()) for _ in range(N))
ans = []
for i in range(N-1,0,-1):
    count = 0
    if gameLevel[i] > gameLevel[i-1]:
        continue
    else:
        count = gameLevel[i-1] - gameLevel[i] + 1 
        gameLevel[i-1] -= count
        ans.append(count)
print(sum(ans))