# 백준 1963 소수 경로
# python solved by 에라토스테네스의 체 & bfs
from collections import deque
import sys, copy
T = int(sys.stdin.readline())
N = 10000 # N보다 작은 모든 소수를 찾을 것이다.
primeCheck = [False, False] + [True] * (N - 1)
primes = []
for i in range(2, N + 1):
    if primeCheck[i]:
        primes.append(i)
        for j in range(2 * i, N + 1, i):
            primeCheck[j] = False
primes = primes[168:] # 1000이하의 소수의 개수는 168개이므로 1000이상만 확인할것이다.

def bfs(before, after):
  	# 각 자리수 비교를 위해서 str형태로 저장
    dq = deque([[list(str(before)),0]])
    visited = {before}

    while True:
        temp, cnt = dq.popleft()
        if int("".join(map(str,temp))) == after:
            return cnt
        else:
            for i in range(4): # 총 4개의 자리수
                for j in range(10): # 각 자리수가 될 수 있는 숫자 0 - 9 까지
                    if temp[i] == str(j): # 만약 해당 자리수의 숫자가 이미 j인 경우에는 바꾸지 통과
                        continue
                    else:
                        tempCopy = copy.deepcopy(temp) # python에서 deepcopy는 완전 복사 따라서 아래에서 값을 바꿔도 temp의 값은 바뀌지 않게됨 (깊은 복사와 얕은 복사의 개념)
                        tempCopy[i] = str(j)
                        tempCopyToInt = int("".join(map(str,tempCopy)))
                        if tempCopyToInt not in visited and tempCopyToInt >= 1000 and tempCopyToInt in primes:
                            visited.add(tempCopyToInt)
                            dq.append([tempCopy, cnt+1])                        

for _ in range(T):
    before, after = map(int, sys.stdin.readline().split())
    print(bfs(before, after))