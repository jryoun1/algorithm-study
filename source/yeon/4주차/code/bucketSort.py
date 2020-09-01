def insertionSort(bucket):
    for i in range(1,len(bucket)):
        min = bucket[i]
        j = i - 1
        while j >= 0 and bucket[j] > min :
            bucket[j+1] = bucket[j]
            j -= 1
        bucket[j+1] = min
    return bucket

def bucketSort(arr):
  	#10 means 10 slots, slot's size if 0.1
    bucket = [[] for _ in range(10)]
	
  	#put elements in each buckets
    for i in arr :
        index = int(i * 10)
        bucket[index].append(i)
        
		#sort individual buckets
    for i in range(10):
        bucket[i] = insertionSort(bucket[i])
    
    #concatenate the bucket
    x = 0
    for i in range(10):
        for j in range(len(bucket[i])):
            arr[x] = bucket[i][j]
            x += 1
    
    
arr = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.12, 0.24] 
print("정렬 전 : ", arr, end=" ") 
bucketSort(arr)
print ("-> 정렬 후 : ",arr) 