# 백준 1389 케빈 베이컨의 6단계 법칙
# python solved by floydwarshall
import sys
input = sys.stdin.readline
INF = 5001
def floydWarhall():
    for k in range(1, N+1): # 거처가는 노드
        for i in range(1, N+1): # 출발 노드
            for j in range(1, N+1): # 도착 노드
                if i == j: 
                    friends[i][j] = 0
                if friends[i][j] > friends[i][k] + friends[k][j]:
                    friends[i][j] = friends[i][k] + friends[k][j]

N, M = map(int, input().split())
friends = [[INF]* (N+1) for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    friends[a][b] = 1
    friends[b][a] = 1
floydWarhall()
ans = []
for i in range(1,N+1):
    ans.append([sum(friends[i])-5001,i])
a = sorted(ans)
count, _min = a[0]
print(_min)