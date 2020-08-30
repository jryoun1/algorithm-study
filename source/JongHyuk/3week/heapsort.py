def heapify(unsorted,index,heap_size):
    print('unsorted',unsorted)
    largest=index
    left_index=2*index+1
    right_index=2*index+2
    if left_index<heap_size and unsorted[left_index]>unsorted[largest]:
        largest=left_index
    if right_index<heap_size and unsorted[right_index]>unsorted[largest]:
        largest=right_index
    if index!=largest:
        unsorted[index],unsorted[largest]=unsorted[largest],unsorted[index]
        heapify(unsorted,largest,heap_size)

def heap_sort(unsorted):
    print('before max heap',unsorted)
    n=len(unsorted)
    for i in range(n//2-1,-1,-1):
        heapify(unsorted,i,n)
    print('*'*100)
    print('after max heap',unsorted)
    for i in range(n-1,0,-1):
        unsorted[0],unsorted[i]=unsorted[i],unsorted[0]
        heapify(unsorted,0,i)
    return unsorted
print(heap_sort([19,10,5,11,2,7,16,5,3,10,2,13,9,2,8,18,20,19,11,13]))