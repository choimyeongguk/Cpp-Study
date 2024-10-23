#include <bits/stdc++.h>
#define INF 15000
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, s, m, e, i, j, min, sum;
	vector<vector<short>> graph;
	vector<int> kevin_bacon;
	
	cin >> N >> M;
	
	graph.assign(N + 1, vector<short>(N + 1, INF));
	kevin_bacon.assign(N + 1, INF);
	for(i = 1; i <= N; i++) {
		graph[i][i] = 0;
	}
	for(i = 0; i < M; i++) {
		cin >> s >> e;
		graph[s][e] = 1;
		graph[e][s] = 1;
	}
	
	
	for(m = 1; m <= N; m++) {
		for(s = 1; s <= N; s++) {
			for(e = 1; e <= N; e++) {
				if(graph[s][e] > graph[s][m] + graph[m][e]) {
					graph[s][e] = graph[s][m] + graph[m][e];
				}
			}
		}
	}
	
	min = 0;
	for(i = 1; i <= N; i++) {
		sum = 0;
		for(j = 1; j <= N; j++) {
			sum += graph[i][j];
		}
		kevin_bacon[i] = sum;
		if(kevin_bacon[min] > sum) min = i;
	}
	cout << min;
	
	return 0;
}