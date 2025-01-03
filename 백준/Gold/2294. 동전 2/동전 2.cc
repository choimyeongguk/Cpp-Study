#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, coin, i, j;
	int dp[20001];
	// dp[i] = j : i원을 만드는 데 필요한 최소 동전 수 j 
	
	cin >> n >> k;
	dp[0] = 0;
	for(i = 1; i <= k; i++) dp[i] = -1;
	for(i = 0; i < n; i++) {
		cin >> coin;
		if(coin > k) continue;
		for(j = 0; j + coin <= k; j++) {
			if(dp[j] == -1) continue;
			if(dp[j + coin] == -1) {
				dp[j + coin] = dp[j] + 1;
			}
			else {
				dp[j + coin] = min(dp[j + coin], dp[j] + 1);
			}
		}
	}
	cout << dp[k];
	
	return 0;
}