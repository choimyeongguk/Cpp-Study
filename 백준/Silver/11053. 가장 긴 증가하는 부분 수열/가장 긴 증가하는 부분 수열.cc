#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans, max, i, j;
	vector<int> seq;
	vector<int> dp;
	
	cin >> N;
	seq.resize(N);
	for(auto& e : seq) cin >> e;
	dp.resize(N);
	dp[0] = 1, ans = 1;
	for(i = 1; i < N; i++) {
		for(max = 0, j = i - 1; j >= 0; j--) {
			if(seq[j] < seq[i] && dp[j] > max) max = dp[j];
		}
		dp[i] = max + 1;
		if(ans < dp[i]) ans = dp[i];
	}
	cout << ans;
	
	return 0;
}