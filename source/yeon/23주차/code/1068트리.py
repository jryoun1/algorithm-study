# 백준 1068 트리
# python solved by tree
import sys
input = sys.stdin.readline
N = int(input())
parents = list(map(int,input().split()))
delNode = int(input())
tree = {}

for i in range(N):
    if i == delNode or parents[i] == delNode:
        continue
    if parents[i] in tree:
        tree[parents[i]].append(i)
    else:
        tree[parents[i]] = [i]

ans = 0
if -1 in tree:
    que = [-1]
else:
    que = []
    
while que:
    node = que.pop()
    print(node, que)
    if node not in tree:
        ans += 1
    else:
        que += tree[node]
print(ans)