from itertools import combinations

height=[]
for _ in range(9):
    height.append(int(input()))

height_comb=list(combinations(height,7))
for height_comb in height_comb:
    if sum(height_comb)==100:
        height_comb=list(height_comb)
        height_comb.sort()
        for i in range(len(height_comb)):
            print(height_comb[i])
        break

