# 백준 1644 소수의 연속합
# python solved by 에라토스테네스의 체 & two pointer
import sys
N = int(sys.stdin.readline())
primeCheck = [False, False] + [True] * (N - 1)
primes = []
for i in range(2, N + 1):
    if primeCheck[i]:
        primes.append(i)
        for j in range(i * 2, N + 1, i):
            primeCheck[j] = False

start, end, ans = 0, 0, 0
_sum = 0
while True:
    if _sum >= N:
        if _sum == N:
            ans += 1
        _sum -= primes[start]
        start += 1
    elif end == len(primes):
        break
    else:
        _sum += primes[end]
        end += 1
    print(_sum)
print(ans)