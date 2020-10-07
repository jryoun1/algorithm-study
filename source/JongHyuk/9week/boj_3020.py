N,H=map(int,input().split(' '))
under_obstacle=[0]
upper_obstacle=[0]
def binary_search_under(lis,height):
    s,e=1,N//2
    # for i in range(1,H+1):
    while s<=e:
        m=(s+e)//2
        if lis[m]>=height:
            e=m-1
        else:
            s=m+1
    return N//2-e


for i in range(N):
    if i%2==0:
        under_obstacle.append(int(input()))
    else:
        upper_obstacle.append(int(input()))
under_obstacle.sort()
upper_obstacle.sort()
count=[0 for _ in range(N+1)]

for i in range(1,H+1):
    tmp=binary_search_under(under_obstacle,i)+binary_search_under(upper_obstacle,H-i+1)
    count[tmp]+=1
# print(count)

print(count.index(max(count)),max(count))
    




