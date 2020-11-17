# BackTracking 이란?

- 해를 찾아가는 도중에 해당 경로가 해가 아닐 경우 그 경로를 더이상 진행하지 않고 되돌아가는 방법을 말한다. 

- 주로 DFS알고리즘과 같이 쓰이며, 조건문 등을 걸어 답이 될 수 없는 경우에 탐색을 중지시키고, 이전으로 돌아가서 다른 경우를 탐색하게끔 구현할 수 있다.

- BackTracking 기법에서 해가 될 가능성이 있는 경우 유망하다(Promising) 라고 일컫고, 유망하지 않은 노드에 가지 않는 것을 가지치기(pruning)를 한다고 표현하다.


# 백준 1941번

- 여러개의 자리중에 7개의 자리를 선택후, 해당 조합에서 S의 갯수를 센 뒤 4개 이상이면 서로 인접한지 판단해준다.

- S의 갯수가 4개 이상이면, 깊이우선탐색(dfs)를 진행해 주는데, 진행하기 전에 해당 자리의 방문 여부를 체크하기위한 visit리스트, 해당 자리가 내가 뽑은 7개의 자리중 한 자리에 해당하는가를 체크하기위한 in_queue 리스트를 만들어준다.

``` python
from itertools import combinations
from sys import stdin
from collections import deque
seat=[]
res=0
for _ in range(5):
    seat.append(list(input()))
seat_num=[str(i) for i in range(25)]
permu_seat=list(combinations(seat_num,7))
dx=[-1,1,0,0]
dy=[0,0,-1,1]

#S가 4이상인지 찾는 함수
def s_bigger(tmp):
    cnt=0
    for position in tmp:
        x,y=position
        if seat[x][y]=='S':
            cnt+=1
        if cnt>=4:
            return True
    return False

#뽑은 7개의 자리가 서로 인접한지 찾는 함수
def is_adjacent(seat_permutaiton):
    tmp=deque()
    cnt=1
    #전체 자리 중 뽑은 7개의 자리가 맞는지 확인하기 위한 리스트
    in_queue=[[False for _ in range(5)] for _ in range(5)]
    #뽑은 7개의 자리번호를 이차원배열 형식으로 바꿔준다
    for number in seat_permutaiton:
        x=int(number)//5
        y=int(number)%5
        tmp.append([x,y])
        #이차원 형식의 배열로 바꿔주면서 해당자리의 뽑힘 여부를 확인하기위해
        in_queue[x][y]=True
    
    if s_bigger(tmp):
        visit=[[0 for _ in range(5)] for _ in range(5)]
        q=deque([tmp[0]])
        visit[tmp[0][0]][tmp[0][1]]=1
        while q:
            x,y=q.popleft()
            for i in range(4):
                tmp_x=x+dx[i]
                tmp_y=y+dy[i]
                if 0<=tmp_x<5 and 0<=tmp_y<5 and visit[tmp_x][tmp_y]==0 and in_queue[tmp_x][tmp_y]==True:
                    q.append([tmp_x,tmp_y])
                    visit[tmp_x][tmp_y]=1
                    cnt+=1
        if cnt==7:
            global res
            res+=1

for i in permu_seat:
    is_adjacent(i)

print(res)

```


# 백준 14888번

- dfs를 사용한방법, 단순 전역탐색 두가지 방법 모두 통과한다.

- 주어진 연산자 갯수가 수열의 갯수와 딱 일치하므로, 순열로 모든 경우를 다 뽑아줘서 하나하나 계산을 해가며 max,min값을 갱신시키는 방법(전역탐색), 남은 연산자의 갯수에 따라 dfs를 달리 진행하는 방법으로 풀었다.

``` python
from itertools import permutations
from sys import stdin

N=int(stdin.readline())
num_li=list(map(int,stdin.readline().split()))
operator_cnt=list(map(int,stdin.readline().split()))
operator=['+','-','*','//']
real_operator=[]
for i in range(4):
    if operator_cnt[i]==0:
        continue
    else:
        for j in range(operator_cnt[i]):
            real_operator.append(operator[i])
len_realoper=len(real_operator)
operator_permutation=set(permutations(real_operator,len_realoper))
_max=-1000000001
_min=1000000001
for perm in operator_permutation:
    res=num_li[0]
    for i in range(len_realoper):
        if perm[i]=='-':
            res-=num_li[i+1]
        elif perm[i]=='+':
            res+=num_li[i+1]
        elif perm[i]=='*':
            res*=num_li[i+1]
        else:
            if res<0:
                res=-((-res)//num_li[i+1])
            else:
                res=res//num_li[i+1]
    _max=max(_max,res)
    _min=min(_min,res)
print(_max)
print(_min)
```

``` python
'''
i ->전체 연산자의 수를 count할 변수
res ->연산을 수행한 숫자를 담기위한 변수
'''
N = int(input())
nums = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())

min_, max_ = 1e9, -1e9

def dfs(i, res, add, sub, mul, div):
    global max_, min_
    if i == N:
        max_ = max(res, max_)
        min_ = min(res, min_)
        return

    else:
        if add:
            dfs(i+1, res+nums[i], add-1, sub, mul, div)
        if sub:
            dfs(i+1, res-nums[i], add, sub-1, mul, div)
        if mul:
            dfs(i+1, res*nums[i], add, sub, mul-1, div)
        if div:
            dfs(i+1, int(res/nums[i]), add, sub, mul, div-1)

dfs(1, nums[0], add, sub, mul, div)
print(max_)
print(min_)
```


# 백준 9663번

- 행 또는 열을 기준으로 첫번째 퀸의 모든 경우의 수만큼 돌면서 dfs를 수행한다.

- 해당 차례의 퀸이 가질수 있는 위치를 queue에다 집어놓고 마찬가지로, 모든 경우의 수만큼 돌면서 dfs를 수행한다.(가질수 있는 위치가 없을경우 return 해줌으로써, backtracking을 수행)

 ``` python
 N=int(input())
column=0
cnt=0
res=0

def dfs(lis):
    if len(lis)==N:
        global res
        res+=1
        return
    tmp=[i for i in range(N)]
    #해당 순번의 말이 위치할 수 있는 좌표를 뽑는다
    for i in range(len(lis)):
        #같은 행 또는 열에 위치할 경우 제외
        if lis[i] in tmp:
            tmp.remove(lis[i])
        #대각선 상에 위치하는경우를 제외
        if (lis[i]+len(lis)-i) in tmp:
            tmp.remove(lis[i]+len(lis)-i)
        if (lis[i]-len(lis)+i) in tmp:
            tmp.remove(lis[i]-len(lis)+i)
    #해당 순번의 말이 갈수 있는 칸이 없지 않으면
    if tmp !=[]:
        #각각의 경우의수 마다 dfs로 재귀적으로 탐색해준다.
        for i in tmp:
            lis.append(i)
            dfs(lis)
            lis.pop()
    else:
        return 
#첫번째 행 또는 열을 고정한다는 가정하에 첫번째 퀸이 갈수 있는 경우의수
for i in range(N):
    dfs([i])

print(res)

 ```


 # 백준 2023번
 
  ``` python
  N=int(input())
first_value=['2','3','5','7']
value=['1','3','7','9']
ans=[]
def dfs(num):
    #소수 판별뒤, 소수가 아니면 return
    for i in range(2,int(int(num)**0.5)):
        if int(num)%i ==0:
            return
    #입력받은 자릿수 까지 도착하면 출력
    #애초에 리스트자체를 오름차순으로 정렬 해 놓았기 때문에 상관없다
    if len(num)==N:
        print(num)
        return
    #앞에서부터 수를 이어붙여가면서 소수인지를 판별
    for i in value:
        dfs(num+i)

for start in first_value:
    dfs(start)
  ```