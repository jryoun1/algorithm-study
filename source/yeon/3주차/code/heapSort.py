# heap정렬 파이썬 코드
def heapify(arr, index, size):
    largest = index
    left_index = index * 2 + 1
    right_index = index * 2 + 2

    if left_index < size and arr[largest] < arr[left_index]:
        largest = left_index
    if right_index < size and arr[largest] < arr[right_index] :
        largest = right_index

    if largest != index:
        arr[index], arr[largest] = arr[largest], arr[index]
        heapify(arr, largest, size)

def heapSort(arr): 
    size = len(arr) 
  
    # build max heap을 하는 과정 (전체 크기의 반부터 즉 O(n)이 나오는 연산으로 수행)
    for i in range(size//2 - 1, -1, -1): 
        heapify(arr, i, size) 
  
    # max heap이 구현된 arr에서 root node(최대값)을 말단 노드(최소값)과 바꾸고 heapify 수행
    # 이떄 heapify를 할 때 heap tree의 크기를 1씩 빼서 보내주는 것이 핵심이다. 
    for i in range(size - 1, 0, -1): 
        arr[i], arr[0] = arr[0], arr[i] 
        heapify(arr, 0, i) 

from random import randint
arr = [randint(1,101) for i in range(8)] # 1부터 101사이의 랜덤 값을 8개의 list 안에 초기화
print("정렬 전 : ", arr, end=" ") 
heapSort(arr)
n = len(arr) 
print ("-> 정렬 후 : ", end="") 
for i in range(n): 
    print ("%d" %arr[i], end = " ")