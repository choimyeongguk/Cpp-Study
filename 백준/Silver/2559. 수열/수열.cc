#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, ans = -0x3f3f3f3f, i;
	int temp[100001] = { 0 };
	
	cin >> N >> K >> temp[1];
	for(i = 2; i <= N; i++) {
		cin >> temp[i];
		temp[i] += temp[i - 1];
	}
	for(i = K; i <= N; i++) {
		ans = max(ans, temp[i] - temp[i - K]);
	}
	cout << ans;
	
	return 0;
}