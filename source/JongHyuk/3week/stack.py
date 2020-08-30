



from collections import deque
n=int(input())
lst=deque([i for i in range(1,n+1)])
ans=[]
stack=[]
cnt=0
flag=True
for i in range(0,n):
    num=int(input())
    while cnt<num:
        cnt+=1
        ans.append('+')
        stack.append(cnt)

    if stack[-1] == num:
        ans.append('-')
        stack.pop()
    else:
        flag=False
        break

if flag==False:
    print('NO')
else:
    print('\n'.join(ans))
