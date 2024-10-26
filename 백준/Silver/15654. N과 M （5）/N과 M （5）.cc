#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> seq;
vector<int> idx;
vector<bool> used;

void comb(int start, int depth) {
	if(depth == M) {
		for(auto& e : idx) cout << e << " ";
		cout << "\n";
		return;
	}
	for(int i = 0; i < N; i++) {
		if(used[i]) continue;
		idx.push_back(seq[i]);
		used[i] = true;
		comb(i, depth + 1);
		idx.pop_back();
		used[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	seq.resize(N);
	used.assign(N, false);
	for(auto& e : seq) cin >> e;
	sort(seq.begin(), seq.end());
	comb(-1, 0);
	
	return 0;
}