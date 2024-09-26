#include <bits/stdc++.h>
using namespace std;

int main() {
	int R, C, min, cnt, r, c, i, j;
	char table[50][50];
	
	cin >> R >> C;
	getchar();
	for(r = 0; r < R; r++) {
		for(c = 0; c < C; c++) {
			table[r][c] = getchar()=='B' ? 0 : 1;
		}
		getchar();
	}
	
	min = R * C;
	for(r = 0; r < R-7; r++) {
		for(c = 0; c < C-7; c++) {
			cnt = 0;
			for(i = 0; i < 8; i++) {
				for(j = 0; j < 8; j++) {
					if(table[r+i][c+j] == (i + j)%2) {
						cnt++;
					}
				}
			}
			cnt = cnt < 32 ? cnt : 64-cnt;
			min = min < cnt ? min : cnt;
			if(min == 0) {
				cout << 0;
				return 0;
			}
		}
	}
	cout << min;
	
	return 0;
}