#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, n, i;
	int dp[12];
	dp[1] = 1;
	dp[2] = 1 + dp[1];
	dp[3] = 1 + dp[2] + dp[1];
	for(i = 4; i <= 11; i++) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	
	return 0;
}