# 백준 1038 감소하는 수 
# python solved by deque
from collections import deque

N = int(input())
q = deque()
cnt = 0
if 0 <= N <= 10 :
    print(N)
elif N == 1022 :
    print(9876543210)
elif N > 1022 :
    print(-1)
else :
    for i in range(1,10):
        q.append(i)
        cnt += 1
    while cnt < N :
        k = q.popleft()
        tmp = k % 10
        for i in range(0, tmp):
            q.append(k*10 + i)
            cnt += 1

            if cnt == N :
                print(k * 10 + i)
                break
