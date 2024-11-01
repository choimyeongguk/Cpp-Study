#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<pair<int,vector<int>>> tree;
// tree[i].first : i노드와 그 부모간의 가중치
// tree[i].second[j] = k : i노드의 j번째 자식은 k 노드 

void postorder(int parent) {
	int i, w, first = 0, second = 0;
	int numChild = tree[parent].second.size();
	for(i = 0; i < numChild; i++) {
		postorder(tree[parent].second[i]);
	}
	for(i = 0; i < numChild; i++) {
		w = tree[tree[parent].second[i]].first;
		if(w >= first) {
			second = first;
			first = w;
		} else if(w >= second) {
			second = w;
		}
	}
	tree[parent].first += first;
	ans = ans > first + second ? ans : first + second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, p, c, w, i;
	
	cin >> n;
	tree.assign(n + 1, pair<int,vector<int>>({0,vector<int>()}));
	for(i = 1; i < n; i++) {
		cin >> p >> c >> w;
		tree[c].first = w;
		tree[p].second.push_back(c);
	}
	postorder(1);
	cout << ans;
	
	return 0;
}