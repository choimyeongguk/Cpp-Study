#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, C = 0, M = 0, cost, start, end, i, j;
	int graph[201][201];
	bool visited[201] = { false };
	vector<pair<int,int>> line;
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	
	cin >> N;
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}

	pq.push({ 0, { 1, 1 }});	// cost 0, node 0
	while(!pq.empty()) {
		cost = pq.top().first;
		start = pq.top().second.first;
		end = pq.top().second.second;
		pq.pop();
		if(visited[end]) continue;
		visited[end] = true;
		
		if(cost) {
			C += cost, M++;
			line.push_back({ start, end });
		}
		
		for(i = 1; i <= N; i++) {
			if(visited[i]) continue;
			pq.push({ (graph[end][i] < 0 ? 0 : graph[end][i]), { end, i } });
		}
	}
	
	for(i = 1; i <= N; i++) {
		for(j = 1; j < i; j++) {
			if(graph[i][j] < 0) {
				C -= graph[i][j];
			}
		}
	}
	
	cout << C << " " << M << "\n";
	for(auto& e : line) {
		cout << e.first << " " << e.second << "\n";
	}
	
	return 0;
}