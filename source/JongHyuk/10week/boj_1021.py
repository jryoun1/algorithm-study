N,M=map(int,input().split(' '))
q=[i for i  in range(1,N+1)]
pick_list=list(map(int,input().split(' ')))
index=0
count=0
while pick_list:
    target_index=q.index(pick_list.pop(0))
    a=abs(index-target_index)
    b=len(q)-abs(index-target_index)
    if a<b:
        count+=a
    else:
        count+=b
    index=target_index
    q.pop(index)

print(count)

