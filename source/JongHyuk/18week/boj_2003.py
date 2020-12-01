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


    
