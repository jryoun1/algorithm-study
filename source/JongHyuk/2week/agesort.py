N=int(input())
people=[]
for i in range(N):
    age,name=input().split()
    people.append([int(age),name,i])
people=sorted(people,key=lambda x:(x[0],x[2]))
for i in people:
    print(i[0],i[1])
