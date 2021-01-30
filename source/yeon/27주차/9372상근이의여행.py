# 백준 9372 상근이의 옇애
# python solved by BFS
import sys
input = sys.stdin.readline
def bfs(start):
    global result 
    visited[start] = 1
    q = [start]
    while q:
        c = q.pop()
        for a in tree[c]:
            if visited[a] != 1:
                visited[a] = 1
                result += 1
                q.append(a)

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    tree = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        tree[a-1].append(b-1)
        tree[b-1].append(a-1)
    result = 0
    visited = [0] * N
    bfs(0)
    print(result)