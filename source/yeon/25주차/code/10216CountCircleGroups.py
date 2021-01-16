# 백준 10216 Count Circle Groups
# python solved by Union-Find
import sys
import math
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def find(x):
    if x == graph[x]: return x
    graph[x] = find(graph[x])
    return graph[x]

def union(x,y):
    x = find(x)
    y = find(y)
    if x == y: return
    if x < y:
        graph[y] = x
    else: graph[x] = y

T = int(input())
for _ in range(T):
    N = int(input())
    graph = {i:i for i in range(N)}
    location = []

    for _ in range(N):
        x, y, r = map(int,input().split())
        location.append([x,y,r])
    
    cnt = N
    for i in range(N):
        for j in range(i+1,N):
            if  find(i) != find(j):
                if (location[i][0]-location[j][0])**2 + (location[i][1] - location[j][1])**2 <= (location[i][2] + location[j][2])**2:
                    union(i,j)
                    cnt -= 1
    print(cnt)