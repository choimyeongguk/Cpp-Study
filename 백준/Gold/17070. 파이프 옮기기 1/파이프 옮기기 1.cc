#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, tmp, i, j;
	cin >> N;
	vector<vector<int>> pipe(N + 1, vector<int>(N + 1, 0));
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(3, 0)));
	
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++) {
			cin >> pipe[i][j];
		}
	}
	
	dp[1][2][0] = 1;
	for(i = 1; i <= N; i++) {
		for(j = 3; j <= N; j++) {
			if(pipe[i][j]) continue;
			if(!pipe[i - 1][j] && !pipe[i][j - 1]) {
				dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
			dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
		}
	}
	
	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
	
	return 0;
}