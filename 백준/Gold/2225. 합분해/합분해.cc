#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K, i, j;
	int dp[201] = { 0 };
	// int dp[201][201] = { 0 };
	// dp[i][j]=k : 0부터 N까지의 정수 i개를 더해서 그 합이 j이 되는 경우의 수 k
	
	cin >> N >> K;
	dp[0] = 1;
	for(i = 1; i <= K; i++) {
		for(j = 1; j <= N; j++) {
			dp[j] += dp[j - 1];
			dp[j] %= 1000000000;
		}
	}
	cout << dp[N];
		
	return 0;
}