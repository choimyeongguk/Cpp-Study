#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, tmp, i, j;
	int dp[100001];
	dp[0] = 0;
	dp[1] = 1;
	for(i = 2; i <= 100000; i++) {
		tmp = 0x3f3f3f3f;
		for(j = 1; j * j <= i; j++) {
			tmp = min(tmp, 1 + dp[i - j * j]);
		}
		dp[i] = tmp;
	}
	cin >> N;
	cout << dp[N];
	
	return 0;
}