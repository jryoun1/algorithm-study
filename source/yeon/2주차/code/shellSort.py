def insertionSort(list, first, last, gap):
    index = first + gap 
    #첫번째 while문은 생성한 배열에서의 gap만큼 인덱스를 last까지 증가시켜주는 역할
    while index <= last: 
        val = list[index]
        pos = index
        # 두 번째 while문은 첫 번째 while문에 의해서 설정된 index 값부터 gap만큼 
        # 빼가면서 앞에 원소중에서 크기가 작으면 교환, 즉 sort하는 역할 
        while pos > first and list[pos - gap] > val:
            list[pos] = list[pos-gap]
            pos -= gap
        list[pos] = val
        index += gap

def shellSort(list):
    length = len(list)
    gap = length//2 # 정렬한 원소의 크기의 반을 gap으로 지정
    while gap > 0: 
        # shellsort 개념에서 gap 개수만큼 배열을 만드는 부분인데
        # 실제로는 배열을 만드는 것이 아니라 리스트를 한번씩 정렬하는 방식 
        for i in range(0, gap): 
            insertionSort(list, i, length-1, gap)
        gap //= 2
    return list

from random import randint

lst = [randint(1,101) for i in range(8)] # 1부터 101사이의 랜덤 값을 8개의 list 안에 초기화
print("shellSort :", lst, end=" "); print ("->",shellSort(lst))