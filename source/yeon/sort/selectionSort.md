## 선택 정렬 (Selection Sort)
### 개념 : 선택 정렬은 배열 내에서 가장 작은 것을 선택하여 맨 앞으로 보내는 정렬 방법이다. <br>
선택 정렬은 첫 번째 자료를 두 번째 자료부터 마지막 자료까지 차례대로 비교하여 가장 작은 값을 찾아 첫 번째에 놓고, <br>
두 번째 자료를 세 번째 자료부터 마지막 자료까지와 차례대로 비교하여 그 중 가장 작은 값을 찾아 두 번째 위치에 놓는 과정을 반복하며 정렬을 수행<br>
1회전을 수행 하고 나면 가장 작은 값의 자료가 맨 앞에 오게 되므로 그 다음 회전에서는 두 번째 자료를 가지고 비교한다. 마찬가지로 3회전에서는 세 번째 자료를 정렬한다.

## 프로그래머스 정렬 문제 - K 번째 수 
  - https://programmers.co.kr/learn/courses/30/lessons/42748

## 접근 방법
1. commands의 size만큼 반복하여 commands[i][0]부터 commands[i][1]까지 주어진 배열 자르기 <br>
2. 구현한 선택 정렬 함수를 사용하여 정렬 (c++, python 기본 제공 sort라이브러리 사용 x) <br>
3. 정렬된 배열에서 commands[i][2]의 값을 index로 가지는 원소를 꺼내서 answer에 추가 

## python code
```python
#프로그래머스 k번째 수 
#선택 정렬 함수
def selection_sort(object):
    min, temp = 0, 0
    for i in range(0,len(object)-1):
        min = i
        for j in range(i+1,len(object)):
            if object[j] < object[min] :
                min = j
        if i != min :
            temp = object[i]
            object[i] = object[min]
            object[min] = temp

def solution(array, commands):
    answer = []
    for i in commands :
        temp = array[i[0]-1:i[1]]
        selection_sort(temp) #temp.sort()사용해서 풀이가능 
        answer.append(temp.pop(i[2]-1))
    return answer
``` 
### 수행 속도
![img load fail](./images/selectionSortpython.PNG)

## c++ code
```c++
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void selectionSort(vector<int> &arr){
    int min =0, temp =0;
    for(int i = 0; i < arr.size()-1; i++){
        min = i;
        for(int j = i+1; j< arr.size(); j++){
            if(arr[j] < arr[min]){
                min =j;
            }
        }
        if( i != min){
            temp = arr[i];
            arr[i]= arr[min];
            arr[min] = temp;
        }
    }
} 

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(int i =0; i< commands.size();i++){
        temp={};
        for(int j = commands[i][0] - 1; j<commands[i][1];j++){
            temp.push_back(array[j]);
        }
        selectionSort(temp); //sort(temp.begin(),temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}
```
### 수행속도
![img load fail](./images/selectionSortc++.PNG)

## 시간복잡도
1 2 3 4 5 6 7 8 9 10의 원소를 가지는 배열이 있다고 하면 1은 10번 비교를 해야하며, 2는 9번, 3은 8번,... 9는 2번, 10은 1번의 비교를 하게된다. <br>
즉, 10 + 9 + 8 + 7 + ... + 2 + 1 이므로 N x (N + 1) / 2 가 선택 정렬(selection sort)의 시간복잡도가 된다.<br>
따라서 선택정렬의 시간 복잡도는 O(N^2)이다.

## 공간복잡도
