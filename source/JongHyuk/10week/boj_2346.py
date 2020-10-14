N=int(input())
num_li=list(map(int,input().split(' ')))
number=[i for i in range(1,N+1)]
num_li=list(zip(num_li,number))
ans=[]
while num_li:
    _pop=num_li[0]
    jump=_pop[0]
    ans.append(_pop[1])
    num_li.pop(0)
    N-=1
    if N==1:
        ans.append(num_li[0][1])
        break
    
    if jump>0:
        jump=(jump-1)%N
        for _ in range(jump):
            num_li.append(num_li.pop(0))
    else:
        jump=abs(jump)
        jump=jump%N
        for _ in range(jump):
            num_li.insert(0,num_li.pop())
for i in ans:
    print(i,end=' ')




