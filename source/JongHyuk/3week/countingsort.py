import random

def counting_sort(arr, size, m):
    count = [0 for _ in range(m)]
    tmp = [0 for _ in range(size)]

    for x in arr:
        count[x] += 1

    for x in range(1, m):
        count[x] += count[x - 1]

    for x in range(size - 1, -1, -1):
        count[arr[x]] -= 1
        tmp[count[arr[x]]] = arr[x]

    return tmp

m = 5
size = 20
arr = [random.randrange(m) for _ in range(size)]
print('정렬전 :', arr)
print('정렬후 :', counting_sort(arr, size, m))