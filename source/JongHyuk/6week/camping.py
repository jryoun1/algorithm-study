lst=[]
cnt=0
while True:
    L,P,V=map(int,input().split(' '))
    if L==0 and P==0 and V==0:
        break
    if L<(V%P):
        tmp=(V//P)*L+L
    elif L>=(V%P):
        tmp=(V//P)*L+(V%P)
    lst.append(tmp)
    cnt+=1

for i in range(1,cnt+1):
    print('Case',str(i)+':',lst[i-1])