#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, s, m, e, c, i;
	cin >> N >> M;
	vector<vector<int>> graph(N, vector<int>(N, INF));
	for(i = 0; i < N; i++) graph[i][i] = 0;
	for(i = 0; i < M; i++) {
		cin >> s >> e >> c;
		s--, e--;
		graph[s][e] = min(graph[s][e], c);
	}
	
	for(m = 0; m < N; m++) {
		for(s = 0; s < N; s++) {
			for(e = 0; e < N; e++) {
				graph[s][e] = min(graph[s][e], graph[s][m] + graph[m][e]);
			}
		}
	}
	
	for(auto& r : graph) {
		for(auto& c : r) {
			cout << (c == INF ? 0 : c) << " ";
		}
		cout << "\n";
	}
	
	return 0;
}