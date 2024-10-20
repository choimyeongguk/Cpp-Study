#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main() {
	int i, j, n, min, tmp;
	int dp[50001] = { 0 };
	
	for(i = 1; i * i <= 50000; i++) {
		dp[i * i] = 1;
	}
	for(i = 2; i <= 50000; i++) {
		if(dp[i]) continue;
		min = INF;
		for(j = 1; j<<1 <= i; j++) {
			tmp = dp[j] + dp[i - j];
			if(min > tmp) min = tmp;
		}
		dp[i] = min;
	}
	
	cin >> n;
	cout << dp[n];
	
	return 0;
}