#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define MAX 65

int N;
int image[MAX][MAX];
string str[MAX];
string answer;

bool compareString(vector<string> str) {
	bool check=true;
	for (int i = 1; i < str.size(); i++) {
		check = str[i - 1].compare(str[i]);
		if (check != 0)
			return false;
	}
	return true;
}

string solution(int h,int x,int y)
{ 
	if (h == 1)
		return to_string(image[x][y]);
	vector<string> req;
	req.push_back(solution(h / 2 ,x, y)); 
	req.push_back(solution(h / 2, x, y+(h / 2)));
	req.push_back(solution(h / 2, x+(h /2) , y));
	req.push_back(solution(h / 2, x+(h / 2), y+(h / 2)));
	
	//abcd가 다 같다면 한 개의 값만 뽑아서 그걸 print하는데 그 때는 ()를 쓰지않음
	//abcd의 값이 다 같은게 아니라면 가로를 쓰고 안에 내용들을 모두 프린트
	if (compareString(req)&&(req[0]).size()==1)
			return req[0];
	else
		return "("+ req[0] + req[1] + req[2] + req[3]+")";
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
			image[i][j] = s[j] - '0';
	}
	cout << solution(N, 0, 0);
	return 0;
}