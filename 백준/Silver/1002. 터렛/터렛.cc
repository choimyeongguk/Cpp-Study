#include <bits/stdc++.h>
using namespace std;

int solve() {
	int x1, y1, r1, x2, y2, r2, l, t1, t2;

	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	l = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	
	if(x1 == x2 && y1 == y2) {
		if(r1 == r2) return -1;
		else return 0;
	} else {
		t1 = (r1 + r2) * (r1 + r2);
		t2 = (r1 - r2) * (r1 - r2);
		if(l > t1 || l < t2) return 0;
		else if(l == t1 || l == t2) return 1;
		else return 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) cout << solve() << "\n";
	
	return 0;
}