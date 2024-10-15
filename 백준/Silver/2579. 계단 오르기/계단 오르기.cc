#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, i;
	vector<int> stair;
	vector<int> dp;
	
	cin >> n;
	stair.assign(n + 1, 0);
	dp.assign(n + 1, 0);
	for(i = 1; i <= n; i++) {
		cin >> stair[i];
	}
	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[2] + stair[1];
	for(i = 3; i <= n; i++) {
		dp[i] = max(stair[i] + dp[i-2], stair[i] + stair[i-1] + dp[i-3]);
	}
	cout << dp[n];
	
	return 0;
}