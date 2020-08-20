#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//입력 다받고 입력 받은거 arr 에 저장
//arr에 따라서 push와 pop갯수 정해줌
//pop결과랑 arr이랑 비교 했을 때 맞으면
//vector에 +. - push
//틀리면 NO

void solution(int n)
{
	stack<int> s;
	vector<int> vTmp;
	int a = 0;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a);
		arr[i] = a;
	}

	int max = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (i == 0)
		{
			for (int j = 1; j <= arr[i]; j++) {
				s.push(j);
				vTmp.push_back(1);
			}
			if (max <= arr[i]) max = arr[i];
			if (s.top() != arr[i])
			{
				vTmp.clear();
				vTmp.push_back(2);
				break;
			}
			else {
				s.pop(); 	vTmp.push_back(0);	
			}
		}
		else if (arr[i-1] < arr[i])
		{
			for (int j = max+1; j <= arr[i]; j++) {
				s.push(j);
				vTmp.push_back(1);
			}
			if (max <= arr[i]) max = arr[i];
			if (s.top() != arr[i])
			{
				vTmp.clear();
				vTmp.push_back(2);
				break;
			}
			else { s.pop();	vTmp.push_back(0); 		
			}
		}
		else {
			if (s.top() != arr[i])
			{
				vTmp.clear();
				vTmp.push_back(2);
				break;
			}
			else {
				s.pop(); 	vTmp.push_back(0);
			}
		}
	}
	if(vTmp.at(0) == 2)
	{
		printf("NO\n");
	}
	else
	{
		for (int i = 0; i < vTmp.size(); i++)
			if(vTmp.at(i)==1)printf("%c\n",'+');
			else printf("%c\n", '-');
	}

		
}

int main()
{
	stack<int> s;
	solution(8);
	return 0;
}

