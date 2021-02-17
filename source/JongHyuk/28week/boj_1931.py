from sys import stdin


N=int(stdin.readline())
arr=[]
count=0
for _ in range(N):
    s,e=map(int,stdin.readline().split())
    arr.append([s,e])
arr.sort(key=lambda x: (x[1],x[0]))
s,e=0,0
for i in range(N):
    if e<=arr[i][0]:
        e=arr[i][1]
        count+=1
print(count)




