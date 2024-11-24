#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i, j;
	string A, B;
	vector<vector<pair<int,pair<int,int>>>> dp;
	stack<char> S;
	
	cin >> A >> B;
	dp.assign(B.size() + 1, vector<pair<int,pair<int,int>>>(A.size() + 1, {0, {0, 0}}));
	
	for(i = 1; i <= B.size(); i++) {
		for(j = 1; j <= A.size(); j++) {
			if(B[i - 1] == A[j - 1]) {
				dp[i][j] = {dp[i - 1][j - 1].first + 1, {i - 1, j - 1}};
			} else if(dp[i - 1][j].first > dp[i][j - 1].first) {
				dp[i][j] = {dp[i - 1][j].first, {i - 1, j}};
			} else {
				dp[i][j] = {dp[i][j - 1].first, {i, j - 1}};
			}
		}
	}
	
	cout << dp[B.size()][A.size()].first << "\n";
	pair<int,int> idx = { B.size(), A.size() };
	while(idx.first > 0 && idx.second > 0) {
		if(B[idx.first - 1] == A[idx.second - 1]) {
			S.push(A[idx.second - 1]);
		}
		idx = dp[idx.first][idx.second].second;
	}
	while(!S.empty()) {
		cout << S.top();
		S.pop();
	}
	
	return 0;
}