#include "SelectionSort.h"
#include "BubleSort.h"
#include "InsertionSort.h"

#include "common.h"

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> arrayTemp(array);
	for (int i = 0; i < commands.size(); i++)
	{
		vector<int> arraySortTemp;
		//arrayTemp = array; 

		for (int a = commands[i][0] - 1; a < commands[i][1]; a++)
		{
			arraySortTemp.push_back(array.at(a));
		}

		//arraySortTemp=selectionSort(arraySortTemp);
		//arraySortTemp = BubleSort(arraySortTemp);
		arraySortTemp = InsertionSort(arraySortTemp);

		for (int i = 0; i < arraySortTemp.size(); i++)
		{
			cout << arraySortTemp.at(i) << " ";
		}
		cout << endl;

		//sort(arrayTemp.begin()+commands[i][0]-1, arrayTemp.begin() + commands[i][1]);
		//answer.push_back(arrayTemp.at(commands[i][0] + commands[i][2]-2));

		answer.push_back(arraySortTemp.at(commands[i][2] - 1));                                                                                    
	}
	return answer;
}

int main()
{
	vector <int> array = {1, 5, 2, 6, 3, 7, 4};
	vector <vector<int>> commands= { {2, 5, 3}, { 4, 4, 1 }, { 1, 7, 3 }};
	vector <int> answer;
	answer = solution(array, commands);
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}
	return 0;
}

