#include <bits/stdc++.h>
using namespace std;

int R, C, ans = 0;
int d[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
vector<vector<short>> paper;
vector<vector<bool>> visited;

void dfs(int r, int c, int depth, int val) {
	if(depth == 4) {
		if(ans < val) ans = val;
		return;
	}
	visited[r][c] = true;
	int nr, nc, i;
	for(i = 0; i < 4; i++) {
		nr = r + d[i][0];
		nc = c + d[i][1];
		if(0 <= nr&&nr < R && 0 <= nc&&nc < C && !visited[nr][nc]) {
			visited[nr][nc] = true;
			dfs(nr, nc, depth + 1, val + paper[nr][nc]);
			visited[nr][nc] = false;
		}
	}
	visited[r][c] = false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int tmp, i, j;
	
	cin >> R >> C;
	paper.resize(R, vector<short>(C));
	for(auto& r : paper) {
		for(auto& c : r) {
			cin >> c;
		}
	}
	
	visited.assign(R, vector<bool>(C, false));
	for(ans = 0, i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			dfs(i, j, 1, paper[i][j]);
		}
	}
	
	for(i = 0; i < R - 1; i++) {  // ㅜ 
		for(j = 1; j < C - 1; j++) {
			tmp = paper[i][j] + paper[i + 1][j] + paper[i][j - 1] + paper[i][j + 1];
			if(ans < tmp) ans = tmp;
		}
	}
	for(i = 1; i < R - 1; i++) {  // ㅓ 
		for(j = 1; j < C; j++) {
			tmp = paper[i][j] + paper[i + 1][j] + paper[i][j - 1] + paper[i - 1][j];
			if(ans < tmp) ans = tmp;
		}
	}
	for(i = 1; i < R; i++) {  // ㅗ 
		for(j = 1; j < C - 1; j++) {
			tmp = paper[i][j] + paper[i - 1][j] + paper[i][j - 1] + paper[i][j + 1];
			if(ans < tmp) ans = tmp;
		}
	}
	for(i = 1; i < R - 1; i++) {  // ㅏ 
		for(j = 0; j < C - 1; j++) {
			tmp = paper[i][j] + paper[i - 1][j] + paper[i][j + 1] + paper[i + 1][j];
			if(ans < tmp) ans = tmp;
		}
	}
	
	cout << ans; 
	
	return 0;
}