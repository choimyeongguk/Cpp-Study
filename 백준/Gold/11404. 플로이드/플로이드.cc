#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, s, m, e, c, i;
	cin >> N >> M;
	vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
	for(i = 1; i <= N; i++) graph[i][i] = 0;
	for(i = 0; i < M; i++) {
		cin >> s >> e >> c;
		graph[s][e] = min(graph[s][e], c);
	}
	
	for(m = 1; m <= N; m++) {
		for(s = 1; s <= N; s++) {
			for(e = 1; e <= N; e++) {
				graph[s][e] = min(graph[s][e], graph[s][m] + graph[m][e]);
			}
		}
	}
	
	for(s = 1; s <= N; s++) {
		for(e = 1; e <= N; e++) {
			cout << (graph[s][e] == INF ? 0 : graph[s][e]) << " ";
		}
		cout << "\n";
	}
	
	return 0;
}