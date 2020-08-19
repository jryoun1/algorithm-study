def heapify(arr, size ,node_index):
    largest = node_index
    L_index = node_index * 2 + 1
    R_index = node_index * 2 + 2

    if L_index < size and arr[node_index] < arr[L_index]:
        largest = L_index
    if R_index < size and arr[largest] < arr[R_index] :
        largest = R_index
    
    if largest != node_index:
        arr[node_index], arr[largest] = arr[largest], arr[node_index]
        heapify(arr, size, largest)
        # The main function to sort an array of given size 

def heapSort(arr): 
    n = len(arr) 
  
    # Build a maxheap. 
    for i in range(n//2 - 1, -1, -1): 
        heapify(arr, n, i) 
  
    # One by one extract elements 
    for i in range(n-1, 0, -1): 
        arr[i], arr[0] = arr[0], arr[i] # swap 
        heapify(arr, i, 0) 
  
# Driver code to test above 
arr = [ 12, 11, 13, 5, 6, 7] 
heapSort(arr) 
n = len(arr) 
print ("Sorted array is") 
for i in range(n): 
    print ("%d" %arr[i], end = " ")