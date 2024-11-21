#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int V, E, A, B, C, ans, cost, node, i;
	vector<bool> visited;
	vector<vector<pair<int,int>>> graph;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	cin >> V >> E;
	
	visited.assign(V + 1, false);
	graph.resize(V + 1);
	
	for(i = 0; i < E; i++) {
		cin >> A >> B >> C;
		graph[A].push_back({C, B});
		graph[B].push_back({C, A});
	}

	pq.push({0, 1});
	while(!pq.empty()) {
		cost = pq.top().first;
		node = pq.top().second;
		pq.pop();
		if(visited[node])
			continue;
		
		ans += cost;
		visited[node] = true;
		for(auto& e : graph[node]) {
			if(!visited[e.second]) {
				pq.push(e);
			}
		}
	}
	cout << ans;
	
	return 0;
}