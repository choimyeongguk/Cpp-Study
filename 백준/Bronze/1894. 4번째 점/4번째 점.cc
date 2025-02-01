#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	double x1, y1, x2, y2, x3, y3, x4, y4, tmp;
	
	while(true) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		if(cin.eof()) break;
		if(x1 == x3 && y1 == y3) {
			x3 = x4, y3 = y4;
			tmp = x1, x1 = x2, x2 = tmp;
			tmp = y1, y1 = y2, y2 = tmp;
		}
		else if(x1 == x4 && y1 == y4) {
			tmp = x1, x1 = x2, x2 = tmp;
			tmp = y1, y1 = y2, y2 = tmp;
		}
		else if(x2 == x3 && y2 == y3) {
			x3 = x4, y3 = y4;
		}
		
		cout << fixed << setprecision(3) << x1 + x3 - x2 << " " << y1 + y3 - y2 << "\n";
	}
	
	return 0;
}