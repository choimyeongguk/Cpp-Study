#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, P[1001], i, j;
	int dp[10001][1001] = { 0 };
	
	cin >> N;
	for(i = 1; i <= N; i++)
		cin >> P[i];
		
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j - 1];
			if(i >= j) {
				dp[i][j] = max(dp[i][j], P[j] + dp[i - j][j]);
			}
		}
	}
	cout << dp[N][N];
	
	return 0;
}