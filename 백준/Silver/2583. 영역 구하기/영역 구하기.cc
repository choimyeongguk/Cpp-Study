#include <bits/stdc++.h>
using namespace std;

int R, C;
int d[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
vector<vector<bool>> paper;

int dfs(int r, int c) {
	paper[r][c] = false;
	int ret = 1, nr, nc, i;
	for(i = 0; i < 4; i++) {
		nr = r + d[0][i];
		nc = c + d[1][i];
		if(nr < 0 || nr >= R || nc < 0 || nc >= C || !paper[nr][nc])
			continue;
		ret += dfs(nr, nc);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int K, c1, r1, c2, r2, i, j, k;
	vector<int> area;
	
	cin >> R >> C >> K;
	paper.assign(R, vector<bool>(C, true));
	for(i = 0; i < K; i++) {
		cin >> c1 >> r1 >> c2 >> r2;
		
		for(j = r1; j < r2; j++) {
			for(k = c1; k < c2; k++) {
				paper[j][k] = false;
			}
		}
	}

	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(paper[i][j]) {
				area.push_back(dfs(i, j));
			}
		}
	}
	sort(area.begin(), area.end());
	cout << area.size() << "\n";
	for(i = 0; i < area.size(); i++)
		cout << area[i] << " ";
	
	return 0;
}