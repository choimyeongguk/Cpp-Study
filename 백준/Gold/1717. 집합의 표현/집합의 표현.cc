#include <bits/stdc++.h>
using namespace std;

int tree[1000001];	// tree[i]=j : i노드의 부모는 j; 

int root(int x) {
	if(x == tree[x])
		return x;
	else
		return root(tree[x]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, op, a, b, i;
	
	cin >> n >> m;
	for(i = 0; i <= n; i++) {
		tree[i] = i;
	}
	for(i = 0; i < m; i++) {
		cin >> op >> a >> b;
		if(op == 0) {
			tree[root(b)] = root(a);
		}
		else {
			if(root(a) == root(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	
	return 0;
}