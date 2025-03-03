#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, A, B, cnt, num, min, i;
	int in_degree[32001] = { 0 };
	bool solved[32001] = { false };
	vector<vector<int>> graph;
	
	cin >> N >> M;;
	graph.resize(N + 1);
	for(i = 0; i < M; i++) {
		cin >> A >> B;
		graph[A].push_back(B);
		in_degree[B]++;
	}

	cnt = 0, num = 1;
	while(cnt < N) {
		if(solved[num]) {	// 이미 푼 문제 
			num++;
		}
		else if(!in_degree[num]) {	// 풀 수 있는 문제 
			cout << num << " ";
			solved[num] = true;
			min = num + 1;
			cnt++;
			for(auto& e : graph[num]) {
				in_degree[e]--;
				if(!in_degree[e]) {
					min = min < e ? min : e;
				}
			}
			num = min;
		}
		else num++;		// 풀 수 없는 문제 
	}
	
	return 0;
}