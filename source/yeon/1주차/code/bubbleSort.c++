#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void bubbleSort(vector<int> &arr){
    int temp =0;
    for(int i = arr.size() - 1; i > 0; i--){
        for(int j = 0; j< i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
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
        bubbleSort(temp); //sort(temp.begin(),temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}