# 백준 11725 트리의 부모찾기
# python solved by dfs
import sys
sys.setrecursionlimit(10**9)
def dfs(node):
    for i in tree[node]:
        if ans[i] == 0:
            ans[i] = node
            dfs(i)

N = int(sys.stdin.readline())
tree = {}
for i in range(1, N+1):
    tree[i] = set()
for _ in range(N-1):
    a, b = map(int,sys.stdin.readline().split())
    tree[a].add(b)
    tree[b].add(a)
ans = [0]*(N+1)
dfs(1)
for i in range(2,N+1):
    print(ans[i])