#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, R, m, s, e, ans, sum, i, j;
	int T[101];
	int graph[101][101];
	
	cin >> N >> M >> R;
	for(i = 1; i <= N; i++) {
		cin >> T[i];
	}
	fill(&graph[0][0], &graph[100][100], INF);
	for(i = 1; i <= N; i++) {
		graph[i][i] = 0;
	}
	for(i = 0; i < R; i++) {
		cin >> s >> e >> m;
		graph[s][e] = m;
		graph[e][s] = m;
	}
	
	for(m = 1; m <= N; m++) {
		for(s = 1; s <= N; s++) {
			for(e = s + 1; e <= N; e++) {
				if(graph[s][e] > graph[s][m] + graph[m][e])
					graph[s][e] = graph[s][m] + graph[m][e];
					graph[e][s] = graph[s][e];
			}
		}
	}
	
	for(ans = 0, i = 1; i <= N; i++) {
		for(sum = 0, j = 1; j <= N; j++) {
			if(graph[i][j] <= M)
				sum += T[j];
		}
		ans = max(ans, sum);
	}
	cout << ans;
	
	return 0;
}