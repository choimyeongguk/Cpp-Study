#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i;
	bool dp[1001][2];	// dp[i][0] : 상근이가 지도록 만들 수 있음. 
						// dp[i][1] : 상근이가 이기도록 만들 수 있음.
	
	dp[1][0] = false, dp[1][1] = true;
	dp[2][0] = true, dp[2][1] = false;
	dp[3][0] = false, dp[3][1] = true;
	
	for(i = 4; i <= 1000; i++) {
		// 상근(선수)입장 :  dp[i - 1] 또는 dp[i - 3]를 패배로 만들어야 함. 
		// 상근이는 dp[i - 1]또는 dp[i - 3]을 패배로 만들 수 있는가? 
		dp[i][0] = dp[i - 1][1] || dp[i - 3][1];
		dp[i][1] = dp[i - 1][0] || dp[i - 3][0];
	}

	cin >> N;
	if(dp[N][1]) {
		cout << "SK";
	} else cout << "CY";
	
	return 0;
}