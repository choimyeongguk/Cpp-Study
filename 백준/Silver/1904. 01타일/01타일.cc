#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, i, dp[1000001];
	dp[1] = 1, dp[2] = 2;
	for(i = 3; i <= 1000000; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	cin >> N;
	cout << dp[N];
	return 0;
}