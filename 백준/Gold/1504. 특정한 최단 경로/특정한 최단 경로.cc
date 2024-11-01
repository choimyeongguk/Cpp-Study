#include <bits/stdc++.h>
#define INF 700000000
using namespace std;

typedef pair<int,int> pii;

int N;
vector<vector<int>> graph;
vector<int> dist;

void dijkstra(int start) {
	int c, n, i;
	priority_queue<pii, vector<pii>, greater<pii>> heap;
	dist.assign(N + 1, INF);
	dist[start] = 0;
	heap.push({0, start});
	while(!heap.empty()) {
		c = heap.top().first;
		n = heap.top().second;
		heap.pop();
		if(dist[n] < c) continue;
		for(i = 1; i <= N; i++) {
			if(dist[i] > c + graph[n][i]) {
				dist[i] = c + graph[n][i];
				heap.push({dist[i], i});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int E, a, b, c, v1, v2, n, t1, t2, i;
	int StoV1, StoV2, VtoV, V1toE, V2toE;
	
	cin >> N >> E;
	graph.assign(N + 1, vector<int>(N + 1, INF));
	for(i = 1; i <= N; i++) graph[i][i] = 0;
	for(i = 1; i <= E; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	cin >> v1 >> v2;
	
	dijkstra(1);
	StoV1 = dist[v1];
	StoV2 = dist[v2];
	
	dijkstra(v1);
	VtoV = dist[v2];
	V1toE = dist[N];
	
	dijkstra(v2);
	V2toE = dist[N];
	
	t1 = StoV1 + VtoV + V2toE;
	t2 = StoV2 + VtoV + V1toE;
	if(t1 >= INF && t2 >= INF) cout << "-1";
	else cout << (t1 < t2 ? t1 : t2);
	
	return 0;
}