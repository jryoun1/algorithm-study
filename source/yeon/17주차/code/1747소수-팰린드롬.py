# 백준 1747 소수&팰린드롬
# python solved by 에라토스테네스의 체
N = int(input())
primeCheck = [False, False] + [True] * (1003002 - 1)
for i in range(2, 1003002):
    if primeCheck[i]:
        for j in range(2 * i, 1003002, i):
            primeCheck[j] = False

for i in range(N, 1003002):
    if primeCheck[i]:
        stringType = str(i)
        if stringType == stringType[::-1]:
            print(stringType)
            break