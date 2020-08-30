# 계수 정렬
MAX_NUM = 20
def countingSort(arr):
    length = len(arr)
    # 배열 안의 원소의 개수를 세는 배열
    count_arr =[0] * (MAX_NUM+1)
    # 배열의 원소들의 개수를 더해가면서 저장하는 배열 
    count_sum = [0] *(MAX_NUM+1)
    
    for i in range(length):
        count_arr[arr[i]] +=1
    
    count_sum[0] = count_arr[0]
    for i in range(1,MAX_NUM+1):
        count_sum[i] = count_sum[i-1] + count_arr[i]

    #sorted_arr는 정렬된 결과를 저장하는 배열 
    sorted_arr = [0]*(length+1) 
    for i in range(length-1, -1, -1): 
        sorted_arr[count_sum[arr[i]]] = arr[i] 
        count_sum[arr[i]] -= 1

    sorted_arr = sorted_arr[1:]
    return sorted_arr

from random import randint
lst = [randint(1,MAX_NUM) for i in range(8)] # 1부터 101사이의 랜덤 값을 8개의 list 안에 초기화
print("정렬 전 -> ",lst, end= " "); print("정렬 후 -> ",countingSort(lst))