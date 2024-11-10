#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> pii;

int N;
vector<vector<pii>> graph;  // 소요시간, 끝점 

void dijkstra(int start, vector<int>& dist) {
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
	
	int M, X, S, E, T, ans, i;
	vector<int> dist1;
	vector<int> dist2;
	
	cin >> N >> M >> X;
	graph.resize(N + 1);
	for(i = 0; i < M; i++) {
		cin >> S >> E >> T;
		graph[S].push_back({T, E});
	}
	
	dijkstra(X, dist1);
	for(ans = 0, i = 1; i <= N; i++) {
		dijkstra(i, dist2);
		ans = max(ans, dist1[i] + dist2[X]);
	}
	cout << ans;
	
	return 0;
}