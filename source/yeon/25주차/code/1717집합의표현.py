# 백준 1717 집합의 표현
# python solved by union-find
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def find(x):
    if x == graph[x]: return x
    graph[x] = find(graph[x]) # path-compression진행 
    return graph[x]

def union(x,y):
    x_parent = find(x)
    y_parent = find(y)
    if x_parent == y_parent: return
    # 랭크에 의한 합치기 (Union by rank)
    if rank[x_parent] > rank[y_parent]:
        x_parent, y_parent = y_parent, x_parent
    graph[x_parent] = y_parent
    if rank[x_parent] == rank[y_parent]:
        rank[y_parent] += 1

N, M = map(int, input().split())
graph = {i:i for i in range(N+1)}
rank = {i:1 for i in range(N+1)}
for _ in range(M):
    case, x, y = map(int, input().split())
    if case == 0:
        union(x, y)
    else:
        if find(x) == find(y):
            print("YES")
        else:
            print("NO")