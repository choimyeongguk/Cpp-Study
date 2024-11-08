#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i;
	int T[16], P[16], dp[17] = { 0 };
	
	cin >> N;
	for(i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for(i = N; i > 0; i--) {
		if(i + T[i] - 1 > N) {
			dp[i] = dp[i + 1];
		} else {
			dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
		}
	}
	cout << dp[1];
	
	return 0;
}