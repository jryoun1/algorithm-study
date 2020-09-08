# 백준 1038 감소하는 수 
# python solved by deque
from collections import deque

# decreasing numbers are set of those number
# {0,1,2,3,4,5,6,7,8,9} = which means 
# there's only 2^10 - 1(empty set) = 1023 decreasing numbers are exist
N = int(input())
q = deque()
cnt = 0 # value counts amount of decreasing number

# print N if range btw 0-10
if 0 <= N <= 10 :
    print(N)
# print biggest decreasing number if N = 1022
elif N == 1022 :
    print(9876543210)
# print -1 if N is bigger than 1023
elif N > 1022 :
    print(-1)
# if N is btw 11 - 1021
else :
    for i in range(1,10):
        q.append(i)
        cnt += 1
    while cnt < N :
        k = q.popleft()
        # tmp is 1's digit of k (=element in queue) 
        tmp = k % 10
        for i in range(0, tmp):
            # append number which is lower than decreasing number 
            # e.g. k = 98 -> temp = 8 and append 980, 981, 982, 983, 984, 985, 986, 987 
            q.append(k * 10 + i)
            cnt += 1

            if cnt == N :
                print(k * 10 + i)
                break
