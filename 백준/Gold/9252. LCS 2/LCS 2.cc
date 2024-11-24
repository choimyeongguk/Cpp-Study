#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i, j;
	string A, B;
	int dp[1001][1001] = { 0 };
	stack<char> S;
	
	cin >> A >> B;
	
	for(i = 1; i <= B.size(); i++) {
		for(j = 1; j <= A.size(); j++) {
			if(B[i - 1] == A[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	cout << dp[B.size()][A.size()] << "\n";
	i = B.size(), j = A.size();
	while(i > 0 && j > 0) {
		if(B[i - 1] == A[j - 1]) {
			S.push(A[j - 1]);
			i--, j--;
		} else {
			dp[i - 1][j] > dp[i][j - 1] ? i-- : j--;
		}
	}
	while(!S.empty()) {
		cout << S.top();
		S.pop();
	}
	
	return 0;
}