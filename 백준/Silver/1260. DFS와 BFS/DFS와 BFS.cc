#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
	cout << node << ' ';
	visited[node] = true;
	
	for(int i = 0; i < graph[node].size(); i++) {
		if(!visited[graph[node][i]]) {
			dfs(graph[node][i]);
		}
	}
}

void bfs(int node) {
	int curNode;
	queue<int> que;
	
	que.push(node);
	visited[node] = true;
	while(!que.empty()) {
		curNode = que.front();
		cout << curNode << ' ';
		que.pop();
		for(int i = 0; i < graph[curNode].size(); i++) {
			if(!visited[graph[curNode][i]]) {
				que.push(graph[curNode][i]);
				visited[graph[curNode][i]] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, V, a, b, i;
	cin >> N >> M >> V;
	graph.assign(N + 1, vector<int>());
	for(i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	visited.assign(N + 1, 0);
	dfs(V);
	cout << '\n';
	visited.assign(N + 1, 0);
	bfs(V);
	
	return 0;
}