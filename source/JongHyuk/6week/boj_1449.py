N,L=map(int,input().split(' '))
location=list(map(int,input().split(' ')))
location.sort()
res=0
cnt=1
while len(location)>0:
    length=L-1
    tmp=0
    cnt=1
    if len(location)==1:
        res+=1
        break
    for i in range(1,len(location)):
        tmp+=(location[i]-location[i-1])
        if tmp<=length:
            cnt+=1
            if location[i]==location[-1]:
                res+=1
                for _ in range(cnt):
                    location.clear()

        else:
            res+=1
            for _ in range(cnt):
                location.pop(0)
            break
print(res)

            




