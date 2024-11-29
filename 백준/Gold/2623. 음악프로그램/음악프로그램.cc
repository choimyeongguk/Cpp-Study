#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, num, prev, cur, i, j;
	vector<vector<int>> graph;
	vector<int> in_degree;
	vector<int> order;
	queue<int> q;
	
	cin >> N >> M;
	graph.resize(N + 1);
	in_degree.assign(N + 1, 0);
	for(i = 0; i < M; i++) {
		cin >> num >> prev;
		for(j = 1; j < num; j++) {
			cin >> cur;
			graph[prev].push_back(cur);
			in_degree[cur]++;
			prev = cur;
		}
	}
	for(i = 1; i <= N; i++) {
		if(!in_degree[i]) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		order.push_back(q.front());
		for(auto& e : graph[q.front()]) {
			in_degree[e]--;
			if(!in_degree[e]) {
				q.push(e);
			}
		}
		q.pop();
	}
	if(order.size() == N) {
		for(auto& e : order) {
			cout << e << "\n";
		}
	}
	else
		cout << 0;
	
	return 0;
}