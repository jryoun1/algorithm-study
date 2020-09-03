N=int(input())
board=[]
for _ in range(N):
    board.append(list(input()))
    
candy=[]
res=[]
tmp=''
ans=0
flag=-1
#인접한 오른쪽블럭,아래블럭을 조건이 맞으면 
#전제 board를 순회하면서 바꿔주고 바뀐 상태에서 연속된 문자열 최대값을 저장해나간다.
for i in range(N):
    for j in range(N):
        #인접한 밑블럭이 조건에 맞으면
        if i+1<N:
            candy=[]
            board[i][j],board[i+1][j]=board[i+1][j],board[i][j]
            #전체 블럭을 순회하면서 최대 문자열 길이를 뽑아낸다.(행 기준)
            for k in range(N):
                tmp=board[k][0]
                for l in range(N):
                    if tmp==board[k][l]:
                        ans+=1
                    else:
                        tmp=board[k][l]
                        candy.append(ans)
                        ans=1
                candy.append(ans)
                ans=0
            res.append(max(candy))
            candy=[]

            #최대 문자열 길이를 마찬가지로 뽑아낸다(열 기준)
            for k in range(N):
                tmp=board[0][k]
                for l in range(N):
                    if tmp==board[l][k]:
                        ans+=1
                    else:
                        tmp=board[l][k]
                        candy.append(ans)
                        ans=1
                candy.append(ans)
                ans=0
            res.append(max(candy))
            board[i][j],board[i+1][j]=board[i+1][j],board[i][j]

        #인접한 오른쪽블록이 조건에맞으면
        if j+1<N:
            ans=0
            candy=[]
            board[i][j],board[i][j+1]=board[i][j+1],board[i][j]
            #순회하며 최대 문자열 길이 뽑는다.(행기준)
            for k in range(N):
                tmp=board[k][0]
                for l in range(N):
                    if tmp==board[k][l]:
                        ans+=1
                    else:
                        tmp=board[k][l]
                        candy.append(ans)
                        ans=1
                candy.append(ans)
                ans=0
            res.append(max(candy))
            candy=[]
            ans=0
            #순회하며 최대 문자열 길이를 뽑는다.(열기준)
            for k in range(N):
                tmp=board[0][k]
                for l in range(N):
                    if tmp==board[l][k]:
                        ans+=1
                    else:
                        tmp=board[l][k]
                        candy.append(ans)
                        ans=1
                candy.append(ans)
                ans=0
            res.append(max(candy))
            board[i][j],board[i][j+1]=board[i][j+1],board[i][j]
            candy=[]
            ans=0
print(max(res))

            



