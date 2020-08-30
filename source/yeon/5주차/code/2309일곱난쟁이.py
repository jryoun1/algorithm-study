from itertools import combinations
# combinations(조합)과 permutations(순열)의 차이
# 순열은 순서가 있는 조합 즉, 순열은 원소의 순서가 상관이 있음 
# 조합은 순서가 상관 없다

height = []
for i in range(9):
    n = int(input())
    height.append(n)

# make combinations with height list having 7 elements
a = list(combinations(height,7))

for i in a:
    sum = 0
    for j in range(7):
        sum += i[j]
    if sum == 100:
        ans = list(i)
        ans.sort()
        for i in ans:
            print(i,end="\n")
        exit()