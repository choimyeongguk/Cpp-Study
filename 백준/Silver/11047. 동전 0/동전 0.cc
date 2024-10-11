#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, cnt = 0, i;
	vector<int> coin;
	
	cin >> N >> K;
	coin.assign(N, 0);
	for(i = coin.size() - 1; i >= 0; i--) {
		cin >> coin[i];
	}
	for(i = 0; i < N; i++) {
		cnt += K / coin[i];
		K %= coin[i];
	}
	cout << cnt;
	
	return 0;
}