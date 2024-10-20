#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j, k;
	cin >> n;
	for(i = 0; i * i <= n; i++) {
		for(j = i; j * j <= n; j++) {
			for(k = j; k * k <= n; k++) {
				if(i * i + j * j + k * k == n) {
					cout << 3 - !i - !j;
					return 0;
				}
			}
		}
	}
	cout << 4;
	return 0;
}