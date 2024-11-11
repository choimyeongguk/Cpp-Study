#include <bits/stdc++.h>
using namespace std;

int N, M[101][101];
vector<vector<bool>> visited;

void dfs(int r, int c, int h) {
	visited[r][c] = true;
	char d[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
	int nr, nc;
	for(int i = 0; i < 4; i++) {
		nr = r + d[0][i];
		nc = c + d[1][i];
		if(0 <= nr&&nr < N && 0 <= nc&&nc < N && M[nr][nc] > h && !visited[nr][nc]) {
			dfs(nr, nc, h);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int min = 100, max = 1, cnt, ans, i, j, h;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			cin >> M[i][j];
			min = min < M[i][j] ? min : M[i][j];
			max = max > M[i][j] ? max : M[i][j];
		}
	}
	for(ans = 0, h = min - 1; h < max; h++) {
		visited.assign(N, vector<bool>(N, false));
		for(cnt = 0, i = 0; i < N; i++) {
			for(j = 0; j < N; j++) {
				if(M[i][j] > h && !visited[i][j]) {
					cnt++;
					dfs(i, j, h);
				}
			}
		}
		ans = ans > cnt ? ans : cnt;
	}
	cout << ans;
	
	return 0;
}