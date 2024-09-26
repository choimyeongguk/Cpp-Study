#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, k, n, i, j;
	int apart[15][15] = { 0 };
	
	for(i = 1; i <= 14; i++) {
		apart[0][i] = i;
		apart[i][1] = 1;
	}
	apart[0][1] = 1;
	
	for(i = 1; i <= 14; i++) {
		for(j = 2; j <= 14; j++) {
			apart[i][j] = apart[i][j-1] + apart[i-1][j];
		}
	}
	
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> k >> n;
		cout << apart[k][n] << '\n';
	}
	
	return 0;
}