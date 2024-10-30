#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> ans;
vector<bool> used;

void comb(int start) {
	if(ans.size() == M) {
		for(auto& e : ans) cout << e << " ";
		cout << "\n";
		return;
	}
	for(int i = 1; i <= N; i++) {
		if(used[i]) continue;
		ans.push_back(i);
		used[i] = true;
		comb(i);
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
	comb(0);
	return 0;
}