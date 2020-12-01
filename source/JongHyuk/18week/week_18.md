# Two Pointer 알고리즘 이란?
-  1차원 배열이 존재하고, 그 1차원 배열에서 각자 다른 원소를 가리키고 있는 2개의 포인터를 조작하면서 원하는 알고리즘이다.

- 답이되는 원소들이 연속적일 경우(앞에서 부터 차례로 확인하며 부분합이 특정수가 되는 갯수를 찾는문제가 대표적) 사용

# Sliding Window 알고리즘 이란?
- 투포인터 알고리즘과 비슷하지만, 어느 순간에도 구간의 넓이가 동일하다는 차이점이 존재한다.


# 백준 2003번

- 투포인터 알고리즘을 사용하여 해결

``` python
from sys import stdin
N,M=map(int,stdin.readline().split())
#인덱스 1부터 시작하므로 인덱스0을 0세팅후 시작
arr=[0]+list(map(int,stdin.readline().split()))
start,end=0,0
sum=0
cnt=0
while True:
    #sum이 주어진 수랑 같은경우 cnt증가시켜주고, end를 증가시켜준다.
    #sum이 더 작은경우, end를 증가시켜준다.
    if sum<=M:
        if sum==M:
            cnt+=1
        end+=1
        if end==len(arr):
            break
        sum=sum+arr[end]
    #sum이 더 큰 경우, start를 증가시키며 sum에서 빼나간다.
    #start가 end를 앞지르는 경우는 존재하지 않는다.
    #주어진 M이 음수가 되는 경우는 없기 때문
    elif sum>M:
        sum=sum-arr[start]
        start+=1
print(cnt)
```

# 백준 2096번

- 최악의경우 행이 100,000개가 되므로, 이를 해결하기 위하여 슬라이딩 윈도우 기법을 사용한다.

- tmpMax,tmpMin리스트를 매번 생성해주어(각각 크기가 3인 1차원리스트) 값을 갱신해나간다.

``` python

from sys import stdin
import copy
N=int(stdin.readline())

for n in range(N):
    line=[int(x) for x in stdin.readline().split()]
    #첫 시작은 이전 dp배열이 없으므로 입력받은 line리스트를 그대로 dp배열에 넣어준다.
    if n==0:
        dpMax=copy.deepcopy(line)
        dpMin=copy.deepcopy(line)
    #dp를 max,min각각 갱신해 나간다.
    #메모리 제한 때문에 dp를 1행으로 유지하며 갱신시켜나간다.
    else:
        tmpMax=copy.deepcopy(dpMax)
        tmpMin=copy.deepcopy(dpMin)
    
        for i in range(3):
            #인덱스가 0일 때 dpMax는 바로 위의 행에서 인덱스가 0,1 에 해당하는 값들중 최대값+현재 행의 값으로 갱신시켜준다.
            #인덱스가 0일 때 dpMin은 바로 위의 행에서 인덱스가 0,1 에 해당하는 값들중 최소값+현재 행의 값으로 갱신시켜준다
            if i==0:
                dpMax[i]=max(tmpMax[i],tmpMax[i+1])+line[i]
                dpMin[i]=min(tmpMin[i],tmpMin[i+1])+line[i]
            elif i==1:
                dpMax[i]=max(tmpMax[i-1],max(tmpMax[i],tmpMax[i+1]))+line[i]
                dpMin[i]=min(tmpMin[i-1],min(tmpMin[i],tmpMin[i+1]))+line[i]
            else:
                dpMax[i]=max(tmpMax[i],tmpMax[i-1])+line[i]
                dpMin[i]=min(tmpMin[i],tmpMin[i-1])+line[i]

print(max(dpMax),min(dpMin))
            

```

# 백준 2531번

- 처음부터 시작해 k개씩 묶어가면서 몇가지 종류의 초밥이 포함되어있는지 세어준다.
- 쿠폰에 적힌 초밥의 종류가 k개 안에 포함되어 있지 않으면 +1 해주어서 다음 결과에 반영해준다.

``` python
from sys import stdin
N,d,k,c=map(int,stdin.readline().split())
fish=[]
for _ in range(N):
    fish.append(int(stdin.readline()))
fish=fish+fish
eat_check=[0 for _ in range(d+2)]
kind=0
#첫번째 초밥 묶음을 계산한다.
#먹은 종류의 초밥을 count해줄 eat_check리스트를 초밥 종류만큼 만들고 0으로 세팅한 뒤,
#해당 종류의 초밥이 나올때 마다 갯수를 증가시켜준다.
#만약 해당 초밥묶음에서 쿠폰에 적힌 번호의 초밥이 포함되지 않는경우에,
#_max값을 갱신시켜줄때, 쿠폰에 적힌 번호의 초밥을 더해주면서 갱신한다.
for i in range(k):
    if eat_check[fish[i]]==0:
        kind+=1
        eat_check[fish[i]]+=1
    else:
        eat_check[fish[i]]+=1
_max=0
if eat_check[c]==0:
    _max=max(_max,kind+1)
else:
    _max=max(_max,kind)

#슬라이딩 윈도우 기법을 사용
for i in range(k,N+k):
    #빼줘야 할 초밥의 check를 1 감소 시켜주고,
    eat_check[fish[i-k]]-=1
    #빼준 초밥의 check가 0이면 kind에서 1 감소시킨다.
    if eat_check[fish[i-k]]==0:
        kind-=1
    #더해줄 초밥의 check가 0이면 kind와 해당 초밥의 check를 1씩 증가
    if eat_check[fish[i]]==0:
        kind+=1
        eat_check[fish[i]]+=1
    #0ㅇ아니면 단순히 check만 증가시켜줌
    else:
        eat_check[fish[i]]+=1
    #쿠폰에 적힌 초밥의 포함 여부에따라 _max값을 다르게 갱신시킨다.
    if eat_check[c]==0:
        _max=max(_max,kind+1)
    else:
        _max=max(_max,kind)
    # if _max==k+1:
    #     break
print(_max)
```

# 백준 11728번
- 두 배열이 정렬 되어있으므로, 포인터를 각각 A,B리스트에 두고 대소 비교를 하며 결과 리스트에 하나씩 복사해준다. 만약, A,B리스트중 한개의 리스트라도 끝 원소까지 결과 리스트에 옮겨지면 나머지 리스트에 남은 원소들을 순차적으로 결과리스트에 이어붙여준다.

 ``` python

from sys import stdin
N,M=map(int,stdin.readline().split())
A=list(map(int,stdin.readline().split()))
B=list(map(int,stdin.readline().split()))
res=[]
a_ptr,b_ptr=0,0
#리스트별로 포인터를 따로두고, 
#차례로 해당리스트의 해당포인터에 해당하는 원소들을 비교하며
#오름차순으로 res리스트에 넣어준다.
#각 리스트는 오름차순으로 정렬 되있으므로 둘중에 하나라도 포인터가 해당 리스트의 끝까지 가게되면
#res에 나머지 리스트를 그대로 이어붙이기만하면 정답이다.
while a_ptr<N and b_ptr<M:
    if A[a_ptr]<=B[b_ptr]:
        res.append(A[a_ptr])
        a_ptr+=1
    else:
        res.append(B[b_ptr])
        b_ptr+=1
if a_ptr==N:
    res=res+B[b_ptr:]
else:
    res=res+A[a_ptr:]
print(*res)
 ```