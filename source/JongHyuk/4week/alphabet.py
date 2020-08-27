def bfs(c_x,c_y,x,y,board,R,C):
    queue=set()
    word=board[0][0]
    queue.add((0,0,word))
    _max=0
    while queue:
        tmp=queue.pop()
        tmp_x=tmp[0]
        tmp_y=tmp[1]
        word=tmp[2]
        _max=max(_max,len(word))
        if _max == 26 :
            return 26
        for i in range(4):
            c_x=tmp_x+x[i]
            c_y=tmp_y+y[i]
            if  -1<c_x and c_x<R and -1<c_y and c_y<C and (board[c_x][c_y] not in word) :
                queue.add((c_x,c_y,word+board[c_x][c_y]))
    return _max
R,C=map(int,input().split(' '))
board=[]
for i in range(R):
    board.append(input())

x=(0,1,0,-1)
y=(1,0,-1,0)
print(bfs(0,0,x,y,board,R,C))
    