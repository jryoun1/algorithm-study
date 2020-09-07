// 백준 13904 과제
// cpp solved by Greedy algorithm + sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int N, d, w, sum = 0;
	vector<pair<int,int>> pv;
	vector<int> result;
	scanf("%d",&N);
	for (int i = 0 ; i < N; i++){
		scanf("%d %d", &d, &w);
		pv.push_back(make_pair(d,w));
	}
	// range shold be 1-1000
	for(int i = 1000; i > 0; i--){
		for(int j = 0; j< N; j++){
			if(pv[j].first == i){
				result.push_back(pv[j].second);
			}
		}
		sort(result.begin(),result.end());
		if(!result.empty()){
			int max = result.back();
			sum += max;
			result.pop_back();
		}
	}
	printf("%d", sum);
	return 0;
}