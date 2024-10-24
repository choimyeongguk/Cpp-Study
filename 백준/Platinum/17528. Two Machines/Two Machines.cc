#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, sum, tmp, ans, i, j;
	vector<int> a;
	vector<int> b;
	vector<int> dp;  // dp[i] = j : a가 i 일할 때, b는 j 일함 
	
	cin >> n;
	
	a.resize(n);
	b.resize(n);
	for(sum = 0, i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	
	dp.assign(sum + 1, INF);
	dp[sum] = 0;
	for(i = 0; i < n; i++) {
		for(j = a[i]; j <= sum; j++) {
			if(dp[j] != INF)
				dp[j - a[i]] = min(dp[j - a[i]], dp[j] + b[i]);
		}
	}
	
	ans = INF;
	for(i = 0; i <= sum; i++) {
		tmp = max(i, dp[i]);
		if(ans > tmp) ans = tmp;
	}
	cout << ans;
	
	return 0;
}