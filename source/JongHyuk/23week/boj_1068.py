from sys import stdin
n=int(stdin.readline())
parents=list(map(int,stdin.readline().split()))
del_node=int(stdin.readline())
tree={}
for i in range(n):
    if i==del_node or parents[i]==del_node:
        continue
    if parents[i] in tree:
        tree[parents[i]].append(i)
    else:
        tree[parents[i]]=[i]

if -1 in tree:
    q=[-1]
else:
    q=[]
ans=0
while q:
    key=q.pop()
    if key in tree:
        q+=tree[key]
    else:
        ans+=1
print(ans)

