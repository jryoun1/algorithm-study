N,M=map(int,input().split(' '))
arr=list(map(int,input().split(' ')))
#sort하면 틀렸다고 나옴 이유를 모르겠음
# arr.sort()

#이분탐색의 start를 주어진 레슨의 길이중 최댓값을,
#이분탐색의 end를 주어진 레슨의 길이의 총 합으로 둔다.

_max=max(arr)
s,e=_max,sum(arr)

while s<=e:
    tmp=0
    count=0
    m=(s+e)//2
    for i in arr:
        tmp+=i
        if tmp>m:
            count+=1
            tmp=i
    count+=1
    if count>M:
        s=m+1
    else:
        e=m-1
print(s)



