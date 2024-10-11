#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> graph;
vector<bool> infected;

int dfs(int node) {
	infected[node] = true;
	int result = 1;
	for(int i = 0; i < graph[node].size(); i++) {
		if(!infected[graph[node][i]]) {
			result += dfs(graph[node][i]);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int v, e, a, b, i;
	
	cin >> v >> e;
	graph.assign(v + 1, vector<char>());
	infected.assign(v + 1, false);
	for(i = 0; i < e; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cout << dfs(1) - 1;
	
	return 0;
}