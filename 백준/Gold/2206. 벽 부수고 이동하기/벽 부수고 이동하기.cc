#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct Node {
	int r, c, w;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char tmp;
	char d[2][4] = {{-1,1,0,0},{0,0,-1,1}};
	int R, C, ans = INF, nr, nc, Smin, Emin, i, j, k;
	int M[1000][1000][2];  // M[i][j][0] : (0,0)에서 (i,j) 거리, M[i][j][1] : (R-1,C-1)에서 (i,j) 거리 
	queue<Node> bfs;
	
	cin >> R >> C;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> tmp;
			if(tmp == '1')
				M[i][j][0] = -1, M[i][j][1] = -1;
			else
				M[i][j][0] = INF, M[i][j][1] = INF;
		}
	}
	
	M[0][0][0] = 1;
	bfs.push({0, 0, 1});
	while(!bfs.empty()) {
		int& r = bfs.front().r;
		int& c = bfs.front().c;
		int& w = bfs.front().w;
		if(r == R - 1 && c == C - 1) {
			ans = w;
		}
		for(i = 0; i < 4; i++) {
			nr = r + d[0][i];
			nc = c + d[1][i];
			if(0 <= nr&&nr < R && 0 <= nc&&nc < C && M[nr][nc][0] == INF) {
				M[nr][nc][0] = w + 1;
				bfs.push({nr, nc, M[nr][nc][0]});
			}
		}
		bfs.pop();
	}
	
	M[R - 1][C - 1][1] = 1;
	bfs.push({R - 1, C - 1, 1});
	while(!bfs.empty()) {
		int& r = bfs.front().r;
		int& c = bfs.front().c;
		int& w = bfs.front().w;
		for(i = 0; i < 4; i++) {
			nr = r + d[0][i];
			nc = c + d[1][i];
			if(0 <= nr&&nr < R && 0 <= nc&&nc < C && M[nr][nc][1] == INF) {
				M[nr][nc][1] = w + 1;
				bfs.push({nr, nc, M[nr][nc][1]});
			}
		}
		bfs.pop();
	}
	
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(M[i][j][0] != -1) continue;
			Smin = INF;
			Emin = INF;
			for(k = 0; k < 4; k++) {
				nr = i + d[0][k];
				nc = j + d[1][k];
				if(0 <= nr&&nr < R && 0 <= nc&&nc < C) {
					if(M[nr][nc][0] != -1) {
						Smin = min(Smin, M[nr][nc][0]);
					}
					if(M[nr][nc][1] != -1) {
						Emin = min(Emin, M[nr][nc][1]);
					}
				}
			}
			ans = min(ans, Smin + Emin + 1);
		}
	}
	
	cout << (ans >= INF ? -1 : ans);
	
	return 0;
}