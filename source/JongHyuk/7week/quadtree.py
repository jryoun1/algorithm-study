import sys

def zip(N,x,y):

    if N==2:
        count_zero=0
        count_one=0
        tmp_x=-1
        tmp_y=-1
        tmp=[]
        for i in range(4):
            tmp_x=x+dx[i]
            tmp_y=y+dy[i]
            if board[tmp_x][tmp_y]=='0':
                count_zero+=1
                tmp.append('0')
            else:
                tmp.append('1')
                count_one+=1
        if count_one == 0 :
            tmp2.append('0')
        elif count_zero ==0:

            tmp2.append('1')
        else:
            tmp2.append('(')
            tmp2.extend(tmp)
            tmp2.append(')')
        print(tmp2)
        return
    zip(N//2,x,y)
    zip(N//2,x,y+N//2)
    zip(N//2,x+N//2,y)
    zip(N//2,x+N//2,y+N//2)
    if tmp2:
        if '(' in tmp2:
            res.append('(')
            res.extend(tmp2)
            res.append(')')
        elif tmp2.count('1')==4:
            res.append('1')
        elif tmp2.count('0')==4:
            res.append('0')
        else:
            res.append('(')
            res.extend(tmp2)
            res.append(')')
        del tmp2[:]
    return





tmp2=[]
res=['(']
N=int(input())
board=[]
dx=[0,0,1,1]
dy=[0,1,0,1]
for _ in range(N):
    board.append(list(input()))
zip(N,0,0)
res.append(')')
print(''.join(res))