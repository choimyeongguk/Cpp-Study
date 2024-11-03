#include <bits/stdc++.h>
using namespace std;

int comb(int m, int n) {  // mCn
	int ret = 1, i, j = 1;
	for(i = m; i > m - n; i--) {
		ret *= i;
		ret /= j++;
	}
	return ret;
}

void solve() {
	int N, M;
	cin >> N >> M;
	cout << comb(M, N) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	
	return 0;
}