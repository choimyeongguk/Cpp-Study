#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x1, y1, x2, y2, n, cx, cy, r, d1, d2, ans = 0, i;
	
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	for(i = 0; i < n; i++) {
		cin >> cx >> cy >> r;
		r *= r;
		d1 = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
		d2 = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2);
		
		if((d1 > r && d2 < r) || (d1 < r && d2 > r))
			ans++;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--)
		solve();
	
	return 0;
}