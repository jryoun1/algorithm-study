from sys import stdin
t=int(stdin.readline())
for _ in range(t):
    n=int(stdin.readline())
    lst=[0,1,1,1,2,2,3,4,5,7,9]
    if n<=10:
        print(lst[n])
        continue
    else:
        for i in range(11,n+1):
            lst.append(lst[len(lst)-1]+lst[len(lst)-5])
    print(lst[n])
