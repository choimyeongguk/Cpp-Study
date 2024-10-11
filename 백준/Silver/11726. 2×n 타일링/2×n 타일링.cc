#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i;
	vector<int> dp;
	
	cin >> n;
	dp.assign(n + 2, 0);
	dp[1] = 1;
	dp[2] = 2;
	for(i = 3; i <= n; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % 10007;
	}
	cout << dp[n];
	
	return 0;
}