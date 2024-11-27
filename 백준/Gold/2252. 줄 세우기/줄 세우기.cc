#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, A, B, i;
	vector<int> in_degree;
	vector<vector<int>> graph;
	queue<int> q;
	
	cin >> N >> M;
	in_degree.assign(N + 1, 0);
	graph.resize(N + 1);
	for(i = 0; i < M; i++) {
		cin >> A >> B;
		in_degree[B]++;
		graph[A].push_back(B);
	}
	
	for(i = 1; i <= N; i++) {
		if(!in_degree[i]) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		cout << q.front() << " ";
		for(auto& e : graph[q.front()]) {
			in_degree[e]--;
			if(!in_degree[e]) {
				q.push(e);
			}
		}
		q.pop();
	}
	
	return 0;
}