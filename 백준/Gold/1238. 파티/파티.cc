#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;

void dijkstra(int start, int N, vector<vector<pii>>& graph, vector<int>& dist) {
	int curCost, curNode;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	dist.assign(N + 1, INF);
	dist[start] = 0;
	pq.push({0, start});
	while(!pq.empty()) {
		curCost = pq.top().first;
		curNode = pq.top().second;
		pq.pop();
		if(dist[curNode] < curCost) continue;
		for(auto& nxt : graph[curNode]) {
			if(dist[nxt.second] > curCost + nxt.first) {
				dist[nxt.second] = curCost + nxt.first;
				pq.push({dist[nxt.second], nxt.second});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int M, N, X, S, E, T, ans, i;
	vector<vector<pii>> graph1;  // X to Nodes
	vector<vector<pii>> graph2;  // Nodes to X
	vector<int> dist1;
	vector<int> dist2;
	
	cin >> N >> M >> X;
	graph1.resize(N + 1);
	graph2.resize(N + 1);
	for(i = 0; i < M; i++) {
		cin >> S >> E >> T;
		graph1[S].push_back({T, E});
		graph2[E].push_back({T, S});
		// 각 노드에서 X로 가는 최단 경로는 단방향 간선의 방향을 뒤집었을 때, 
		// X에서 각 노드로 가는 최단 경로와 같다. 
	}
	
	dijkstra(X, N, graph1, dist1);
	dijkstra(X, N, graph2, dist2);
	for(ans = 0, i = 1; i <= N; i++)
		ans = max(ans, dist1[i] + dist2[i]);
	cout << ans;
	
	return 0;
}