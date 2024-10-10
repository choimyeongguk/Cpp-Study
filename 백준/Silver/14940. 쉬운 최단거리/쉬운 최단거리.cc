#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int R, C, r, c, tr, tc, i, j;
	int d[4][2] = {{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};
	vector<vector<int>> map;
	queue<pair<int,int>> bfs;
	
	cin >> R >> C;
	map.assign(R, vector<int>(C, 0));
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> map[i][j];
			if(map[i][j] == 2) bfs.push({ i, j });
			if(map[i][j]) map[i][j] -= 2;
		}
	}
	
	while(!bfs.empty()) {
		r = bfs.front().first;
		c = bfs.front().second;
		bfs.pop();
		for(i = 0; i < 4; i++) {
			tr = r + d[i][0];
			tc = c + d[i][1];
			if(0 <= tr && tr < R && 0 <= tc && tc < C && map[tr][tc] < 0) {
				map[tr][tc] = map[r][c] + 1;
				bfs.push({ tr, tc });
			}
		}
	}
	
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}