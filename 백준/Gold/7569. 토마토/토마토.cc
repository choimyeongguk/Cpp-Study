#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int H, R, C, numZero = 0, day = 1, i, j, k;
	int h, r, c, nh, nr, nc;
	char d[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
	vector<vector<vector<int>>> tomato;
	queue<tuple<int,int,int>> bfs;
	
	cin >> C >> R >> H;
	tomato.assign(H, vector<vector<int>>(R, vector<int>(C, 0)));
	for(i = 0; i < H; i++) {
		for(j = 0; j < R; j++) {
			for(k = 0; k < C; k++) {
				cin >> tomato[i][j][k];
				if(tomato[i][j][k] == 1) {
					bfs.push(tie(i, j, k));
				}
				if(tomato[i][j][k] == 0) {
					numZero++;
				}
			}
		}
	}
	
	while(!bfs.empty()) {
		h = get<0>(bfs.front());
		r = get<1>(bfs.front());
		c = get<2>(bfs.front());
		bfs.pop();
		
		for(i = 0; i < 6; i++) {
			nh = h + d[i][0];
			nr = r + d[i][1];
			nc = c + d[i][2];
			if(0<=nh&&nh<H && 0<=nr&&nr<R && 0<=nc&&nc<C && !tomato[nh][nr][nc]) {
				bfs.push(tie(nh, nr, nc));
				tomato[nh][nr][nc] = tomato[h][r][c] + 1;
				day = tomato[nh][nr][nc];
				numZero--;
			}
		}
	}
	
	if(numZero) {
		cout << -1;
	} else {
		cout << day - 1;
	}
	
	return 0;
}