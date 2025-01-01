#include <bits/stdc++.h>
using namespace std;

int N, board[10][10], ans[2] = { 0 };
bool sum[19] = { false }, sub[19] = { false };

void back_track(int depth, int r, int c, int color) {
	if(c >= N) {
//		c %= N;
		r++;
		if(c % 2) c = 0;
		else c = 1;
	}
	if(r == N) {
		ans[color] = ans[color] > depth ? ans[color] : depth;
		return;
	}
	if(board[r][c] && !sum[r + c] && !sub[r - c + 9]) {
		sum[r + c] = true;
		sub[r - c + 9] = true;
		back_track(depth + 1, r, c + 2, color);
		sum[r + c] = false;
		sub[r - c + 9] = false;
	}
	back_track(depth, r, c + 2, color);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	back_track(0, 0, 0, 0);
	back_track(0, 0, 1, 1);
	cout << ans[0] + ans[1];
	
	return 0;
}