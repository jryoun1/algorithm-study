# 백준 2668 숫자고르기
# python solved by dfs
import sys
sys.setrecursionlimit(10**9)
def dfs(key):
    num = tree[key][0] # num은 key에 해당하는 원소값 
    # 만약 num을 방문했던 적이 있으면 
    # 그 숫자는 서로 순환되는 것이므로 ans에 num, key 추가
    if num in visited: 
        ans.add(num)
        ans.add(key)
    # num이 방문한 적이 없으면 
    # 방문했다고 표시하고 dfs(num) 진행후 만약 정답이 아닌 경우 pop()
    else:
        visited.append(key)
        dfs(num)
        visited.pop()

N = int(sys.stdin.readline())
tree = {}
for i in range(1, N + 1): # 딕셔너리 key값 및 value형태 설정
    tree[i] = []
for i in range(1, N + 1): # 딕셔너리 value에 사용자로부터 입력값 넣기
    num = int(sys.stdin.readline())
    tree[i].append(num)
ans = set() # 정답을 저장할 set

for i in range(1,N): # 1 부터 N까지 ans에 없으면 dfs 들어감
    visited = []
    if i not in ans:
        dfs(i)

print(len(ans))
for i in sorted(ans): # 정답은 오름차순으로 해줘야함 
    print(i)