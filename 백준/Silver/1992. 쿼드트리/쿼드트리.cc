#include <bits/stdc++.h>
using namespace std;

char image[64][64];
string ans;

void quadTree(int r, int c, int N) {
	bool chk = true;
	for(int i = r; i < r + N; i++) {
		for(int j = c; j < c + N; j++) {
			if(image[i][j] != image[r][c]) {
				chk = false;
				break;
			}
		}
		if(!chk)
			break;
	}
	if(chk)
		ans += image[r][c];
	else {
		ans += '(';
		quadTree(r, c, N / 2);
		quadTree(r, c + N / 2, N / 2);
		quadTree(r + N / 2, c, N / 2);
		quadTree(r + N / 2, c + N / 2, N / 2);
		ans += ')';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> image[i][j];
		}
	}
	quadTree(0, 0, N);
	cout << ans;
	
	return 0;
}