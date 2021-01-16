# 백준 1976 여행가자
# python solved by Union-Find
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def find(index):
    if graph[index] == index: 
        return index
    # path compression 최적화 진행
    graph[index] = find(graph[index])
    return graph[index]

def union(x, y):
    x_parent = find(x)
    y_parent = find(y)
    if x_parent == y_parent: return
    graph[y_parent] = x_parent

N = int(input())
M = int(input())
graph = {i:i for i in range(N)}
disjointGraph = []

for i in range(N):
    a = list(map(int,input().split()))
    disjointGraph.append(a)

for i in range(N):
    for j in range(N):
        if disjointGraph[i][j] == 1:
            union(i,j)

route = list(map(int,input().split()))
ans = set([find(i-1) for i in route])
if len(ans) > 1:
    print("NO")
else:
    print("YES")