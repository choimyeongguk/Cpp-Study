#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, tmp, i, j;
	int dp[100001] = { 0 };
	for(i = 1; i <= 100000; i++) {
		tmp = 100;
		for(j = 1; j * j <= i; j++) {
			tmp = min(tmp, 1 + dp[i - j * j]);
		}
		dp[i] = tmp;
	}
	cin >> N;
	cout << dp[N];
	
	return 0;
}