# 백준 2529 부등호
import sys
import operator
from itertools import permutations, combinations_with_replacement
input = sys.stdin.readline
N = int(input())
array = list(input().split())
operations = []
ans = []
for string in array:
    if string ==  "<":
        operations.append(operator.lt)
    else:
        operations.append(operator.gt)

num = [i for i in range(10)]

for case in permutations(num, N+1):
    flag = True
    for i in range(N):
        if not operations[i](case[i], case[i+1]):
            flag = False
            break
    if flag:
        ans.append(case)

print("".join([str(i) for i in ans[-1]]))
print("".join([str(i) for i in ans[0]]))