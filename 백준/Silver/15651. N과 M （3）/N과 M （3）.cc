#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> ans;

void combr(int depth) {
	if(depth == M) {
		for(auto& e : ans) cout << e << " ";
		cout << "\n";
		return;
	}
	for(int i = 1; i <= N; i++) {
		ans.push_back(i);
		combr(depth + 1);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	combr(0);
	
	return 0;
}