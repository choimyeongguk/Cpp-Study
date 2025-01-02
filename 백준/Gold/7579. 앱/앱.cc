#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, i, j;
	int m[101], c[101], dp[10100] = { 0 };
	// dp[i] = j : i비용을 들여 지울 수 있는 최대 메모리 j 
	
	cin >> N >> M;
	for(i = 0; i < N; i++) cin >> m[i];
	for(i = 0; i < N; i++) cin >> c[i];

	for(i = 0; i < N; i++) {
		for(j = 10000; j >= 0; j--) {
			dp[j + c[i]] = max(dp[j + c[i]], dp[j] + m[i]);
		}
	}
	for(i = 0; i <= 10000; i++) {
		if(dp[i] >= M)
			break;
	}
	cout << i;
	
	return 0;
} 