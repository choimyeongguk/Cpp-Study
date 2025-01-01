#include <bits/stdc++.h>
using namespace std;

void solve() {
	int V, E, u, v, i;
	int node, stat;
	vector<char> visited;
	vector<vector<int>> graph;
	queue<int> q;
	
	cin >> V >> E;
	graph.resize(V + 1);
	for(i = 0; i < E; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	visited.assign(V + 1, 0);
	for(i = 1; i <= V; i++) {
		if(visited[i] != 0) continue;
		visited[i] = 1;
		q.push(i);
		while(!q.empty()) {
			node = q.front();
			stat = visited[node];
			for(auto& e : graph[node]) {
				if(!visited[e]) {
					visited[e] = -stat;
					q.push(e);
				}
				else if(visited[e] == stat) {
					cout << "NO\n";
					return;
				}
			}
			q.pop();
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int K;
	cin >> K;
	while(K--)
		solve();
	
	return 0;
}