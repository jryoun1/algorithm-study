#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void ShellSort(vector<int> &array)
{
	int h, i, j, value;
	int n = array.size();
	h = 1;
	//부분배열 개수 결정
	do h = 3 * h + 1; while (h < n);
	do {
		h /= 3;
		//삽입정렬
		for (i = h; i < n; i++)
		{
			value = array[i];
			j = i;
			while (array[j - h] > value) {
				array[j] = array[j - h];
				j -= h;
				if (j <= h - 1) break;
			}
			array[j] = value;
		}
	} while (h > 1);
}


int main()
{
	vector<int> array = { 30,50,15,60,35,10,40,45,5,25,55,20 };

	//정렬 결과 출력
	ShellSort(array);
	for (int j = 0; j < 12; j++)
	{
		cout << array[j] << endl;
	}
	return 0;
}

