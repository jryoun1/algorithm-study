# # 백준 11657 타임머신
# # python solved by bellmanFord
import sys 
input = sys.stdin.readline
INF = 100000000
def bellmanFord(start):
    distance[start] = 0
    for i in range(1,N+1):
        for j in range(1,N+1):
            for next_node, cost in adj[j]:
                if distance[j] != INF and distance[next_node] > distance[j] + cost:
                    distance[next_node] = distance[j] + cost
                    if i == N:
                        return True
    return False

N, M = map(int, input().split())
adj = [[] for _ in range(N+1)]
distance = [INF] * (N+1)
for _ in range(M):
    s, e, cost = map(int, input().split())
    adj[s].append([e, cost])
negative_cycle = bellmanFord(1)

if negative_cycle:
    print("-1")
else:
    for i in range(2,N+1):
        if distance[i] == INF:
            print("-1")
        else:
            print(distance[i])