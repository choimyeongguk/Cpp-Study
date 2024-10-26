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
	int T, M, N, x, y, lastYear, Q1, Q2, k1, k2, i;
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> M >> N >> x >> y;
		lastYear = M * N / gcd(M, N);
		Q1 = 0, Q2 = 0;
		k1 = M * Q1 + x;
		k2 = N * Q2 + y;
		chk = true;
		while(k1 != k2) {
			if(k1 < k2) Q1++;
			else Q2++;
			k1 = M * Q1 + x;
			k2 = N * Q2 + y;
			if(k1 > lastYear || k2 > lastYear) {
				chk = false;
				break;
			}
		}
		cout << (chk ? k1 : -1) << "\n";
	}
	
	return 0;
}