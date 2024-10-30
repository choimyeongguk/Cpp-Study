#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> seq;
vector<int> ans;

void solve(int start, int depth) {
	if(depth == M) {
		for(auto& e : ans) cout << e << " ";
		cout << "\n";
		return;
	}
	for(int i = start; i < N; i++) {
		if(seq[i - 1] == seq[i]) continue;
		ans.push_back(seq[i]);
		solve(i, depth + 1);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	seq.resize(N);
	for(auto& e : seq) cin >> e;
	sort(seq.begin(), seq.end());
	
	solve(0, 0);
	
	return 0;
}