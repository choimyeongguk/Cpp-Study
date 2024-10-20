#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i;
	int dp[1001];
	
	dp[0] = dp[1] = 1;
	for(i = 2; i <= 1000; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}
	cin >> n;
	cout << dp[n];
	
	return 0;
}