def countingSort(arr, digit):
    n = len(arr)

    #arr that will contain sorted arr
    sorted = [0]*n
    #arr that count the number of how many elements are in digit
    count = [0]*10

    #counting how many elements are in each digit 
    for i in range(0,n):
        index = int(arr[i] / digit)
        count[index % 10] += 1
    
    #cumulative count element at count arr
    for i in range(1,10):
        count[i] += count[i-1]
    
    i = n -1
    while i >= 0:
        index = int(arr[i]/digit)
        sorted[count[index%10]-1] = arr[i]
        count[index%10] -= 1
        i -= 1

    for i in range(0,len(arr)):
        arr[i] = sorted[i]

def radixSort(arr):
    #find the max value at arr
    max_v = max(arr)
    #digit is value, dividing the max value with multiply 10 each cycle
    digit = 1
    # repeat until the max value's quotient is bigger than 0 
    while int(max_v/digit) > 0 :
        countingSort(arr,digit)
        digit *= 10

from random import randint
arr = [randint(1,101) for i in range(8)] # 1부터 101사이의 랜덤 값을 8개의 list 안에 초기화
print("정렬 전 : ", arr, end=" ") 
radixSort(arr)
print ("-> 정렬 후 : ",arr) 
