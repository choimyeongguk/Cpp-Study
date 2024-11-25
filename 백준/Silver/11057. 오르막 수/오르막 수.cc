#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, i, j, k, ans = 0;
	int dp[1001][10] = { 0 };
	cin >> N;
	for(i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
		
	for(i = 2; i <= N; i++) {
		for(j = 0; j <= 9; j++) {
			for(k = 0; k <= j; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}
	
	for(i = 0; i <= 9; i++) {
		ans += dp[N][i];
	}
	cout << ans % 10007;
	
	return 0;
}