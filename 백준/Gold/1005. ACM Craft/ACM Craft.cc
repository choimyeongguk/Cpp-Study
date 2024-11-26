#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K, X, Y, W, i, idx;
	int D[1001], dist[1001] = { 0 };
	int order[1001], degree[1001] = { 0 };
	vector<vector<int>> graph;
	queue<int> q;
	
	// 입력 
	cin >> N >> K;
	for(i = 1; i <= N; i++) {
		cin >> D[i];
	}
	graph.resize(N + 1);
	for(i = 0; i < K; i++) {
		cin >> X >> Y;
		graph[X].push_back(Y);
		degree[Y]++;
	}
	cin >> W;
	
	// 그래프 위상 정렬 
	for(i = 1; i <= N; i++) {
		if(!degree[i]) {
			q.push(i);
		}
	}
	for(i = 1; i <= N; i++) {
		order[i] = q.front();
		for(auto& e : graph[q.front()]) {
			degree[e]--;
			if(!degree[e]) {
				q.push(e);
			}
		}
		q.pop();
	}
	
	// DAG
	for(i = 1; i <= N; i++) {
		idx = order[i];
		dist[idx] += D[idx];
		for(auto& e : graph[idx]) {
			dist[e] = max(dist[e], dist[idx]);
		}
	}
	cout << dist[W] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--)
		solve();
	
	return 0;
}