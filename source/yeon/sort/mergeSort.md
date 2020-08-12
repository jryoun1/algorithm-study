# mergeSort(합병 정렬)
## 목차
- [합병 정렬 개념](#개념)
- [합병 정렬 동작 방식](#동작-방식)
- [합병 정렬 특징](#특징)
- [합병 정렬 시간복잡도와 공간복잡도](#시간복잡도)
- [합병 정렬 python code](#python-code)
- [합병 정렬 c++ code](#c-code)
- [참조](#참조)

#### <a id="information"></a>
### 개념 
입력 자료를 부분집합으로 분할(divide)하고, 각 부분집합에 대해서 정렬 작업을 정복(conquer)한 다음에 정렬된 부분집합들을 모아서 다시 결합(combine)하는 <br>
**분할 정복(divide and conquer)기법** 중 하나로, 여러 개의 정렬된 자료의 집합을 병합하여 한개의 정렬된 집합으로 만드는 방식의 정렬 알고리즘이다. <br>

#### <a id="How it works"></a>
### 동작 방식
0. 정렬한 상태의 자료를 담기 위해 입력 자료의 크기만큼의 새로운 배열(리스트)를 선언
1. 입력 자료를 두 개의 부분집합으로 분할하고, 각 부분집합을 계속해서 2개로 분할하여 모든 부분집합의 원소가 1개일 때까지 분할
2. 원소가 1개인 2개의 부분집합 원소의 크기를 비교하여 오름차순으로 정렬 상태를 담기위한 배열(리스트)로 병합
3. 원소가 2개 이상인 부분집합들을 병합할 때는 다음과 같은 흐름에 따라서 정렬을 진행
- 병합 대상인 두 부분집합 leftList와 rightList의 0 번째 원소 크기 비교
- 더 작은 원소를 새로운 리스트에 삽입 (leftList[0] > rightList[0]라고 가정)
- rightList에서는 이미 0번째 원소가 삽입이 되었기 때문에 leftList[0]과 rightList[1]의 크기 비교
- 위와 같의 과정을 반복하여 둘 중에 한쪽 List가 다 삽입이 되는 경우에는 위의 과정을 중단 (rightList가 먼저 다 삽입 되었다고 가정)
- 아직 삽입이 끝나지 않은 leftList의 남은 원소들을 새로운 리스트에 순차적으로 삽입
4. 부분집합의 원소 개수가 2개, 4개, ...,n개(처음 원소의 개수)가 될 때까지 반복

![img load fail](../images/mergeSortexample.png) <br>
위의 사진은 8개의 원소가 들어가있는 배열의 동작되는 과정을 프린트 해본 것이다.

#### <a id="characteristic"></a>
## 특징
- 연결 리스트(Linked List)로 구현 시 **In-place(제자리 정렬)** 알고리즘이다. <br>
(링크 인덱스만 변경되므로 데이터의 이동은 무시할 수 있을 정도로 작아짐)<br>
- 배열(Array)로 구현 시 **Not-In-place(비제자리 정렬)** 알고리즘이다. (임시 배열이 필요) <br>
- **stable(안정적)** 알고리즘이다.<br>
- 가장 빠르다고 알려진 퀵 정렬(quickSort)과 평균 시간 복잡도가 동일 <br>
(세심하게 따져보면 평균적인 상황에서는 quickSort가 더 빠른편이고, mergeSort는 n만큼의 추가공간이 필요하다는 단점도 존재) <br>
그러나 파이썬에 내장되어 있는 정렬(sort, sorted)메소드의 경우에는 최악의 경우 시간복잡도가 O(N^2)인 quickSort가 아닌 합병 정렬과 삽입 정렬을 혼합한 Tim Sort(팀 정렬)사용

#### <a id="time complexity"></a>
## 시간복잡도
![img load fail](../images/mergeSortworks.png)
### 연산시간
1. **분할 단계** : n 개의 원소를 분할하기 위해서 **log2 n번**의 단계를 수행 <br>
e.g. 위의 사진을 보면, 8개의 원소를 가진 리스트를 3회(log2 (8))에 걸쳐 1개의 원소를 가진 부분집합으로 분할<br>

2. **병합 단계** : 부분집합의 원소를 비교하면서 병합하는 단계에서 최대 **n번**의 비교연산 수행<br>
e.g. 위의 사진에서 총 15번 비교연산 수행 (병합 1단계 : 4회, 병합 2단계 : 5회, 병합 3단계 : 6단계)

### 시간 복잡도
시간 복잡도의 최선, 평균, 최악 모두 **O(Nlog N)** 으로 동일하다.<br>

## 공간복잡도
원소 **n개**에 대해서 **2n개**의 메모리 공간을 사용 **(각 단계에서 병합하여 만든 부분집합을 저장할 공간이 필요)** 

#### <a id="python code"></a>
## python code
```python
#합병정렬 파이썬 코드
#분할하는 함수
def mergeSort(list):
    if len(list) <=1:
        return list
    mid = int(len(list)/2)

    #왼쪽부분 
    leftList = list[:mid]
    #오른쪽부분
    rightList = list[mid:]

    #재귀 -> 가장 왼쪽부터 분리될때까지 반복
    leftList = mergeSort(leftList)
    rightList = mergeSort(rightList)
    
    #합병
    return merge(leftList,rightList)
   
#정복 (합병) 하는 함수
def merge(leftList, rightList):
    sorted_arr = [] #합병한 정렬을 저장하는 배열
    while len(leftList) > 0 or len(rightList) > 0 :
        #왼쪽 리스트와 오른쪽 리스트 안에 둘다 원소가 있는 경우
        if len(leftList) > 0 and len(rightList) > 0 : 
            if leftList[0] <= rightList[0] :
                sorted_arr.append(leftList[0])
                leftList = leftList[1:]
            else:
                sorted_arr.append(rightList[0])
                rightList = rightList[1:]
        #왼쪽 리스트에만 원소가 남은 경우
        elif len(leftList) > 0 :
            sorted_arr.append(leftList[0])
            leftList = leftList[1:]
        #오른쪽 리스트에만 원소가 남은 경우
        elif len(rightList) > 0:
            sorted_arr.append(rightList[0])
            rightList = rightList[1:]
    return sorted_arr

from random import randint
lst = [randint(1,101) for i in range(8)] # 1부터 101사이의 랜덤 값을 8개의 list 안에 초기화
print("mergeSort :", lst, end=" "); print ("->",mergeSort(lst))

# if __name__ == "__main__":
#     arr = list(map(int,input().split()))
#     print(mergeSort(arr))
``` 

#### <a id="c++ code"></a>
## c++ code
```c++
#include<iostream>
#include<string>
int cnt =0;

void merge(int arr[], int left, int mid, int right){
    int i = left, j = mid + 1, k = left ;
    int sorted_arr[1000];
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            sorted_arr[k++] = arr[i++];
        }else{
            sorted_arr[k++] = arr[j++];
        }
    }
    if(i>mid){
        for(int m = j; m <= right; m++){
            sorted_arr[k++] = arr[m];
        }
    }else{
         for(int m = i; m<= mid; m++){
            sorted_arr[k++] = arr[m];
        }
    }
      for (int m = left; m <= right; m++) {
        arr[m] = sorted_arr[m];
    }
}
void mergeSort(int arr[], int left, int right){
    int mid =0;
    
    if(left < right){
        cnt++;
        mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid +1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int len = 0;
    std::cin >> len;
    int *arr = new int[len];
    for(int i = 0; i< len ; i++){
        std::cin >> arr[i];
    }
    mergeSort(arr, 0, len - 1);
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
```
#### <a id="references"></a>
### 참조
아래의 링크를 참조하여 작성하였습니다. <br>
[heejeong Kwon](https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html)
[몽구의 우탕탕탕 개발 공부](https://mong9data.tistory.com/46?category=885884)
