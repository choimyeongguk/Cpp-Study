#include <bits/stdc++.h>
using namespace std;

vector<vector<short>> graph;
vector<bool> isGrouped;

void dfs(int node) {
	isGrouped[node] = true;
	for(int i = 0; i < graph[node].size(); i++) {
		if(!isGrouped[graph[node][i]]) {
			dfs(graph[node][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, u, v, cnt = 0, i;
	
	cin >> N >> M;
	graph.assign(N + 1, vector<short>());
	isGrouped.assign(N + 1, false);
	for(i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(i = 1; i <= N; i++) {
		if(!isGrouped[i]) {
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}