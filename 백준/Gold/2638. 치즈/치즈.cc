#include <bits/stdc++.h>
using namespace std;

struct Cheese {
	int r, c, t;
};

char d[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
int R, C;
vector<vector<char>> S;

void dfs(int r, int c) {
	int nr, nc, i;
	for(i = 0; i < 4; i++) {
		nr = r + d[0][i];
		nc = c + d[1][i];
		if(0 <= nr&&nr < R && 0 <= nc&&nc < C && !S[nr][nc]) {
			S[nr][nc] = -1;
			dfs(nr, nc);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T = 0, tmp, nr, nc, i, j;
	queue<Cheese> cheese;  // 치즈 좌표와 살아남은 시간 저장 
	queue<pair<int,int>> melt;
	
	cin >> R >> C;
	
	S.resize(R, vector<char>(C));
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> tmp;
			S[i][j] = tmp;
			if(tmp) cheese.push({i, j, 1});
		}
	}
	
	S[0][0] = -1;
	dfs(0, 0);
	
	while(!cheese.empty()) {
		T = cheese.front().t;
		while(cheese.front().t == T) {
			int& r = cheese.front().r;
			int& c = cheese.front().c;
			for(tmp = 0, i = 0; i < 4; i++) {
				nr = r + d[0][i];
				nc = c + d[1][i];
				if(S[nr][nc] == -1) tmp++;
			}
			if(tmp >= 2) {
				melt.push({r, c});
			} else {
				cheese.push({r, c, T + 1});
			}
			cheese.pop();
		}
		while(!melt.empty()) {
			int& r = melt.front().first;
			int& c = melt.front().second;
			S[r][c] = -1;
			dfs(r, c);
			melt.pop();
		}
	}
	
	cout << T;
	
	return 0;
}