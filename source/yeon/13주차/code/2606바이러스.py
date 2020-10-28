# 백준 2606 바이러스
# python solved by bfs & deque
from collections import deque
def bfs(start):
    dq = deque()
    dq.extend(graph[start])
    visited = set()
    while dq:
        node = dq.popleft()
        # 이미 방문한 경우 패스
        if node in visited:
            continue
        dq.extend(graph[node])
        visited.add(node)
    print(len(visited) - 1) # 1번 컴퓨터는 제외하고 count 

N = int(input())
K = int(input())
arr = [list(map(int,input().split())) for _ in range(K)]
arr.sort()

graph = dict()
# graph의 key 값을 1번부터 N번까지 설정
for i in range(1,N+1):
    graph[i] = set()

# 서로 연결된 것들을 해당 키 값에 추가해주는데 
# 이때 value의 type이 set이므로 중복된 원소들은 들어가지 않는다.
for i in range(K):
    if arr[i][0] in graph.keys():
        graph[arr[i][0]].add(arr[i][1])
    
    if arr[i][1] in graph.keys():
        graph[arr[i][1]].add(arr[i][0])

bfs(1) # 1번 컴퓨터부터 bfs 시작