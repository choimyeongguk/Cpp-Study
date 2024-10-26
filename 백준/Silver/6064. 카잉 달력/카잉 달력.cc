#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if(!y) return x;
	return gcd(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk;
	int T, M, N, x, y, lastYear, nx, ny, i;
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> M >> N >> x >> y;
		lastYear = M * N / gcd(M, N);
		nx = x, ny = y;
		chk = true;
		while(nx != ny) {
			while(nx < ny) nx += M;
			while(nx > ny) ny += N;
			//nx < ny ? (nx += M) : (ny += N);
			if(nx > lastYear || ny > lastYear) {
				chk = false;
				break;
			}
		}
		cout << (chk ? nx : -1) << "\n";
	}
	
	return 0;
}