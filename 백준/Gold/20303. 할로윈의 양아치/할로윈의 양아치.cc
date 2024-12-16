#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, K, a, b, num, sum, i, j;
	int candy[30001];
	queue<int> q;
	vector<bool> visited;
	vector<vector<int>> graph;
	vector<pair<int,int>> group;
	vector<int> dp;
	
	cin >> N >> M >> K;
	for(i = 1; i <= N; i++) {
		cin >> candy[i];
	}
	graph.resize(N + 1);
	for(i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	visited.assign(N + 1, false);
	for(i = 1; i <= N; i++) {
		if(visited[i]) continue;
		num = 0, sum = 0;
		q.push(i);
		visited[i] = true;
		while(!q.empty()) {
			num++;
			sum += candy[q.front()];
			for(auto& e : graph[q.front()]) {
				if(!visited[e]) {
					q.push(e);
					visited[e] = true;
				}
			}
			q.pop();
		}
		group.push_back({num, sum});
	}
	
	dp.assign(K, 0);
	for(auto& e : group) {
		num = e.first;
		sum = e.second;
		for(j = K - 1; j >= num; j--) {
			dp[j] = max(dp[j], sum + dp[j - num]);
		}
	}
	cout << dp[K - 1];
	
	return 0;
}