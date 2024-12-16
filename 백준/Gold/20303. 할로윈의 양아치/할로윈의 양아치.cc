#include <bits/stdc++.h>
using namespace std;

int candy[30001];
vector<bool> visited;
vector<vector<int>> graph;
vector<pair<int,int>> group;  // 인원 수, 캔디 수 

pair<int,int> dfs(int x) {
	visited[x] = true;
	pair<int,int> tmp, ret = { 1, candy[x] };
	for(auto& e : graph[x]) {
		if(!visited[e]) {
			tmp = dfs(e);
			ret.first += tmp.first;
			ret.second += tmp.second;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, K, a, b, i, j;
	
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
	group.push_back({0, 0});  // dummy
	for(i = 1; i <= N; i++) {
		if(!visited[i]) {
			group.push_back(dfs(i));
		}
	}
	
	vector<vector<int>> dp;
	// dp[i][j]=k : 최대 개수가 i이고, j번째 까지 봤을 때, 최대 캔디 수는 k개 
	dp.assign(K, vector<int>(group.size(), 0));
	for(i = 1; i < K; i++) {
		for(j = 1; j < group.size(); j++) {
			dp[i][j] = dp[i][j - 1];
			if(i >= group[j].first) {
				dp[i][j] = max(dp[i][j], group[j].second + dp[i - group[j].first][j - 1]);
			}
		}
	}
	cout << dp[K - 1][group.size() - 1];
	
	
	return 0;
}