#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct Edge {
	int s, e, t;
	bool isWormhole;
};

bool bellman_ford() {
	int N, M, W, S, E, T, i;
	vector<int> dist;
	vector<Edge> edge;
	
	cin >> N >> M >> W;
	
	dist.assign(N + 1, INF);
	for(i = 0; i < M; i++) {
		cin >> S >> E >> T;
		edge.push_back({S, E, T, false});
	}
	for(i = 0; i < W; i++) {
		cin >> S >> E >> T;
		edge.push_back({S, E, -T, true});
	}
	
	dist[1] = 0;
	for(i = 1; i <= N; i++) {
		for(auto& e : edge) {
			if(dist[e.e] > dist[e.s] + e.t) {
				if(i == N) return true;
				dist[e.e] = dist[e.s] + e.t;
			}
			if(!e.isWormhole && dist[e.s] > dist[e.e] + e.t) {
				if(i == N) return true;
				dist[e.s] = dist[e.e] + e.t;
			}
		}
	}
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin >> TC;
	while(TC--) {
		cout << (bellman_ford() ? "YES" : "NO") << "\n";
	}
	
	return 0;
}