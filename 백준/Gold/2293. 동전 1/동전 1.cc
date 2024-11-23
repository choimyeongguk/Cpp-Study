#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, i, j;
	int coin[101];
	int dp[10001] = { 0 };	// dp[i] = j : 가치 합 i인 경우의 수 j 
	
	cin >> n >> k;
	for(i = 0; i < n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for(i = 0; i < n; i++) {
		for(j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k];
	
	return 0;
}