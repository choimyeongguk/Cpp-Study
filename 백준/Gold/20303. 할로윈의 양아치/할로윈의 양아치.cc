#include <bits/stdc++.h>
using namespace std;

struct Tree {
	int pa;
	int size;
	int candy;
};

vector<Tree> tree;

int root(int x) {
	while(tree[x].pa != x) {
		tree[x].pa = tree[tree[x].pa].pa;
		x = tree[x].pa;
	}
	return x;
}

void merge(int a, int b) {
	a = root(a);
	b = root(b);
	if(a == b) return;
	tree[b].pa = a;
	tree[a].size += tree[b].size;
	tree[a].candy += tree[b].candy;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, K, a, b, ans, i, j;
	
	cin >> N >> M >>K;
	tree.resize(N + 1);
	for(i = 1; i <= N; i++) {
		tree[i].pa = i;
		tree[i].size = 1;
		cin >> tree[i].candy;
	}
	for(i = 0; i < M; i++) {
		cin >> a >> b;
		merge(a, b);
	}
	
//	for(i = 1; i <= N; i++) {
//		cout << i << " ,부모: " << tree[i].pa << " ,크기: " << tree[i].size << " ,캔디: " << tree[i].candy << "\n";
//	}
	
	vector<pair<int,int>> group;  // 인원 수, 캔디 수 
	vector<vector<int>> dp;
	// dp[i][j]=k : 최대 개수가 i이고, j번째 까지 봤을 때, 최대 캔디 수는 k개 
	
	group.push_back({0, 0}); // dummy
	for(ans = 0, i = 1; i <= N; i++) {
		if(tree[i].pa == i && tree[i].size < K)
			group.push_back({tree[i].size, tree[i].candy});
	}
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