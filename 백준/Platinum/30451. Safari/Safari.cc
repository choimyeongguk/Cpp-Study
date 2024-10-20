#include <bits/stdc++.h>
#define INF -1000000000
using namespace std;

struct Animal {
	int x, y, s, e;
};

vector<vector<pair<int,int>>> graph;  // node, weight
vector<int> in_degree;  // # of in
vector<int> dag;  // node, weight
vector<int> dist;

void search(int node) {
	if(in_degree[node]) return;
	dag.push_back(node);
	
	for(auto& e : graph[node]) {
		in_degree[e.first]--;
		search(e.first);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, arrival, ans, i, j;
	vector<Animal> p;
	
	cin >> n;
	
	p.assign(n + 1, { 0, 0, 0, 0 });
	for(i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
	for(i = 1; i <= n; i++) cin >> p[i].s >> p[i].e;
	
	graph.assign(n + 1, vector<pair<int,int>>());
	in_degree.assign(n + 1, 0);
	for(i = 0; i <= n; i++) {  // from
		for(j = 0; j <= n; j++) {  // to
			arrival = p[i].e + abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
			if(arrival < p[j].s) {  // arrived before appear
				graph[i].push_back({ j, p[j].e - p[j].s });
				in_degree[j]++;
			} else if(arrival < p[j].e) {  // arrived before disappear
				graph[i].push_back({ j, p[j].e - arrival });
				in_degree[j]++;
			}
		}
	}
	
	vector<int> start;
	for(i = 0; i <= n; i++) {
		if(!in_degree[i]) start.push_back(i);  // 시작 후보군 추출 
	}
	for(auto& e : start) {
		search(e);  // 노드 위상 정렬 
	}
	
	dist.assign(n + 1, INF);
	dist[0] = 0;
	for(auto& node : dag) {
		for(j = 0; j < graph[node].size(); j++) {
			if(dist[graph[node][j].first] <= dist[node] + graph[node][j].second) {
				dist[graph[node][j].first] = dist[node] + graph[node][j].second;
			}
		}
	}
	
	ans = 0;
	for(auto& e : dist) {
		if(ans < e) ans = e;
	}
	cout << ans;
	
	return 0;
}