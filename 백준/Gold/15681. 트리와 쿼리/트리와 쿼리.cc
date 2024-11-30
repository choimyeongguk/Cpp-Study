#include <bits/stdc++.h>
using namespace std;

int numNode[100001] = { 0 };
vector<bool> visited;
vector<vector<int>> tree;

int cntNode(int node) {
	numNode[node]++;
	visited[node] = true;
	for(auto& e : tree[node]) {
		if(!visited[e]) {
			numNode[node] += cntNode(e);
		}
	}
	return numNode[node];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, R, Q, U, V, i;
	
	cin >> N >> R >> Q;
	visited.assign(N + 1, false);
	tree.resize(N + 1);
	for(i = 1; i < N; i++) {
		cin >> U >> V;
		tree[U].push_back(V);
		tree[V].push_back(U);
	}
	
	cntNode(R);
	
	for(i = 0; i < Q; i++) {
		cin >> U;
		cout << numNode[U] << "\n";
	}
	
	return 0;
}