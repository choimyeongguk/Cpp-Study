#include <bits/stdc++.h>
using namespace std;

bool used[26] = { false };
char board[20][20], d[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
int R, C;

int dfs(int r, int c) {
	int ret = 0, tmp = 0, nr, nc, i;
	for(i = 0; i < 4; i++) {
		nr = r + d[0][i];
		nc = c + d[1][i];
		if(0 <= nr&&nr < R && 0 <= nc&&nc < C && !used[board[nr][nc]]) {
			used[board[nr][nc]] = true;
			tmp = dfs(nr, nc);
			ret = ret > tmp ? ret : tmp;
			if(ret == 25) break;
			used[board[nr][nc]] = false;
		}
	}
	return ret + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char tmp;
	int i, j;
	
	cin >> R >> C;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> tmp;
			board[i][j] = tmp - 'A';
		}
	}
	used[board[0][0]] = true;
	cout << dfs(0, 0);
	
	return 0;
}