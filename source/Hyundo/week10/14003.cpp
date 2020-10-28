#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX = 1000001;

int N;
int seq[MAX], pos[MAX];

// 이분 탐색으로 LIS를 형성
int getLisLen()
{
	vector<int> lis;
	lis.push_back(seq[0]);
	for (int i = 1; i < N; ++i)
	{
		int cand = seq[i];
		//이전 seq[i-1]보다 현재 seq[i]가 더 크다면
		if (lis.back() < cand)
		{
			//더 클 경우에만 lis에 push_back이 되고 사이즈가 증가한다.
			lis.push_back(cand);
			//현재 수의 위치를 pos에 저장한다.
			pos[i] = lis.size() - 1;
		}
		//이전 seq[i-1]보다 현재 seq[i]가 더 작다면
		else
		{
			//lower_bound(value) = value 와 같거나 큰 값이 처음 나타나는 위치를 반복자로 반환
			vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), cand);
			//lower_bound를 통해 현재 seq[i]의 자리를 찾는다.
			*it = cand;
			// 찾은 위치를 pos에 저장한다.
			pos[i] = int(it - lis.begin());
		}
	}

	//최종적으로 index를 이동하면서 index도 크면서 seq[index]도 더 커진 경우에만 push_back을 진행하여
	//최종 size를 반환한다.
	return lis.size();
}

void printLis()
{
	int len = getLisLen();
	cout << len << endl;

	stack<int> st;
	int idx = len - 1;
	//pos 과의 비교를 통해 총길이로부터 하나씩 줄여가며 동일할 경우에만 출력하면
	//가장 긴 부분수열의 값들을 출력할 수 있다.
	//이는 idx가 더 크지만 seq[idx]의 값이 더 작은 경우에는 pos의 값이 줄어들어 조절되기 때문이다.
	for (int i = N - 1; i >= 0; --i)
		if (pos[i] == idx)
		{
			st.push(seq[i]);
			--idx;
		}

	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		scanf("%d", &seq[i]);

	printLis();

	return 0;
}