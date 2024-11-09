#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i;
	long long dp[91][2];
	
	dp[1][0] = 0, dp[1][1] = 1;
	for(i = 2; i <= 90; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	
	cin >> N;
	cout << dp[N][0] + dp[N][1];
	
	return 0;
}