#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, P[1001], i, j;
	int dp[1001] = { 0 };
	
	cin >> N;
	for(i = 1; i <= N; i++)
		cin >> P[i];
		
	// dp[i] = j : i장을 갖기 위해 지불해야 하는 최대금액 j 
	for(i = 1; i <= N; i++)
		for(j = 1; j <= i; j++)
			if(dp[i] < dp[i - j] + P[j])
				dp[i] = dp[i - j] + P[j];
				
	cout << dp[N];
	
	return 0;
}