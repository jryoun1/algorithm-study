# 백준 1865 웜홀
# python solved by bellman-ford
import sys
input = sys.stdin.readline
INF = 100000000
TC = int(input())
for _ in range(TC):
    N, M, W = map(int, input().split())
    distance = [[] for _ in range(N+1)]
    for _ in range(M):
        s, e, t = map(int, input().split())
        distance[s].append([e, t])
        distance[e].append([s, t])
    for _ in range(W):
        s, e, t = map(int, input().split())
        distance[s].append([e, -t])

    dp = [INF] * (N + 1)
    update = False
    for i in range(1, N+1):
        for j in range(1, N+1):
            for vec, wei  in distance[j]:
                if dp[vec] > wei + dp[j]:
                    dp[vec] = wei + dp[j]
                    if i == N:
                        update = True
    if update:
        print("YES")
    else:
        print("NO")