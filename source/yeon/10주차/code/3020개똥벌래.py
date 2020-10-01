# 백준 3020 개똥벌레
# python solved by
import sys
N, H = map(int,sys.stdin.readline().split())
fromUp = [0 for _ in range(H+1)] #even
fromDown = [0 for _ in range(H+1)] #odd
_sum = [500001]+[0 for _ in range(H)]

for i in range(1, N+1):
    n = int(sys.stdin.readline())
    if i % 2 == 0:
        for j in range(1,n+1):
            fromUp[j] += 1
    else:
        for j in range(1,n+1):
            fromDown[j] += 1

_sum[1] = fromDown[1]
_sum[H] = fromUp[1]
for i in range(2, H):
    _sum[i] = fromUp[i] + fromDown[H + 1 -i]

ans = min(_sum)
print(ans,_sum.count(ans))