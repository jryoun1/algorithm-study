def merge_sort(unsorted_list):
    if len(unsorted_list)==1:
        return unsorted_list
    mid=len(unsorted_list)//2
    left=unsorted_list[:mid]
    right=unsorted_list[mid:]
    print(left,right)
    left1=merge_sort(left)
    right1=merge_sort(right)
    return merge(left1,right1)
def merge(left,right):
    ans=[]
    l_i=0
    r_i=0
    while l_i<len(left) and r_i<len(right):
        if left[l_i]<right[r_i]:
            ans.append(left[l_i])
            l_i+=1
        else:
            ans.append(right[r_i])
            r_i+=1
    if l_i<len(left):
        while l_i<len(left):
            ans.append(left[l_i])
            l_i+=1
    else:
        while r_i<len(right):
            ans.append(right[r_i])
            r_i+=1
    return ans



print(merge_sort([5,3,8,1,7,9]))