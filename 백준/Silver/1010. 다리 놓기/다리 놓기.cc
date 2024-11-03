#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll comb(int m, int n) {  // mCn
	int i, j = m - n;
	ll ret = 1;
	for(i = m; i > n; i--) {
		ret *= i;
		while(j > 0 && ret % j == 0) {
			ret /= j;
			j--;
		}
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