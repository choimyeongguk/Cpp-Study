#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int step, prev, ans, i, j;
	int cost[5][5]={
		{1, 2, 2, 2, 2},
    	{2, 1, 3, 4, 3},
    	{2, 3, 1, 3, 4},
    	{2, 4, 3, 1, 3},
    	{2, 3, 4, 3, 1}
	};
	int dp[5][5];
	for(i = 0; i < 5; i++)
		for(j = 0; j < 5; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	queue<pair<int,pair<int,int>>> q;
	
	prev = 0;
	while(true) {
		cin >> step;
		if(!step) break;
		
		for(i = 0; i < 5; i++) {
			q.push({dp[i][prev], {i, prev}});
			dp[i][prev] = INF;
			q.push({dp[prev][i], {prev, i}});
			dp[prev][i] = INF;
		}
		prev = step;
		
		while(!q.empty()) {
			int& n = q.front().first;
			int& l = q.front().second.first;
			int& r = q.front().second.second;
			
			dp[step][r] = min(dp[step][r], n + cost[l][step]);
			dp[l][step] = min(dp[l][step], n + cost[r][step]);
			q.pop();
		}
	}
	for(ans = INF, i = 0; i < 5; i++) {
		for(j = 0; j < 5; j++) {
			ans = min(ans, dp[i][j]);
		}
	}
	cout << ans;
	
	return 0;
}