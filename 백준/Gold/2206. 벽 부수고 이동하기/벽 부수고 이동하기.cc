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
	vector<vector<pair<int,int>>> M;  // (0,0)에서 거리, (R-1,C-1)에서 거리 
	queue<Node> bfs;
	
	cin >> R >> C;
	M.assign(R, vector<pair<int,int>>(C, pair<int,int>({INF, INF})));
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> tmp;
			if(tmp == '1') M[i][j] = { -1, -1 };
		}
	}
	
	if(M[0][0].first != -1) {
		M[0][0].first = 1;
		bfs.push({0, 0, 1});
	}
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
			if(0 <= nr&&nr < R && 0 <= nc&&nc < C && M[nr][nc].first == INF) {
				M[nr][nc].first = w + 1;
				bfs.push({nr, nc, M[nr][nc].first});
			}
		}
		bfs.pop();
	}
	
	if(M[R - 1][C - 1].first != -1) {
		M[R - 1][C - 1].second = 1;
		bfs.push({R - 1, C - 1, 1});
	}
	while(!bfs.empty()) {
		int& r = bfs.front().r;
		int& c = bfs.front().c;
		int& w = bfs.front().w;
		for(i = 0; i < 4; i++) {
			nr = r + d[0][i];
			nc = c + d[1][i];
			if(0 <= nr&&nr < R && 0 <= nc&&nc < C && M[nr][nc].second == INF) {
				M[nr][nc].second = w + 1;
				bfs.push({nr, nc, M[nr][nc].second});
			}
		}
		bfs.pop();
	}
	
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(M[i][j].first != -1) continue;
			Smin = INF;
			Emin = INF;
			for(k = 0; k < 4; k++) {
				nr = i + d[0][k];
				nc = j + d[1][k];
				if(0 <= nr&&nr < R && 0 <= nc&&nc < C) {
					if(M[nr][nc].first != -1) {
						Smin = min(Smin, M[nr][nc].first);
					}
					if(M[nr][nc].second != -1) {
						Emin = min(Emin, M[nr][nc].second);
					}
				}
			}
			ans = min(ans, Smin + Emin + 1);
		}
	}
	
	if(M[0][0].first == -1) {
		if(M[0][1].second != -1 && M[1][0].second != -1) {
			ans = min(M[0][1].second, M[1][0].second) + 1;
		} else if(M[0][1].second != -1) {
			ans = M[0][1].second + 1;
		} else if(M[1][0].second != -1) {
			ans = M[1][0].second + 1;
		}
	}
	if(M[R - 1][C - 1].second == -1) {
		if(M[R - 2][C - 1].first != -1 && M[R - 1][C - 2].first != -1) {
			ans = min(M[R - 2][C - 1].first, M[R - 1][C - 2].first) + 1;
		} else if(M[R - 2][C - 1].first != -1) {
			ans = M[R - 2][C - 1].first + 1;
		} else if(M[R - 1][C - 2].first != -1) {
			ans = M[R - 1][C - 2].first + 1;
		}
	}
	
	cout << (ans >= INF ? -1 : ans);
	
	return 0;
}