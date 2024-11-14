#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, s, e, c, cnt, i;
	int curCost, curNode, nxtCost, nxtNode;
	vector<vector<pair<int,int>>> graph;  // cost, node
	vector<int> dist;
	vector<int> prev;
	deque<int> path;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	cin >> n >> m;
	graph.resize(n + 1);
	for(i = 0; i < m; i++) {
		cin >> s >> e >> c;
		graph[s].push_back({ c, e });
	}
	cin >> s >> e;
	
	dist.assign(n + 1, INF);
	prev.assign(n + 1, INF);
	pq.push({ 0, s });
	dist[s] = 0;
	while(pq.top().second != e) {
		curCost = pq.top().first;
		curNode = pq.top().second;
		pq.pop();
		if(dist[curNode] < curCost)
			continue;
		for(auto& e : graph[curNode]) {
			nxtCost = curCost + e.first;
			nxtNode = e.second;
			if(dist[nxtNode] > nxtCost) {
				dist[nxtNode] = nxtCost;
				prev[nxtNode] = curNode;
				pq.push({ nxtCost, nxtNode });
			}
		}
	}
	
	for(cnt = 0, i = e; i != s; i = prev[i], cnt++)
		path.push_front(i);
	path.push_front(s);
	
	cout << pq.top().first << "\n";
	cout << cnt + 1 << "\n";
	for(auto& e : path)
		cout << e << " ";
	
	return 0;
}