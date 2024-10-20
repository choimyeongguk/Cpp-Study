#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, n, i;
	long long int dp[101];
	
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for(i = 6; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	
	return 0;
}