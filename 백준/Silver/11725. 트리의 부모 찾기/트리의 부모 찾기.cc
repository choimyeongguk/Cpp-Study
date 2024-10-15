#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, n1, n2, i;
	vector<vector<int>> graph;
	vector<int> tree;
	vector<bool> visited;
	queue<int> bfs;
	
	cin >> N;
	graph.assign(N + 1, vector<int>());
	tree.assign(N + 1, 0);
	visited.assign(N + 1, false);
	for(i = 1; i < N; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	
	bfs.push(1);
	visited[1] = true;
	while(!bfs.empty()) {
		int& n = bfs.front();
		for(i = 0; i < graph[n].size(); i++) {
			if(!visited[graph[n][i]]) {
				bfs.push(graph[n][i]);
				visited[graph[n][i]] = true;
				tree[graph[n][i]] = n;
			}
		}
		bfs.pop();
	}
	
	for(i = 2; i <= N; i++) {
		cout << tree[i] << "\n";
	}
	
	return 0;
}