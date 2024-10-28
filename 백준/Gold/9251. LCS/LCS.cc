#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int tmp, prev;
	int dp[1001] = { 0 };
	string A, B;
	
	cin >> A >> B;

	for(int i = 1; i <= B.length(); i++) {
		prev = 0;
		for(int j = 1; j <= A.length(); j++) {
			tmp = dp[j];
			if(A[j - 1] == B[i - 1])
				dp[j] = prev + 1;
			else
				dp[j] = max(dp[j], dp[j - 1]);
			prev = tmp;
		}
	}
	cout << dp[A.length()];

	return 0;
}