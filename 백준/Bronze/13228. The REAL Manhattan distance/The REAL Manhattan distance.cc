#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, x1, y1, z1, x2, y2, z2;
	
	cin >> T;
	while(T--) {
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		cout << z1 + z2 + abs(x2 - x1) + abs(y2 - y1) << "\n";
	}
	
	return 0;
}