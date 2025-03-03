#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, A, B, num, i;
	int in_degree[32001] = { 0 };
	vector<vector<int>> graph;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	cin >> N >> M;
	graph.resize(N + 1);
	for(i = 0; i < M; i++) {
		cin >> A >> B;
		graph[A].emplace_back(B);
		in_degree[B]++;
	}
	
	for(i = 1; i <= N; i++) {
		if(!in_degree[i]) pq.push(i);
	}
	
	while(!pq.empty()) {
		num = pq.top();
		pq.pop();
		cout << num << " ";
		for(auto& e : graph[num]) {
			in_degree[e]--;
			if(!in_degree[e]) pq.push(e);
		}
	}
	
	return 0;
}