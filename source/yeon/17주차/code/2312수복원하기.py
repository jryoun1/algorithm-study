# 백준 2312 수 복원하기
# 소인수분해 = 합성수를 소수의 곱으로 나타내는 방법
# python solved by 
import sys
N = 100001 # N보다 작은 모든 소수를 찾을 것이다.
primeCheck = [False, False] + [True] * (N - 1)
primes = []
for i in range(2, N + 1):
    if primeCheck[i]:
        primes.append(i)
        for j in range(2 * i, N + 1, i):
            primeCheck[j] = False

T = int(sys.stdin.readline())
primeFactor = []
amount = []
for _ in range(T):
    N = int(sys.stdin.readline())
    while True:
        if N == 1:
            break
        for primeNumber in primes:
            count = 0
            if N % primeNumber == 0: # 나눠진다면 나눠질때까지 나누고 기록
                while N % primeNumber == 0:
                    N = N // primeNumber
                    count += 1
                primeFactor.append(primeNumber)
                amount.append(count)

for i in range(len(primeFactor)):
    print(primeFactor[i], amount[i]) 