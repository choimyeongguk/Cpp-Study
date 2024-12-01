#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, A, B, C, i;
	int cnt = 0, sum = 0, max = 0, cost, node;
	vector<bool> visited;
	vector<vector<pair<int,int>>> graph;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	cin >> N >> M;
	visited.assign(N + 1, false);
	graph.resize(N + 1);
	for(i = 0; i < M; i++) {
		cin >> A >> B >> C;
		graph[A].push_back({C, B});
		graph[B].push_back({C, A});
	}
	
	pq.push({0, 1});
	while(cnt < N) {
		cost = pq.top().first;
		node = pq.top().second;
		pq.pop();
		if(visited[node])
			continue;
		visited[node] = true;
		cnt++;
		sum += cost;
		max = max > cost ? max : cost;
		for(auto& e : graph[node]) {
			if(!visited[e.second]) {
				pq.push({e.first, e.second});
			}
		}
	}
	cout << sum - max;
	
	return 0;
}