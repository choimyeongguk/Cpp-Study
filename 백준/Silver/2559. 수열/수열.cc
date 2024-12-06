#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, sum = 0, ans, i;
	int temp[100001] = { 0 };
	
	cin >> N >> K;
	for(i = 1; i <= N; i++) {
		cin >> temp[i];
	}
	for(i = 1; i <= K; i++) {
		sum += temp[i];
	}
	ans = sum;
	int l = 1, r = K;
	while(r < N) {
		sum += temp[++r];
		sum -= temp[l++];
		ans = max(ans, sum);
	}
	cout << ans;
	
	return 0;
}