# 백준 2003 수들의 합 2
# python solved by two-pointers
import sys
N, M = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

s, e, ans = 0, 0, 0
windowSum = 0
while(True):
    if windowSum >= M:
        if windowSum == M:
            ans += 1
        windowSum -= arr[s]
        s += 1
    elif e == N:
        break
    else:
        windowSum += arr[e]
        e += 1
print(ans)