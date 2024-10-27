#include <bits/stdc++.h>
#define min(a, b) a < b ? a : b
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, ans, idx, i;
	vector<vector<int>> dp(2, vector<int>(3, 0));
	
	cin >> N;
	for(i = 0; i < N; i++) {
		idx = i % 2;
		cin >> dp[idx][0] >> dp[idx][1] >> dp[idx][2];
		dp[idx][0] += min(dp[!idx][1], dp[!idx][2]);
		dp[idx][1] += min(dp[!idx][0], dp[!idx][2]);
		dp[idx][2] += min(dp[!idx][0], dp[!idx][1]);
	}
	ans = min(dp[idx][0], dp[idx][1]);
	ans = min(ans, dp[idx][2]);
	cout << ans;
	
	return 0;
}