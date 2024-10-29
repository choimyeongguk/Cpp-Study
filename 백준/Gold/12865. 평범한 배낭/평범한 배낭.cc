#include <bits/stdc++.h>
using namespace std;

struct Stuff {
	int w, v;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, i, j;
	vector<Stuff> stuff;
	vector<vector<int>> dp;
	
	cin >> N >> K;
	
	stuff.assign(N + 1, {0, 0});
	for(i = 1; i <= N; i++) {
		cin >> stuff[i].w >> stuff[i].v;
	}
	
	dp.assign(K + 1, vector<int>(N + 1, 0));
	for(i = 1; i <= K; i++) {
		for(j = 1; j <= N; j++) {
			if(i >= stuff[j].w)
				dp[i][j] = max(dp[i][j - 1], stuff[j].v + dp[i - stuff[j].w][j - 1]);
			else
				dp[i][j] = dp[i][j - 1];	
		}
	}
	cout << dp[K][N];
	
	return 0;
}