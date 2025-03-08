#include <bits/stdc++.h>
#define MAX 1732050809
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	long long N, l, r, m, n, ans;
	
	cin >> N;
	l = 1, r = MAX;
	while(l <= r) {
		m = (l + r) / 2;
		n = 1 + 3 * m * (m - 1);
		if(N < n) {
			r = m - 1;
			ans = m;
		}
		else if(N > n) {
			l = m + 1;
			ans = l;
		}
		else {
			ans = m;
			break;
		}
	}
	cout << ans;
	
	return 0;
}