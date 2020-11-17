# 부분합 이란?
- 배열의 시작점이 s, 끝점이 e라고 할 때, s~e까지의 합을 구하되, 여러번 수행할 경우에 효율적으로 문제를 수행하기 위한 솔루션

- 각각의 인덱스에 대해 부분합을 구하되, 이전 인덱스의 부분합을 최대한 활용 하면 효율적이다.

# 카데인 알고리즘
- 부분합의 한 예로 카데인 알고리즘이 존재한다. dp에 부분합을 저장해 나간다 하면, 해당 인덱스(i+1)에서의 부분합은 이전 단계까지의 최댓값과 해당 인덱스에서의 값을 비교해줘서 계속해서 갱신 시켜주는 알고리즘이다. 점화식으로는   dp[i+1] = max(dp[i]+arr[i+1],arr[i+1]) 와 같이 표현된다.

# 백준 13398
- 카데인 알고리즘을 사용하되, 숫자를 최대 하나까지 지울수 있으므로, i번째 인덱스에서는 1.숫자 하나를 제거 하였는가 2. 숫자를 제거하지 않았는가 로 나눌수 있다.

- 해당 인덱스에서 숫자를 제거하지 않은 부분합을 저장할 리스트는 단순히 카데인 알고리즘에서 보았던 점화식을 사용하여 갱신시켜주면 되고, 숫자를 제거한 부분합을 저장할 리스트는 1.숫자를 하나도 제거하지 않은 i-1번째 까지의 최댓값과(i번째 수를 제거한 경우) 2.숫자를 제거한 i-1번째 까지의 최댓값에서 해당 숫자를 더한 수 중 max값을 저장하며 갱신시킨다.

``` python
n = int(input())
arr = list(map(int, input().split()))
#첫번째리스트는 1회 숫자를 상태에서 최댓값을 담는 리스트
#두번째리스트는 숫자를 지우지 않은 상태에서 최댓값을 담는 리스트
dp = [[0] * n for _ in range(2)]
#초기값 세팅
dp[0][0], dp[1][0] = arr[0], arr[0]

for i in range(1, n):
    #1회 삭제한 dp리스트(dp[0])
    #해당 원소를 지운것 들 중 합의 최댓값과,
    #해당원소를 지우지 않고 앞에서 원소를 지운것들의합 과 해당 원소의합 
    dp[0][i] = max(dp[1][i - 1], dp[0][i - 1] + arr[i])
    #삭제하지 않은 dp리스트(dp[1])
    dp[1][i] = max(dp[1][i - 1] + arr[i], arr[i])

maxNum = float('-inf')
for i in range(2):
    for j in range(n):
        if maxNum < dp[i][j]:
            maxNum = dp[i][j]

print(maxNum)

```

# 백준 2559번
- 연속 몇일동안 온도의 합을 구할지를 입력 받은후, 부분합을 구해나가는데 i번째 부분합을 구할때, i-1번째 부분합에서 i-1번째 원소를 빼주고 i+(연속몇일)번째 원소를 더해주며 부분합 리스트를 갱신시켜나간다.

``` python
from sys import stdin

N,K=map(int,stdin.readline().split())
temp=list(map(int,stdin.readline().split()))
#부분합을 저장할 리스트
_sum=[0 for _ in range(N-K+1)]
_max=-10000001

for i in range(N-(K-1)):
    #N과 K가 같을경우, 단순히 모든 온도의 합을 출력해준다.
    if N==K:
        _max=sum(temp)
        break
    #_sum[0]은 계산을 해주고 시작한다.
    if i==0:
        for j in range(K):
            _sum[i]+=temp[j]
    else:
        #해당 순번의 부분합은 바로 이전의 부분합에서 첫번째 온도를 빼주고,
        #해당 순번의 부분합 중 가장 마지막 원소를 더해주면 된다.
        _sum[i]=_sum[i-1]-temp[i-1]+temp[i+(K-1)]
    _max=max(_max,_sum[i])
print(_max)
```

# 백준 11659번


 ``` python
 from sys import stdin
N,sum_N=map(int,stdin.readline().split())
num_li=[0]+list(map(int,stdin.readline().split()))
sub_sum=[0 for _ in range(N+1)]
for i in range(1,N+1):
    sub_sum[i]=sub_sum[i-1]+num_li[i]
for _ in range(sum_N):
    s,e=map(int,stdin.readline().split())
    print(sub_sum[e]-sub_sum[s-1])
    
 ```

 # 백준 11660번
 
 - 열별로 해당 인덱스까지 부분합이 담긴 리스트를 만들고 두 좌표를 입력받아 계산한다.
  ``` python
    from sys import stdin
    N, M = map(int, input().split())

    #원래 매트릭스 받기
    matrix = [list(map(int, stdin.readline().split())) for _ in range(N)]

    #열별로 sum한 매트릭스 따로 만들어주기 
    for i in range(N):
        for j in range(N):
            if j == 0:
                pass
            else:
                matrix[i][j] += matrix[i][j-1] 
    for _ in range(M):
        sub_sum=0
        x1,y1,x2,y2=map(int,stdin.readline().split())
        x1,y1,x2,y2=x1-1,y1-1,x2-1,y2-1
        for x in range(x1,x2+1):
            sub_sum+=matrix[x][y2]
            if y1>0:
                sub_sum-=matrix[x][y1-1]
            
        print(sub_sum)

  ```