#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> image;
vector<vector<bool>> visited;
int N;
char d[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};

void dfs1(int r, int c) {
	int nr, nc;
	for(int i = 0; i < 4; i++) {
		nr = r + d[i][0];
		nc = c + d[i][1];
		if(0<=nr&&nr<N && 0<=nc&&nc<N && !visited[nr][nc] && image[r][c] == image[nr][nc]) {
			visited[nr][nc] = true;
			dfs1(nr, nc);
		}
	}
}

void dfs2(int r, int c) {
	int nr, nc;
	for(int i = 0; i < 4; i++) {
		nr = r + d[i][0];
		nc = c + d[i][1];
		if(0<=nr&&nr<N && 0<=nc&&nc<N && !visited[nr][nc]) {
			if(image[r][c] != 'B' && image[nr][nc] != 'B') {
				visited[nr][nc] = true;
				dfs2(nr, nc);
			} else if(image[r][c] == 'B' && image[nr][nc] == 'B'){
				visited[nr][nc] = true;
				dfs2(nr, nc);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int ans1, ans2, i, j;
	
	cin >> N;
	image.resize(N, vector<char>(N));
	for(auto& r : image) {
		for(auto& c : r) {
			cin >> c;
		}
	}
	
	visited.assign(N, vector<bool>(N, false));
	for(ans1 = 0, i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(!visited[i][j]) {
				visited[i][j] = true;
				dfs1(i, j);
				ans1++;
			}
		}
	}
	
	visited.assign(N, vector<bool>(N, false));
	for(ans2 = 0, i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(!visited[i][j]) {
				visited[i][j] = true;
				dfs2(i, j);
				ans2++;
			}
		}
	}
	
	cout << ans1 << " " << ans2;
	
	return 0;
}