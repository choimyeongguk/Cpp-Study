#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K, i, j;
	int dp[1001][1001];	// nCk = n-1Ck-1 + n-1Ck
	
	cin >> N >> K;
	
	for(i = 1; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for(i = 1; i <= N; i++) {
		for(j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[N][K];

	return 0;
}