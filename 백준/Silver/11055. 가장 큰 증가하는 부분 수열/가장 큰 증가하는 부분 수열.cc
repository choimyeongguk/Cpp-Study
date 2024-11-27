#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans = 0, max, i, j;
	int A[1001], dp[1001];
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> A[i];
	}
	for(i = 0; i < N; i++) {
		max = 0;
		for(j = 0; j < i; j++) {
			if(A[j] < A[i] && max < dp[j])
				max = dp[j];
		}
		dp[i] = A[i] + max;
		ans = ans > dp[i] ? ans : dp[i];
	}
	cout << ans;
	
	return 0;
}