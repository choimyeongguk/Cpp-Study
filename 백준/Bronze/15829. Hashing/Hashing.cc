#include <bits/stdc++.h>
using namespace std;

int main() {
	int L, r = 31, M = 1234567891;
	long long int H = 0, a;
	
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