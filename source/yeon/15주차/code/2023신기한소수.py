# 백준 2023 신기한 소수
# python solved by dfs
import math
N = int(input())
primeNums = [2, 3, 5, 7]

def isPrime(num):
    if num < 2: return False
    # N의 루트씌운 것까지 나눠봤을 때 나눠지는 숫자가 있으면 소수가 아님
    for i in range(2, int(math.sqrt(num)) + 1): 
        if num % i == 0 : return False
    return True


def dfs(primeNumber, count):
    if count == 0: 
        print(primeNumber)
    # 짝수가 오게되면 무조건 소수가 아니므로 홀수만 더해주고 확인
    for i in range(1,10,2): 
        nextDigitPrime = primeNumber * 10 + i
        if isPrime(nextDigitPrime):
            dfs(nextDigitPrime, count-1)

for primeNumber in primeNums:
    dfs(primeNumber, N-1)
