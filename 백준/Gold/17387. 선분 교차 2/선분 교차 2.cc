#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll det(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	x2 -= x1, y2 -= y1, x3 -= x1, y3 -= y1;
	ll ret = x2 * y3 - x3 * y2;
	return ret == 0 ? 0 : ret > 0 ? 1 : -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	ll d1, d2, d3, d4, p1, p2;
	ll tx1, ty1, tx2, ty2;
	
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	
	d1 = det(x1, y1, x2, y2, x3, y3);
	d2 = det(x1, y1, x2, y2, x4, y4);
	d3 = det(x3, y3, x4, y4, x1, y1);
	d4 = det(x3, y3, x4, y4, x2, y2);
	
	p1 = d1 * d2;
	p2 = d3 * d4;
	
	if(p1 < 0 && p2 < 0) cout << 1;
	else if(p1 == 0 || p2 == 0) {
		if(d1 == 0 || d2 == 0) {
			tx1 = (x1 < x2 ? x1 : x2), ty1 = (y1 < y2 ? y1 : y2);
			tx2 = (x1 > x2 ? x1 : x2), ty2 = (y1 > y2 ? y1 : y2);
			if(d1 == 0 && (tx1 <= x3 && x3 <= tx2 && ty1 <= y3 && y3 <= ty2)) {
				cout << 1;
				return 0;
			}
			if(d2 == 0 && (tx1 <= x4 && x4 <= tx2 && ty1 <= y4 && y4 <= ty2)) {
				cout << 1;
				return 0;
			}
		}
		if(d3 == 0 || d4 == 0) {
			tx1 = (x3 < x4 ? x3 : x4), ty1 = (y3 < y4 ? y3 : y4);
			tx2 = (x3 > x4 ? x3 : x4), ty2 = (y3 > y4 ? y3 : y4);
			if(d3 == 0 && (tx1 <= x1 && x1 <= tx2 && ty1 <= y1 && y1 <= ty2)) {
				cout << 1;
				return 0;
			}
			if(d4 == 0 && (tx1 <= x2 && x2 <= tx2 && ty1 <= y2 && y2 <= ty2)) {
				cout << 1;
				return 0;
			}
		}
		cout << 0;
	}
	else cout << 0;
	
	return 0;
}