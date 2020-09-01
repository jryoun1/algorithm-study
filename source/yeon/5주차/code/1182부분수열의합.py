# 백준 1182 부분수열의 합
# python solved by combinations and brute-force
from itertools import combinations

N, S = map(int, input().split())
arr = list(map(int,input().split()))

cnt = 0
# make combinations 1 to N
# and check the sum of each case 
# if there's any answer exist 
for i in range(1,N+1):
    a = list(combinations(arr,i))
    for j in a :
        sum = 0
        for h in range(i):
            sum += j[h]
        if sum == S :
            cnt +=1
print(cnt)