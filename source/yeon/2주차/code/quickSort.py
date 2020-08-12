#quickSort in-place 코드
import time
start = time.time()

def quickSort(lst):
    def sort(low, high): 
        if high <= low: #high와 low의 순서가 바뀌면 탈출 
            return

        mid = partition(low, high) 
        sort(low, mid-1)
        sort(mid, high)

    def partition(low, high): #분할 기준점의 인덱스(low)를 반환
        pivot = lst[(low + high) // 2]
        while low <= high:
            while lst[low] < pivot:
                low += 1
            while lst[high] > pivot:
                high -= 1
            if low <= high:
                lst[low], lst[high] = lst[high], lst[low]
                low, high = low + 1, high -1
        return low

    return sort(0,len(lst)-1)

from random import randint
lst = [randint(1,101) for i in range(8)] # 1부터 101사이의 랜덤 값을 8개의 list 안에 초기화
print("quickSort :", lst, end=" "); quickSort(lst); print ("->",lst)
print("time : ", time.time()-start )

# def quickSort(lst):
#     if len(lst) <= 1:
#         return lst
    
#     pivot = lst[len(lst)//2]
#     less_arr, equal_arr, greater_arr = [],[],[]

#     for num in lst:
#         if num < pivot:
#             less_arr.append(num)
#         elif num > pivot:
#             greater_arr.append(num)
#         else:
#             equal_arr.append(num)

#     return quickSort(less_arr)+equal_arr+quickSort(greater_arr)