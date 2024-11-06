#include <bits/stdc++.h>
using namespace std;

bool used[26] = { false };
char board[20][20], d[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
int R, C, ans = 0;

void dfs(int r, int c, int depth) {
	int nr, nc, i;
	ans = ans > depth ? ans : depth;
	for(i = 0; i < 4; i++) {
		nr = r + d[0][i];
		nc = c + d[1][i];
		if(0 <= nr&&nr < R && 0 <= nc&&nc < C && !used[board[nr][nc]]) {
			used[board[nr][nc]] = true;
			dfs(nr, nc, depth + 1);
			used[board[nr][nc]] = false;
		}
	}
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
	dfs(0, 0, 1);
	cout << ans;
	
	return 0;
}