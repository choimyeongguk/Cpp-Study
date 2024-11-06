#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

void preTOpost(auto root, auto end) {
	if(root >= end) return;
	auto idx = lower_bound(root + 1, end, *root);
	preTOpost(root + 1, idx);
	preTOpost(idx, end);
	cout << *root << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int tmp;
	while(cin >> tmp) tree.push_back(tmp);
	preTOpost(tree.begin(), tree.end());
	
	return 0;
}