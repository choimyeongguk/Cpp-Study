#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, num, tmp, ans, i, j, k;
	int group[51][51];  // group[i][j]=k : i번째 파티의 j번째 사람은 k번 
	
	cin >> N >> M >> num;

	vector<int> knowTrue(num);
	vector<vector<int>> graph(N + 1);
	for(i = 0; i < num; i++) {
		cin >> knowTrue[i];
	}
	for(i = 0; i < M; i++) {
		cin >> num;
		for(j = 0; j < num; j++) {
			cin >> group[i][j];
		}
		for(j = 0; j < num; j++) {
			for(k = 0; k < num; k++) {
				graph[group[i][j]].push_back(group[i][k]);
			}
		}
	}
	
	vector<int> visited(N + 1, false);
	
	queue<int> bfs;
	for(auto& e : knowTrue) {
		bfs.push(e);
		while(!bfs.empty()) {
			int& n = bfs.front();
			for(i = 0; i < graph[n].size(); i++) {
				if(visited[graph[n][i]]) continue;
				visited[graph[n][i]] = true;
				bfs.push(graph[n][i]);
			}
			bfs.pop();
		}
	}
	
	for(ans = 0, i = 0; i < M; i++)
		if(!visited[group[i][0]]) ans++;
	cout << ans;
	
	return 0;
}