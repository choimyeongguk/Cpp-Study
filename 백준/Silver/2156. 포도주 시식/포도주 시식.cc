#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, num, i;
	int wine[10002]; 
	int dp[10002][2] = { 0 };
	// dp[i][0] = j : i잔을 마시지 않는 경우 최대
	// dp[i][1] = j : i잔을 마시는 경우 최대 
	
	cin >> n;
	for(i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	dp[1][1] = wine[1];
	for(i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = wine[i] + max(wine[i - 1] + dp[i - 2][0], dp[i - 1][0]);
	}
	cout << max(dp[n][0], dp[n][1]);
	
	return 0;
}