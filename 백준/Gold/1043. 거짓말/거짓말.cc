#include <bits/stdc++.h>
using namespace std;

int tree[51];  // tree[i]=j : i노드의 부모는 j 
int level[51];  // tree의 높이 

int root(int x) {
	if(x == tree[x]) return x;
	return tree[x] = root(tree[x]);
}

void combine(int x, int y) {
	if(x == y) return;
	if(!x) {
		tree[y] = x;
		return;
	}
	if(!y) {
		tree[x] = y;
		return;
	}
	if(level[x] > level[y]) tree[y] = x;
	else tree[x] = y;
	if(level[x] == level[y]) level[y]++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, num, tmp, ans, i, j;
	int group[51];
	
	cin >> N >> M;
	
	for(i = 0; i <= N; i++) {
		tree[i] = i;
		level[i] = 1;
	}
	level[0] = 2;
	cin >> num;
	for(i = 0; i < num; i++) {
		cin >> tmp;
		tree[tmp] = 0;  // 진실을 아는 집합의 루트는 0 
	}
	
	for(ans = 0, i = 0; i < M; i++) {
		cin >> num >> group[i];
		for(j = 1; j < num; j++) {
			cin >> tmp;
			combine(root(group[i]), root(tmp));
		}
	}
	for(i = 0; i < M; i++) {
		if(root(tree[group[i]])) ans++;
	}
	
	cout << ans;
	
	return 0;
}