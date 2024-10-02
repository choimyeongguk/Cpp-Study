#include <bits/stdc++.h>
using namespace std;

typedef struct {
	short r;
	short c;
	int day;
} BOX;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int day = 0;
	short C, R, numRaw = 0, r, c, i, j;
	char d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	vector<vector<short>> tomato;
	queue<BOX> bfs;
	
	cin >> C >> R;
	tomato.assign(R, vector<short>(C));
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> tomato[i][j];
			if(tomato[i][j] == 1) {
				bfs.push({i, j, 0});
			}
			if(tomato[i][j] == 0) {
				numRaw++;
			}
		}
	}

	while(!bfs.empty()) {
		r = bfs.front().r;
		c = bfs.front().c;
		day = bfs.front().day;
		bfs.pop();
		
		for(i = 0; i < 4; i++) {
			r += d[i][0];
			c += d[i][1];
			if(0 <= r && r < R && 0 <= c && c < C && !tomato[r][c]) {
				tomato[r][c]++;
				numRaw--;
				bfs.push({r, c, day + 1});
			}
			r -= d[i][0];
			c -= d[i][1];
		}
	}
	
	if(numRaw) {
		cout << -1;
	} else {
		cout << day;
	}
	
	return 0;
}