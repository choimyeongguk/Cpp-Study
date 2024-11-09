#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct Edge {
	int s, e, t;
};

bool bellman_ford() {
	int N, M, W, S, E, T, curNode, nxtNode, cost, i;
	vector<int> dist;
	vector<Edge> edge;
	
	cin >> N >> M >> W;
	
	dist.assign(N + 1, INF);
	for(i = 0; i < M; i++) {
		cin >> S >> E >> T;
		edge.push_back({S, E, T});
		edge.push_back({E, S, T});
	}
	for(i = 0; i < W; i++) {
		cin >> S >> E >> T;
		edge.push_back({S, E, -T});
	}
	
	dist[1] = 0;
	for(i = 1; i <= N; i++) {
		for(auto& e : edge) {
			curNode = e.s;
			nxtNode = e.e;
			cost = e.t;
			
			if(dist[nxtNode] > dist[curNode] + cost) {
				if(i == N) return true;
				dist[nxtNode] = dist[curNode] + cost;
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