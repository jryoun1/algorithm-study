
import sys
T = int(sys.stdin.readline())
def solve_bf(N, M):
    shortest_route[1] = 0
    for it in range(N):
        for v in range(1, N+1):
            for nv, nw in graph[v]:
                if shortest_route[nv] > (shortest_route[v] + nw):
                    shortest_route[nv] = shortest_route[v] + nw
                    if it == N-1:
                        print("YES")
                        return
    print("NO")
    return

for _ in range(T):
    N, M, W = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(N+1)]
    shortest_route = [1e9] * (N+1)
    #양방향이므로 서로 연결
    for _ in range(M):
        s, e, t = map(int, sys.stdin.readline().split())
        graph[s].append([e, t])
        graph[e].append([s, t])
    #가중치를 마이너스
    for _ in range(W):
        s, e, t = map(int, sys.stdin.readline().split())
        graph[s].append([e, -t])
    solve_bf(N, M)
                        
