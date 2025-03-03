#include <bits/stdc++.h>
using namespace std;

struct STATUS {
	int Rr, Rc, Br, Bc;
};

char board[11][11];
int R, C;

// 0:N, 1:E, 2:S, 3:W
STATUS tilt(STATUS s, int dir) {
	int d = (dir == 0 || dir == 3 ? -1 : 1);
	int Rr = s.Rr, Rc = s.Rc, Br = s.Br, Bc = s.Bc; 
	
	if(dir == 0 || dir == 2) {	// 세로 움직임 
		while(board[Rr + d][Rc] != '#' && (Rr + d != Br || Rc != Bc)) {
			Rr += d;
			if(board[Rr][Rc] == 'O') {
				Rr = 0, Rc = 0;
				break;
			}
		}
		while(board[Br + d][Bc] != '#' && (Br + d != Rr || Bc != Rc)) {
			Br += d;
			if(board[Br][Bc] == 'O')
				return { -1, -1, -1, -1 };
		}
		if(Rr != 0) {	// 구멍에 빠지지 않았으면 
			while(board[Rr + d][Rc] != '#' && (Rr + d != Br || Rc != Bc)) {
				Rr += d;
				if(board[Rr][Rc] == 'O') {
					Rr = 0, Rc = 0;
					break;
				}
			}
		}
	}
	else {	// 가로 움직임 
		while(board[Rr][Rc + d] != '#' && (Rr != Br || Rc + d != Bc)) {
			Rc += d;
			if(board[Rr][Rc] == 'O') {
				Rr = 0, Rc = 0;
				break;
			}
		}
		while(board[Br][Bc + d] != '#' && (Br != Rr || Bc + d != Rc)) {
			Bc += d;
			if(board[Br][Bc] == 'O')
				return { -1, -1, -1, -1 };
		}
		if(Rr != 0) {
			while(board[Rr][Rc + d] != '#' && (Rr != Br || Rc + d != Bc)) {
				Rc += d;
				if(board[Rr][Rc] == 'O') {
					Rr = 0, Rc = 0;
					break;
				}
			}
		} 
	}
	
	return { Rr, Rc, Br, Bc };
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i, j;
	STATUS stat;
	bool visited[11][11][11][11] = { false };	// 이미 방문한 상태 저장 
	queue<pair<STATUS, int>> q;
	
	cin >> R >> C;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> board[i][j];
			if(board[i][j] == 'R')
				stat.Rr = i, stat.Rc = j;
			if(board[i][j] == 'B')
				stat.Br = i, stat.Bc = j;
		}
	}
	board[stat.Rr][stat.Rc] = '.';
	board[stat.Br][stat.Bc] = '.';
	
	visited[stat.Rr][stat.Rc][stat.Br][stat.Bc] = true;
	q.push({stat, 0});
	while(q.front().second <= 9 && !q.empty()) {
		STATUS& curStat = q.front().first;
		int& cnt = q.front().second;
		
		for(i = 0; i < 4; i++) {
			stat = tilt(curStat, i);
			if(visited[stat.Rr][stat.Rc][stat.Br][stat.Bc]) continue;	// 이미 방문함
			if(stat.Rr == -1) continue;	// 실패
			if(stat.Rr == 0) {	// 성공 
				cout << cnt + 1;
				return 0;
			} 
			q.push({stat, cnt + 1});
			visited[stat.Rr][stat.Rc][stat.Br][stat.Bc] = true;
		}
		
		q.pop();
	}
	
	cout << "-1";
	
	return 0;
}