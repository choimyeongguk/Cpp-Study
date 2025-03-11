#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans, i, j, k, l;
	int dp[101][10][1 << 10] = { 0 };
	// dp[i][j][k(2)] = l
	// 길이 i이고 j로 끝나며, k와 같이 사용된 계단 수 개수 l
	 
	cin >> N;
	
	for(i = 1; i < 10; i++)
		dp[1][i][1 << i] = 1;
		
	for(i = 2; i <= N; i++) {
		for(j = 0; j < 10; j++) {
			for(k = 0; k < 1 << 10; k++) {
				l = k | 1 << j;
				if(j == 0)
					dp[i][j][l] = (dp[i][j][l] + dp[i - 1][j + 1][k]) % MOD;
				else if(j == 9)
					dp[i][j][l] = (dp[i][j][l] + dp[i - 1][j - 1][k]) % MOD;
				else
					dp[i][j][l] = (dp[i][j][l] + dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]) % MOD;
			}
		}
	}
	
	for(ans = 0, i = 0; i < 10; i++) {
		ans = (ans + dp[N][i][1023]) % MOD;
	}
	cout << ans;
	
	return 0;
}