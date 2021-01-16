# 백준 16562 친구비
# python solved by union-find
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def find(x):
    if x == graph[x][0]: return x
    graph[x][0] = find(graph[x][0])
    return graph[x][0]

def union(x,y):
    x = find(x)
    y = find(y)
    if x == y: return
    graph[y][0] = x

N,M,K = map(int, input().split())
cost = list(map(int, input().split()))
graph = {i:[i,cost[i]] for i in range(N)}
for _ in range(M):
    v, w = map(int, input().split())
    union(v-1,w-1)

for i in range(N):
    find(i)

ans = sorted(graph.items(), key = lambda x : (x[1], x[1][1]))

first = ans[0][1][0]
totalCost = ans[0][1][1]

for index, [root, cost] in ans:
    if root == first: continue
    else:
        first = root
        totalCost += cost

if totalCost <= K:
    print(totalCost)
else:
    print("Oh no")