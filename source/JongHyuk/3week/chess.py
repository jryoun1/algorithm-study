N,M = map(int, input().split())
board = [list(input()) for _ in range(N)]
tmp=[]
num_lst=[]
pattern1 = [['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']]

pattern2 =[['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
 ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
 ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']]

def min_fixed(pattern1,pattern2,tmp_board):
    pattern1_cnt=0
    pattern2_cnt=0
    for i in range(8):
        for j in range(8):
            if pattern1[i][j] != tmp_board[i][j]:
                pattern1_cnt+=1
            if pattern2[i][j] != tmp_board[i][j]:
                pattern2_cnt+=1
    return min(pattern2_cnt,pattern1_cnt)



for i in range(N-7):
    for j in range(M-7):
        tmp.append(board[i][j:j+8])
        tmp.append(board[i+1][j:j+8])
        tmp.append(board[i+2][j:j+8])
        tmp.append(board[i+3][j:j+8])
        tmp.append(board[i+4][j:j+8])
        tmp.append(board[i+5][j:j+8])
        tmp.append(board[i+6][j:j+8])
        tmp.append(board[i+7][j:j+8])
        num_lst.append(min_fixed(pattern1,pattern2,tmp))
        tmp.clear()
        
print(min(num_lst))
        
        
        

