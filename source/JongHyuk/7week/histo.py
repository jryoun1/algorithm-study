
#세그먼트 트리 만들기
def init(arr,tree,node,start,end):
    if start==end:
        tree[node]=[arr[start],start]
        return tree[node]
    mid = (start+end)//2
    tree[node]=min(init(arr,tree,node*2,start,mid),init(arr,tree,node*2+1,mid+1,end))
    return tree[node]


#세그먼트 트리에서 해당 인덱스 범위에 해당하는 최저값 가지고오기
def query(arr,tree,node,start,end,i,j):
    if i>end or j<start: # 주어진 범위가 전체 범위에 완전히 속하지 않는다면
        return -1 
    if i<=start and end<=j: # 주어진 범위가 전체 범위를 완전히 포함한다면
        return tree[node] # 해당 범위의 최소값 index를 return 함

    # 주어진 범위가 전체 범위에 속해있다면
    # ex_) 0~4 index의 값이 주어졌을 때, 1~3 index에 대한 최소값을 구하고 싶음
    m1 = query(arr,tree,2*node,start,(start+end)//2,i,j) # 전체 범위를 반으로 자른 범위를 넘기고 왼쪽 노드 값을 넘김
    m2 = query(arr,tree,2*node+1,(start+end)//2+1,end,i,j) # 전체 범위를 반으로 자른 범위를 넘기고 오른쪽 노드 값을 넘김
    if m1==-1:
        return m2
    elif m2==-1:
        return m1
    else:
        if m1[0]<m2[0]:
            return m1
        else:
            return m2


def solve(left,right):
    min_value=query(arr,tree,1,0,len(arr)-1,left,right)[0]
    min_index=query(arr,tree,1,0,len(arr)-1,left,right)[1]
    global max_width
    #전체 범위에서 최저값 찾아서 기준으로삼고 돌리기

    max_width=max(max_width,((right-left)+1)*min_value)
    if left<min_index-1:
        solve(left,min_index-1)

    if right>min_index:
        solve(min_index+1,right)
    return max_width
    



        




max_width=0
n=int(input())
arr=[]
for _ in range(n):
    arr.append(int(input()))

tree=[0]*4*len(arr)
init(arr,tree,1,0,len(arr)-1)
print(solve(0,len(arr)-1))
