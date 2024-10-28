#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int ans = 0;
	string s1, s2;
	int dp[1001][1001] = { 0 };
	
	cin >> s1 >> s2;
	for(int i = 1; i <= s1.length(); i++) {
		for(int j = 1; j <= s2.length(); j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if(s1[i - 1] == s2[j - 1]) {
				dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	
	return 0;
}