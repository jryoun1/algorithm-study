#include<iostream>
#include<vector>

using namespace std;

int answer=0;
int root;
int N;
int delNode;
vector<vector<int>> arr(51);


void DFS(int num) {
	//leafnode 도달 시에 개수++
	if (arr[num].size() == 0){
		answer++;
		return;
	}

	for (int i = 0; i < arr[num].size(); i++){
		if (arr[num][i] == delNode)//자식 노드가 지운노드인 경우
		{
			if (arr[num].size() == 1)//자식의 개수가 1이라면
			{ //현재 노드가 leafnode가 되므로 개수++
				answer++;
			}
			continue;
		}
		//각 노드 별 간선으로 연결 된 노드로 DFS진행
		DFS(arr[num][i]);
	}
}

int main() {

	cin >> N;
	int root;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp != -1)
		{
			arr[tmp].push_back(i);
		}
		else
			root = i;
	}
	cin >> delNode;

	//지워야하는 노드가 root노드라면 정답은 0
	if (delNode == root)
		cout << "0";
	else {
		DFS(root);
		cout << answer;
	}
}