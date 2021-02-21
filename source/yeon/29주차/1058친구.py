# 백준 1058 친구
import sys
input = sys.stdin.readline
def bfs(start):
    check[start] = 1
    q = [(start, 0)]
    count = 0
    while q:
        j, cnt = q.pop()
        if cnt >= 2:
            continue
        for k in range(N):
            if not check[k] and friends[j][k]:
                count += 1
                check[k] = 1
                q.append((k, cnt + 1))
    return count

N = int(input())
friends = [[0] * N for _ in range(N)]
for i in range(N):
    relations = list(input().rstrip())
    for j in range(N):
        if relations[j] == 'Y':
            friends[i][j] = 1

ans = 0
for i in range(N):
    check = [0] * N
    ans = max(ans, bfs(i))
print(ans)
