#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void insertionSort(vector<int> &arr){
    int temp =0, min =0, len = arr.size();
    for(int i = 1; i < len; i++){
        min = i;
        for(int j = i-1; j >= 0; j--){
            if(arr[min] < arr[j]){
                temp = arr[min];
                arr[min] = arr[j];
                arr[j] = temp;
                min = j;
            }
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
        insertionSort(temp); //sort(temp.begin(),temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}