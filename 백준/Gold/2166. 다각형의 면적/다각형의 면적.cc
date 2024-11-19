#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i;
	double area = 0, x0, y0, x1, y1, x2, y2;
	
	cin >> N;
	cin >> x0 >> y0;
	cin >> x1 >> y1;
	x1 -= x0, y1 -= y0;
	for(i = 2; i < N; i++) {
		cin >> x2 >> y2;
		x2 -= x0, y2 -= y0;
		area += (x1 * y2 - x2 * y1) / 2;
		x1 = x2;
		y1 = y2;
	}
	cout << fixed << setprecision(1) << abs(area);
	
	return 0;
}