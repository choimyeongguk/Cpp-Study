#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

int root(int x) {
	while(x != tree[x]) {
		x = tree[x];
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, a, b, ra, rb, result = 0, i;
	
	cin >> n >> m;
	tree.assign(n, -1);
	for(i = 1; i <= m; i++) {
		cin >> a >> b;
		if(tree[a] == -1 && tree[b] == -1) {
			tree[a] = a;  // a를 root 노드로
			tree[b] = a;  // b를 child 노드로 
		} else if(tree[a] == -1) {
			tree[a] = b;
		} else if(tree[b] == -1) {
			tree[b] = a;
		} else {  // 둘 다 부모가 있음 
			ra = root(a);
			rb = root(b);
			if(ra == rb) {
				result = i;
				break;
			} else {
				tree[rb] = a;  // b의 root 노드를 a의 child 노드로 
			}
		}
	}
	
	cout << result; 
	
	return 0;
}