#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> seq;
vector<int> ans;
vector<bool> used;

void comb(int depth) {
	if(depth == M) {
		for(auto& e : ans) cout << e << " ";
		cout << "\n";
		return;
	}
	for(int i = 1; i <= N; i++) {
		if(used[i]) continue;
		if(seq[i] == seq[i - 1] && !used[i - 1]) continue;
		used[i] = true;
		ans.push_back(seq[i]);
		comb(depth + 1);
		ans.pop_back();
		used[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	used.assign(N + 1, false);
	seq.assign(N + 1, 0);
	for(int i = 0; i < N; i++) cin >> seq[i];
	sort(seq.begin(), seq.end());
	comb(0);
	
	return 0;
}