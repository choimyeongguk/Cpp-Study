#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, w, v, i, j;
	int dp[100001] = { 0 };
	
	cin >> N >> K;
	
	for(i = 0; i < N; i++) {
		cin >> w >> v;
		for(j = K; j >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[K];
	
	return 0;
}