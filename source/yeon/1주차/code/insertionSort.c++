#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void insertionSort(vector<int> &arr){
    int j , key = 0, len = arr.size();
    for(int i = 1; i < len; i++){
        key = arr[i];
        for(j = i-1; j >= 0; j--){
            if(key < arr[j]){
                arr[j+1] = arr[j];
            }
            else break;
        }
        arr[j+1] = key;
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