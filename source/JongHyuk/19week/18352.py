#모든 가중치가 1로 같으므로,
#단순히 갈수있는 노드들을 순회하며
#visit 리스트를 갱신하면서 count가 조건과 같아질경우가 정답이다.
import sys
from collections import deque
 
input = sys.stdin.readline
 
n, m, k, x = map(int, input().split())
visited = [False] * (n + 1)
 
path = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b = map(int, input().split())
    path[a].append(b)
 
answer = list()
q = deque()
q.append((x, 0))
while q:
    town, count = q.popleft()
    if count == k:
        answer.append(town)
    elif count < k:
        for con in path[town]:
            if not visited[con]:
                visited[con] = True
                q.append((con, count + 1))
 
if len(answer) == 0:
    print(-1)
else:
    answer.sort()
    for ans in answer:
        print(ans)