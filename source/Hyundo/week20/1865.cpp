#include<iostream>
#include<vector>
#define INF 999999

using namespace std;

void solution(int N, int M, int W) {
	//N개의 간선     목적지/가중치
	vector<vector<pair<int, int>>> edge(N + 1);
	//각 지점의 초기값을 무한의 값으로 설정
	vector<int> dis(N + 1, INF);
	dis.at(1) = 0; //첫번째 위치를 0으로 설정

	//각 도로 정보 저장
	for (int i = 0; i < M; i++) {
		int S, E, T;
		cin >> S >> E >> T;
		//도로는 방향이 없으므로 양방향으로 저장
		edge.at(S).push_back({E,T});
		edge.at(E).push_back({S,T});
	}
	//각 웜홀 정보 저장
	for (int i = 0; i < W; i++) {
		int S, E, T;
		cin >> S >> E >> T;
		//웜홀은 방향이 있으므로 단방향 저장
		//웜홀은 시간이 뒤로 가므로 -로 저장
		edge.at(S).push_back({ E,-T });
	}

	bool answer = false;
	//N번을 수행하더라도 dis[1]가 음수가 되지 않을 수 있음
	//N번째 수행에서 갱신이 된 경우를 체크
	//이완작업반복
	for (int i = 1; i <= N; i++) {	//정점의 개수만큼 간선 relax작업 실행
		for (int j = 1; j <= N; j++) {	//각 정점에 해당하는 간선들에 대한 작업
			//지점 별 연결 간선과 웜홀에 대해 계산
			for (int k = 0; k < edge.at(j).size(); k++) {
				int from = j; //시작위치
				int to = edge.at(j).at(k).first; //도착위치
				int weight = edge.at(j).at(k).second; //간선or웜홀 의 가중치
				//현재 위치의가중치와 간선가중치를 더한 값과 도착위치 가중치를 비교
				if (dis.at(from) + weight < dis.at(to)) {
					dis.at(to) = dis.at(from) + weight;
					//음의 가중치를 갖는 순환경로 존재 확인
					//N번째 수행에서 갱신이 된 경우 음의 사이클
					if (i == N) answer = true;
				}
			}
		}
	}
	if (answer == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	int TC;
	int N;
	int M;
	int W;

	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		cin >> N >> M >> W;
		solution(N, M, W);
	}
}