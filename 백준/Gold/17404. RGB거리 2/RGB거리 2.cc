#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int N, ans = INF;
int cost[1001][3] = { 0 };
int dp[1001][3];

void solve(int r, int g, int b) {
	dp[1][0] = r, dp[1][1] = g, dp[1][2] = b;
	for(int i = 2; i <= N; i++) {
		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	if(r != INF)
		ans = min(ans, min(dp[N][1], dp[N][2]));
	else if(g != INF)
		ans = min(ans, min(dp[N][0], dp[N][2]));
	else
		ans = min(ans, min(dp[N][0], dp[N][1]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	
	solve(cost[1][0], INF, INF);
	solve(INF, cost[1][1], INF);
	solve(INF, INF, cost[1][2]);
	
	cout << ans;
	
	return 0;
}