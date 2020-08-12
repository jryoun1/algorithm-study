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