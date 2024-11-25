#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, N, ans = 0, i, x, y;
	cin >> T;
	while(T--) {
		cin >> x >> y;
		
		N = y - x;
		for(ans = 0, i = 1; N > 0; i++) {
			N -= 2 * i;
			ans += 2;
		}
		if(N < 0) {
			N += 2 * --i;
			ans -= 2;
			if(N > i) ans += 2;
			else ans += 1;
		}
		cout << ans << "\n";
	}
	
	return 0;
} 