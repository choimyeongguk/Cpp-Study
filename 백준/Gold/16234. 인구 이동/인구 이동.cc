#include <bits/stdc++.h>
using namespace std;

int d[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
int N, L, R, sum;
int area[50][50];
bool visited[50][50];
vector<pair<int,int>> alliance;

void dfs(int r, int c) {
	int nr, nc, tmp, i;
	visited[r][c] = true;
	sum += area[r][c];
	alliance.push_back({ r, c });
	for(i = 0; i < 4; i++) {
		nr = r + d[0][i];
		nc = c + d[1][i];
		if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])
			continue;
		tmp = abs(area[r][c] - area[nr][nc]);
		if(L <= tmp && tmp <= R)
			dfs(nr, nc);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk;
	int T = 0, avg, i, j;
	
	cin >> N >> L >> R;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			cin >> area[i][j];
		}
	}
	
	while(++T) {
		chk = true;
		for(i = 0; i < N; i++) {
			for(j = 0; j < N; j++) {
				if(visited[i][j])
					continue;
				
				sum = 0;
				alliance.clear();
				dfs(i, j);
				
				if(alliance.size() == 1)
					continue;
									
				avg = sum / alliance.size();
				for(auto& e : alliance) {
					if(area[e.first][e.second] != avg)
						chk = false;
					area[e.first][e.second] = avg;
				}
			}
		}
		for(i = 0; i < N; i++) {
			for(j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}
		if(chk)
			break;
	}
	cout << --T;
	
	return 0;
}