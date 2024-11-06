#include <bits/stdc++.h>
using namespace std;

char board[20][20], d[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
int visited[20][20];
int R, C;

int dfs(int r, int c, int used) {
	used |= (1 << board[r][c]);
	if(visited[r][c] == used) return 0;
	visited[r][c] = used;
	
	int ret = 0, tmp = 0, nr, nc, i;
	for(i = 0; i < 4; i++) {
		nr = r + d[0][i];
		nc = c + d[1][i];
		if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		if(!(used & (1 << board[nr][nc]))) {
			tmp = dfs(nr, nc, used);
			ret = ret > tmp ? ret : tmp;
			if(ret == 25) break;
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
	cout << dfs(0, 0, 0);
	
	return 0;
}