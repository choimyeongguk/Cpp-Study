#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, tmp, i;
	int dp[100001][2];
	
	cin >> n >> dp[1][1];
	dp[1][0] = dp[1][1];
	for(i = 2; i <= n; i++) {
		cin >> tmp;
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = tmp + max(dp[i - 1][1], 0);
	}

	cout << max(dp[n][0], dp[n][1]);
	
	return 0;
}