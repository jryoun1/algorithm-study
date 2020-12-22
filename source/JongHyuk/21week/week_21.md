# 플루이드와샬 알고리즘이란?
- 모든 최단 경로를 구하는 알고리즘

- 하나의 정점에서 모든 다른 정점까지의 최단거리를 구하는 다익스트라 알고리즘 보다는 느리지만, 한번의 실행으로 모든 노드 간 최단경로를 구할 수 있다.


# 백준 1389

- 친구관계는 양방향이므로 양방향으로 연결 한 뒤, 플루이드와샬 알고리즘을 적용해 업데이트시켜가며 완성된 이차원 리스트의 각 행의 합은 각행의 인덱스에 해당하는 사람의 케빈베이컨 수 이다.

``` python

INF = float('inf')
n, m = map(int, input().split())
link = [[INF]*n for _ in range(n)]

#양방향 연결
for i in range(m):
    x, y = map(int, input().split())
    link[x-1][y-1] = 1
    link[y-1][x-1] = 1

#플루이드와샬
for k in range(n):
    for i in range(n):
        for j in range(n):
            #자기자신일 경우
            if i == j:
                link[i][j] = 0
            #최단 케빈 베이컨 수를 저장
            else:
                link[i][j] = min(link[i][j], link[i][k] + link[k][j])
ans = []
for i in link:
    ans.append(sum(i))
for i in range(n):
    if ans[i] == min(ans):
        print(i+1)
        break
```

# 백준 2458

``` python

from sys import stdin
#입력
N, M = map(int, input().split())
height = [[0 for _ in range(N+1)] for _ in range(N+1)]

for _ in range(M):
    tall, short = map(int,stdin.readline().split())
    height[tall][short] = 1

#플로이드 와샬 알고리즘
for k in range(1, N+1): 
    for i in range(1, N+1):
        for j in range(1, N+1):
            if height[i][j]==1 or (height[i][k] ==1 and height[k][j]==1):
                height[i][j]=1


#출력
answer = 0
for i in range(1, N+1):
    known_height = 0
    for j in range(1, N+1):
        #자신보다 큰사람들과 작은사람과 작은사람들을 세어
        known_height += height[i][j] + height[j][i] 
    #자신을 빼고 모두와의 키 순서를 알 수 있는경우
    if known_height == N-1: 
        answer += 1
print(answer)

```

# 백준 11403

- 그래프를 입력받아 모든 점을 돌며 해당 점에서 갈 수 있는 경우들을 찾는다.

 ``` python

N = int(input())
board=[]
for i in range(N):
    board.append(list(map(int,input().split(' '))))
    
#플로이드 워셜 알고리즘
for k in range(0, N) :
    for i in range(0, N) :
        for j in range(0, N):
            if board[i][k] and board[k][j] :
                board[i][j] = 1
 
for i in range(0, N) :
    _str = ""
    for j in range(0, N) :
        _str += str(board[i][j]) +  " "
    print(_str)
    
 ```

 # 백준 11404
 
  ``` python
    n = int(input())
    m = int(input())
    inf = 100000000
    #2차원 리스트를 주어진 연결정보로 초기화
    s = [[inf] * n for i in range(n)]
    for i in range(m):
        a, b, c = map(int, input().split())
        if s[a - 1][b - 1] > c:
            s[a - 1][b - 1] = c
    #플루이드 와샬
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i != j and s[i][j] > s[i][k] + s[k][j]:
                    s[i][j] = s[i][k] + s[k][j]
    for i in s:
        for j in i:
            if j == inf:
                print(0, end=' ')
            else:
                print(j, end=' ')
        print()
  ```