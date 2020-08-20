
# def tree(N,M,tree_height):
#     for i in range(1,len(tree_height)):
#         tmp=0
#         for j in range(0,i):
#             tmp+=(tree_height[j]-tree_height[i])
#         if tmp>=M:
#             tree_sublst=tree_height[:i]
    
#             for height in range(tree_height[i-1],tree_height[i]-1,-1):
#                 tmp_cnt=0
#                 for tree in tree_sublst:
#                     tmp_cnt+=(tree - height)
#                 if tmp_cnt>=M:
#                     return height       

# N,M=map(int,input().split(' '))
# tree_height=list(map(int,list(input().split(' '))))
# tree_height.sort(reverse=True)
# print(tree(N,M,tree_height))


N,M=map(int,input().split(' '))
tree=list(map(int,input().split(' ')))
start,end=1,max(tree)
while start<=end:
    mid=(start+end)//2
    logged=0
    for t in tree:
        if t>mid:
            logged+= (t-mid)
    if logged>=M:
        start=mid+1
    else:
        end=mid-1
print(end)