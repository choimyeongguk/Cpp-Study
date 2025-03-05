#include <bits/stdc++.h>
using namespace std;

int R, C, ans = 0;
char M[10000][500];

bool link(int r, int c) {
	M[r][c] = 'O';
	if(c == C - 1) {
		ans++;
		return true;
	}
	if(r > 0 && M[r - 1][c + 1] == '.') {
		if(link(r - 1, c + 1)) {
			return true;
		}
	}
	if(M[r][c + 1] == '.') {
		if(link(r, c + 1)) {
			return true;
		}
	}
	if(r < R - 1 && M[r + 1][c + 1] == '.') {
		if(link(r + 1, c + 1)) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i, j;
	
	cin >> R >> C;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> M[i][j];
		}
	}
	
	for(i = 0; i < R; i++) {
		link(i, 0);
	}
	
//	for(i = 0; i < R; i++) {
//		for(j = 0; j < C; j++) {
//			cout << M[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	cout << ans;
	
	
	
	return 0;
}