# 백준 1941 소문난 칠공주
# python solved by dfs
from itertools import combinations
# combinations(조합)과 permutations(순열)의 차이
# 순열은 순서가 있는 조합 즉, 순열은 원소의 순서가 상관이 있음 
# 조합은 순서가 상관 없다
dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

students = [list(input()) for _ in range(5)]
num, ans = [x for x in range(25)], 0
selectedCombination = list(combinations(num,7))

def dfs(x, y, visited, _map):
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < 5 and 0 <= ny < 5 and visited[nx][ny] == 0 and _map[nx][ny] == 1:
            visited[nx][ny] = 1
            dfs(nx,ny, visited, _map)

def IsSover4(selected): # S가 4개 이상이면 True 나머지 False
    cnt = 0
    for i in range(25):
        if selected[i] == True:
            x, y = i // 5, i % 5
            if students[x][y] == "S":
                cnt += 1
    if cnt > 3:
        return True
    else: return False

def IsSevenAdjacent(case): # 7개가 근접해 있는지 dfs 로 확인
    global ans
    _map = [[0] * 5 for i in range(5)]
    visited = [[0] * 5 for i in range(5)]
    for i in range(7):
        x, y = case[i] // 5, case[i] % 5
        _map[x][y] = 1
    cnt = 0
    for i in range(5):
        for j in range(5):
            if _map[i][j] == 1 and visited[i][j] == 0:
                if cnt > 1 : return
                dfs(i,j, visited, _map)
                cnt += 1
    if cnt == 1 : ans += 1

# 조합으로 만들 것들을 하나씩 진행
for case in selectedCombination: 
    selected = [False] * 25
    # 조합에서 선택된 숫자들을 selected에 표시
    for i in range(7):
        selected[case[i]] = True
    # selected에 표시된 것들 중에 S가 몇개인지 확인 
    if IsSover4(selected) :
        # S가 4개 이상인 경우에 대해서 7개가 근접해 있는지 확인
        IsSevenAdjacent(case)

print(ans)