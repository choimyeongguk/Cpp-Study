#include <bits/stdc++.h>
using namespace std;

int R, C;
int m[50][50];

void dfs(int r, int c) {
	m[r][c] = 0;
	int nr, nc, i;
	int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	for(i = 0; i < 8; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if(nr < 0 || nr >= R || nc < 0 || nc >= C)
			continue;
		if(m[nr][nc])
			dfs(nr, nc);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int cnt, i, j;
	
	while(true) {
		cin >> C >> R;
		if(C == 0 && R == 0)
			break;
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				cin >> m[i][j];
			}
		}
		for(cnt = 0, i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(m[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}