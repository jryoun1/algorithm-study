#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)

#define MAX 100000

using namespace std;

int T = 0;
string p;
int N;
string sArr;
char str[MAX];
vector<int> vArr;
bool check = false;

//배열 전체 reverse
void R() {
	reverse(vArr.begin(), vArr.end());
}

//배열 첫번째 숫자 pop
void D() {
	vArr.erase(vArr.begin());
}

//들어온 값에 대한 R과 D처리 후 저장하는 부분
void sol() {
	//1. 현재 들어와있는 string 형태로 되어있는 arr을 벡터에 push함
	strcpy(str, sArr.c_str());
	char* ptr = strtok(str, "[,]");

	while (ptr) {
		vArr.push_back(stoi(ptr));
		ptr = strtok(NULL, "[,]");
	}

	//2. 들어온 p값에 대하여 R과 D함수 진행
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == 'R')
			R();
		else if (p[i] == 'D') {
			if (vArr.empty()) {
				check = true;
				break;
			}
			else
				D();
		}
	}

	//3. 실행 결과 출력
	if (check == true)
		cout << "error"<<endl;
	else {
		cout << "[";
		for (int i = 0; i < vArr.size() - 1; i++) {
			cout << vArr[i];
			cout << ",";
		}
		cout << vArr[vArr.size() - 1] << "]"<<endl;
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vArr.clear();
		check = false;
		cin >> p;
		cin >> N;
		cin >> sArr;
		sol();
	}

	return 0;
}