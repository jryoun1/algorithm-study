from sys import stdin
N=int(stdin.readline())
ans=0
score=[]
for _ in range(N):
    score.append(int(stdin.readline()))

for i in range(N-1,0,-1):
    if score[i]<=score[i-1]:
        move=0
        move=score[i-1]-score[i]+1
        ans+=move
        score[i-1]=score[i-1]-move
print(ans)

