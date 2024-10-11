#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<bool>> field;
char d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int r, int c) {
	field[r][c] = false;
	for(int i = 0; i < 4; i++) {
		int nr = r + d[i][0];
		int nc = c + d[i][1];
		if(0<=nr&&nr<R && 0<=nc&&nc<C && field[nr][nc]) {
			dfs(nr, nc);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, K, cnt, r, c, i, j, k;
	
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> C >> R >> K;
		field.assign(R, vector<bool>(C, false));
		for(j = 0; j < K; j++) {
			cin >> c >> r;
			field[r][c] = true;
		}
		cnt = 0;
		for(j = 0; j < R; j++) {
			for(k = 0; k < C; k++) {
				if(field[j][k]) {
					dfs(j, k);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;
}