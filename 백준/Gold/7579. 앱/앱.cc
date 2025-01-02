#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, i, j;
	int m[100], c[100], dp[10000000];
	// dp[i]=j : i바이트 이상을 비워야 할 때 최소 비용 j
	
	cin >> N >> M;
	for(i = 0; i < N; i++)  cin >> m[i];
	for(i = 0; i < N; i++)  cin >> c[i];
	for(i = 1; i <= M; i++) dp[i] = 0x3f3f3f3f;
	dp[0] = 0;
	
	for(i = 0; i < N; i++) {
		dp[M] = min(dp[M], c[i] + dp[M - m[i]]);
		for(j = M - 1; j >= m[i]; j--) {
			dp[j] = min(dp[j], dp[j + 1]);
			dp[j] = min(dp[j], c[i] + dp[j - m[i]]);
		}
	}
	cout << dp[M];
	
	return 0;
}