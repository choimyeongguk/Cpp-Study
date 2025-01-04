#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, a, b, l, i, j;
	int dp[501][501] = { 0 };
	// 행렬의 곱셈 [a * b][b * c][c * d]...는 a b c...의 수열로 나타낼 수 있음 
	// dp[i][j] = k : i번 부터 j번 값의 연산 횟수의 최솟값 k 
	int len[501];
	
	cin >> N >> len[0] >> len[1];
	for(i = 2; i <= N; i++) {
		cin >> a >> len[i];
	}
	
	for(l = 2 ; l <= N + 1 ; l++) {
        for(i = 0 ; i + l <= N ; i++) {
        	dp[i][i + l] = len[i] * len[i + 1] * len[i + l] + dp[i + 1][i + l];
        	for(j = i + 2; j < i + l; j++)
        		dp[i][i + l] = min(dp[i][i + l], len[i] * len[j] * len[i + l] + dp[i][j] + dp[j][i + l]);
        }
    }
	
	cout << dp[0][N];
	
	return 0;
}