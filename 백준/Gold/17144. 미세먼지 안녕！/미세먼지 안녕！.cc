#include <bits/stdc++.h>
using namespace std;

struct Dust {
	int row, col, val;
};

int R, C;
vector<int> purifier;
vector<vector<int>> room;
queue<Dust> dust;

void spread() {
	int nxtR, nxtC, nxtV, i;
	int d[2][4] = {{ -1, 1, 0, 0 }, { 0, 0, -1, 1 }};
	
	while(!dust.empty()) {
		int& curR = dust.front().row;
		int& curC = dust.front().col;
		int& curV = dust.front().val;
		for(i = 0; i < 4; i++) {
			nxtR = curR + d[0][i];
			nxtC = curC + d[1][i];
			nxtV = curV / 5;
			if(nxtC == 0 && (nxtR == purifier[0] || nxtR == purifier[1]))
				continue;
			if(nxtR < 0 || nxtR >= R || nxtC < 0 || nxtC >= C)
				continue;
			room[nxtR][nxtC] += nxtV;
			room[curR][curC] -= nxtV;
		}
		dust.pop();
	}
}

void circulate() {
	int tmp, i, j;
	
	tmp = room[0][0];
	for(i = 0; i < C - 1; i++)
		room[0][i] = room[0][i + 1];
	for(i = 0; i < purifier[0]; i++)
		room[i][C - 1] = room[i + 1][C - 1];
	for(i = C - 1; i > 0; i--)
		room[purifier[0]][i] = room[purifier[0]][i - 1];
	for(i = purifier[0]; i > 0; i--)
		room[i][0] = room[i - 1][0];
	room[1][0] = tmp;
	room[purifier[0]][0] = -1;
	room[purifier[0]][1] = 0;
	
	tmp = room[R - 1][0];
	for(i = 0; i < C - 1; i++)
		room[R - 1][i] = room[R - 1][i + 1];
	for(i = R - 1; i > purifier[1]; i--)
		room[i][C - 1] = room[i - 1][C - 1];
	for(i = C - 1; i > 0; i--)
		room[purifier[1]][i] = room[purifier[1]][i - 1];
	for(i = purifier[1]; i < R - 1; i++)
		room[i][0] = room[i + 1][0];
	room[R - 2][0] = tmp;
	room[purifier[1]][0] = -1;
	room[purifier[1]][1] = 0;
	
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(room[i][j] > 0) {
				dust.push({ i, j, room[i][j] });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, ans, i, j;
	
	cin >> R >> C >> T;
	room.resize(R, vector<int>(C));
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> room[i][j];
			if(room[i][j] > 0) {
				dust.push({ i, j, room[i][j] });
			}
			if(room[i][j] == -1) {
				purifier.push_back(i);
			}
		}
	}
	
	while(T--) {
		spread();
		circulate();
	}
	for(ans = 0, i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			ans += room[i][j];
		}
	}
	cout << ans + 2;
	
	return 0;
}