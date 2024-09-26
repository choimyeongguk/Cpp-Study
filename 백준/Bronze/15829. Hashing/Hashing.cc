#include <bits/stdc++.h>
using namespace std;

int main() {
	int L, H = 0;
	int a, r = 31, M = 1234567891;
	
	cin >> L;
	getchar();
	for(int i = 0; i < L; i++) {
		a = getchar() - 'a' + 1;
		for(int j = 0; j < i; j++) {
			a *= r;
			a %= M;
		}
		H += a;
		H %= M;
	}
	cout << H;
	
	return 0;
}