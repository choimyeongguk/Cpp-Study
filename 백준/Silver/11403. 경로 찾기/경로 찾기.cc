#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, tmp, i, j;
	vector<vector<short>> graph;
	
	cin >> N;
	graph.assign(N, vector<short>(N, 0));
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	
	for(int m = 0; m < N; m++) {
		for(int s = 0; s < N; s++) {
			for(int e = 0; e < N; e++) {
				if(graph[s][m] && graph[m][e]) {
					graph[s][e] = true;
				}
			}
		}
	}
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}