#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int R, C, ans = 0, nr, nc, i, j;
	int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
	vector<vector<char>> campus;
	queue<pair<int,int>> bfs;
	
	cin >> R >> C;
	campus.resize(R, vector<char>(C));
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> campus[i][j];
			if(campus[i][j] == 'I') {
				bfs.push({i, j});
				campus[i][j] = 0;
			}
		}
	}
	while(!bfs.empty()) {
		int& r = bfs.front().first;
		int& c = bfs.front().second;
		for(i = 0; i < 4; i++) {
			nr = r + d[i][0];
			nc = c + d[i][1];
			if(0 <= nr&&nr < R && 0 <= nc&&nc < C && campus[nr][nc] != 'X') {
				if(campus[nr][nc] == 'P') ans++;
				campus[nr][nc] = 'X';
				bfs.push({nr, nc});
			}
		}
		bfs.pop();
	}
	if(ans) {
		cout << ans;
	} else {
		cout << "TT";
	}
	
	return 0;
}