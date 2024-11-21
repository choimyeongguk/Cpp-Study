#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b, m, p, c, ans = -1, i;
	vector<vector<int>> graph;
	vector<bool> visited;
	queue<pair<int,int>> q;
	
	cin >> n >> a >> b >> m;
	graph.resize(n + 1);
	for(i = 0; i < m; i++) {
		cin >> p >> c;
		graph[p].push_back(c);
		graph[c].push_back(p);
	}
	
	visited.assign(n + 1, false);
	visited[a] = true;
	q.push({a, 0});
	while(!q.empty()) {
		int& node = q.front().first;
		int& cost = q.front().second;
		if(node == b) {
			ans = cost;
			break;
		}
		for(auto& e : graph[node]) {
			if(!visited[e]) {
				visited[e] = true;
				q.push({e, cost + 1});
			}
		}
		q.pop();
	}
	cout << ans;
	
	return 0;
}