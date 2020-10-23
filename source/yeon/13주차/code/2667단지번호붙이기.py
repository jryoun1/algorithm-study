# 백준 2667 단지 번호 붙이기
# python solved by bfs
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs(b, a):
    stack.append((a,b))
    visited[b][a] = 1
    # 이미 bfs로 들어온 것부터가 아파트이므로 한대부터 카운트
    cnt = 1
    while stack:
        x, y = stack.pop()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and visited[ny][nx] == 0:
                if _map[ny][nx] == _map[y][x]:
                    cnt += 1
                    stack.append((nx,ny))
                    visited[ny][nx] = 1
    return cnt
	
N = int(input())
_map = [input() for _ in range(N)]
visited = [[0] * N for _ in range(N)]
stack, total, ans = [], 0, []

for i in range(N):
	for j in range(N):
        # 이때는 1인 경우에만 아파트단지 이기 때문에 1인지도 확인해준다. 
		if visited[i][j] == 0 and _map[i][j] == "1":
			total += 1
			ans.append(bfs(i,j))
ans.sort()
print(total)
print('\n'.join(map(str,ans)))