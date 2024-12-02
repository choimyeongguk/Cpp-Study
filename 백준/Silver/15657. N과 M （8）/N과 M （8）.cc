#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> num;
vector<int> ans;

void solve(int depth) {
	if(ans.size() == M) {
		for(auto& e : ans)
			cout << e << " ";
		cout << "\n";
		return;
	}
	for(int i = depth; i < N; i++) {
		ans.push_back(num[i]);
		solve(i);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	num.resize(N);
	for(auto& e : num)
		cin >> e;
	sort(num.begin(), num.end());
	solve(0);
	
	return 0;
}