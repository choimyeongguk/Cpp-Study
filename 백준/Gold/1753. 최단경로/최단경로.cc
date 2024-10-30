#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int V, E, K, u, v, w, n, i;
	vector<vector<pii>> graph;
	vector<int> dist;
	priority_queue<pii, vector<pii>, greater<pii>> bfs;
	
	cin >> V >> E >> K;
	graph.resize(V + 1);
	for(i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({w, v});
	}
	
	dist.assign(V + 1, INF);
	dist[K] = 0;
	bfs.push({0, K});
	while(!bfs.empty()) {
		w = bfs.top().first;
		n = bfs.top().second;
		bfs.pop();
		if(w > dist[n]) continue;
		for(auto& nn : graph[n]) {
			if(dist[nn.second] > w + nn.first) {
				dist[nn.second] = w + nn.first;
				bfs.push({dist[nn.second], nn.second});
			}
		}
	}
	for(i = 1; i <= V; i++) {
		if(dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	
	return 0;
}