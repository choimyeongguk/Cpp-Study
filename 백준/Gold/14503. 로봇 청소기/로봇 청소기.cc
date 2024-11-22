#include <bits/stdc++.h>
using namespace std;
enum Status { DIRTY, WALL, CLEANED };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk;
	int R, C, r, c, d, nr, nc, cnt = 0, i, j;
	int dir[2][4] = {{-1, 0, 1, 0},{0, 1, 0, -1}};
	int room[50][50];
	
	cin >> R >> C >> r >> c >> d;
	for(i = 0; i < R; i++)
		for(j = 0; j < C; j++)
			cin >> room[i][j];
	
	while(true) {
		if(room[r][c] == DIRTY) {
			room[r][c] = CLEANED;
			cnt++;
		}
		
		for(chk = false, i = 0; i < 4; i++) {
			if(--d < 0) d = 3;
			nr = r + dir[0][d];
			nc = c + dir[1][d];
			if(room[nr][nc] == DIRTY) {
				r = nr;
				c = nc;
				chk = true;
				break;
			}
		}
		if(chk) continue;
		
		nr = r + dir[0][(d + 2) % 4];
		nc = c + dir[1][(d + 2) % 4];
		if(room[nr][nc] == WALL) {
			break;
		} else {
			r = nr;
			c = nc;
		}
	}
	
	cout << cnt;
	
	return 0;
}