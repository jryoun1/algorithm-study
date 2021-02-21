# 백준 1759 암호만들기
import sys
from itertools import combinations
intput = sys.stdin.readline
a = ['a','e','i','o','u']
L, C = map(int, input().split())
alphabet = list(input().split())
alphabet.sort()
cases = list(combinations(alphabet, L))
ans = []
for case in cases:
    count = 0
    for i in a:
        if i in case:
            count += 1
    if count >= 1 and L - count >= 2:
        ans.append("".join(case))

for answer in ans:
    print(answer)