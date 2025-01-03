#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, coin, i, j;
	int dp[10001] = { 0 };
	
	cin >> n >> k;
	for(i = 1; i <= k; i++) dp[i] = INF;
	for(i = 0; i < n; i++) {
		cin >> coin;
		if(coin > k) continue;
		for(j = 0; j + coin <= k; j++)
			dp[j + coin] = min(dp[j + coin], dp[j] + 1);
	}
	cout << (dp[k] == INF ? -1 : dp[k]);
	
	return 0;
}