import sys
input = sys.stdin.readline
N, M = map(int, input().split())
first, changed = [], []
for _ in range(N):
    row = input().rstrip()
    first.append(list(row))
for _ in range(N):
    row = input().rstrip()
    changed.append(list(row))

def checkEquality():
    for i in range(N):
        for j in range(M):
            if first[i][j] != changed[i][j]:
                return 0
    return 1

def reverse(x, y):
    for i in range(x, x+3):
        for j in range(y, y+3):
            if first[i][j] == "1":
                first[i][j] = "0"
            else:
                first[i][j] = "1"

count = 0
# 이때 검사는 N-2, M-2까지만 검사하면 된다. 
for i in range(N-2): 
    for j in range(M-2):
        if first[i][j] != changed[i][j]:
            reverse(i, j)
            count += 1

if checkEquality():
    print(count)
else:
    print(-1)