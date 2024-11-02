#include <bits/stdc++.h>
using namespace std;

int n1, n2, l;
vector<vector<pair<int,int>>> tree;  // 노드, 가중치 
vector<bool> visited;

void dfs(int n, int w) {
	if(l < w) {
		l = w;
		n1 = n;
	}
	for(int i = 0; i < tree[n].size(); i++) {
		if(visited[tree[n][i].first]) continue;
		
		visited[tree[n][i].first] = true;
		dfs(tree[n][i].first, w + tree[n][i].second);
		visited[tree[n][i].first] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int V, w, i;
	
	cin >> V;
	tree.resize(V + 1);
	for(i = 0; i < V; i++) {
		cin >> n1;
		while(true) {
			cin >> n2;
			if(n2 == -1) break;
			cin >> w;
			tree[n1].push_back({n2, w});
		}
	}
	l = 0, n1 = 0;
	visited.assign(V + 1, false);
	visited[1] = true;
	dfs(1, 0);
	
	l = 0;
	visited.assign(V + 1, false);
	visited[n1] = true;
	dfs(n1, 0);
	cout << l;
	
	
	return 0;
}