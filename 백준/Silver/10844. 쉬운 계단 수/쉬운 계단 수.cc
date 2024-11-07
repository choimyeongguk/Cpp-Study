#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int main() {
	int N, ans = 0, i, j;
	int dp[101][10] = { 0 };
	
	cin >> N;
	
	for(i = 1; i <= 9; i++) dp[1][i] = 1;
	for(i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		for(j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MAX;
		}
		dp[i][9] = dp[i - 1][8];
	}
	for(i = 0; i <= 9; i++) {
		ans = (ans + dp[N][i]) % MAX;
	}
	cout << ans;
	
	return 0;
}