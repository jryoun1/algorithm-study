def quicksort(list):
    less_arr=[]
    eq_arr=[]
    bigger_arr=[]
    if len(list)<=1:
        return list
    pivot=list[len(list)//2]
    for num in list:
        if num<pivot:
            less_arr.append(num)
        elif num>pivot:
            bigger_arr.append(num)
        else:
            eq_arr.append(num)
    print(less_arr,bigger_arr,eq_arr)
    return quicksort(less_arr)+eq_arr+quicksort(bigger_arr)

print(quicksort([3,4,2,1,7,5,8,9]))


