#include <bits/stdc++.h>
#define INF 700000000
using namespace std;

typedef pair<int,int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, E, a, b, c, v1, v2, n, i;
	int StoV1, StoV2, VtoV, V1toE, V2toE;
	vector<vector<int>> graph;
	vector<int> dist;
	priority_queue<pii, vector<pii>, greater<pii>> heap;
	
	cin >> N >> E;
	graph.assign(N + 1, vector<int>(N + 1, INF));
	for(i = 1; i <= N; i++) graph[i][i] = 0;
	for(i = 1; i <= E; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	cin >> v1 >> v2;
	
	dist.assign(N + 1, INF);
	dist[1] = 0;
	heap.push({0, 1});
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
	StoV1 = dist[v1];
	StoV2 = dist[v2];
	
	dist.assign(N + 1, INF);
	dist[v1] = 0;
	heap.push({0, v1});
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
	VtoV = dist[v2];
	V1toE = dist[N];
	
	dist.assign(N + 1, INF);
	dist[v2] = 0;
	heap.push({0, v2});
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
	V2toE = dist[N];
	
//	cout << "StoV1 : " << StoV1 << "\n";
//	cout << "StoV2 : " << StoV2 << "\n";
//	cout << "VtoV : " << VtoV << "\n";
//	cout << "V1toE : " << V1toE << "\n";
//	cout << "V2toE : " << V2toE << "\n";
	int t1 = StoV1 + VtoV + V2toE;
	int t2 = StoV2 + VtoV + V1toE;
	if(t1 >= INF && t2 >= INF) cout << "-1";
	else cout << (t1 < t2 ? t1 : t2);
	
	return 0;
}