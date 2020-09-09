# 백준 4796 캠핑
# python sovled by Greedy algorithm
arr = []
L,P,V = 1,1,1

# get input from user
while True:
    L,P,V = map(int,input().split())
    arr.append([L,P,V])
    if L == 0 and P == 0 and V == 0 : break

for i in range(len(arr)-1):
    # V % P < L
    if arr[i][2] % arr[i][1] < arr[i][0] : 
        print("Case {}: {}".format(i+1, int(arr[i][2]/arr[i][1])*arr[i][0] + arr[i][2] % arr[i][1]))
    # V % P > L 
    else :
        print("Case {}: {}".format(i+1, int(arr[i][2]/arr[i][1])*arr[i][0] + arr[i][0]))
