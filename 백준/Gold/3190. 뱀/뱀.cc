#include <bits/stdc++.h>
using namespace std;
enum Dummy { NONE, APPLE, SNAKE };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char C;
	int N, K, L, X, T, dir, r, c, i;
	int d[2][4] = {{-1, 0, 1, 0},{0, 1, 0, -1}};
	int board[101][101] = { 0 };
	queue<pair<int,char>> control;
	deque<pair<int,int>> snake;
	
	cin >> N >> K;
	for(i = 0; i < K; i++) {
		cin >> r >> c;
		board[r][c] = APPLE;
	}
	cin >> L;
	for(i = 0; i < L; i++) {
		cin >> X >> C;
		control.push({X, C});
	}
	
	dir = 1;
	board[1][1] = SNAKE;
	snake.push_back({1, 1});
	for(T = 1; ;T++) {
		r = snake.front().first + d[0][dir];
		c = snake.front().second + d[1][dir];
		if(r < 1 || r > N || c < 1 || c > N || board[r][c] == SNAKE) {
			break;
		}
		if(board[r][c] != APPLE) {
			board[snake.back().first][snake.back().second] = NONE;
			snake.pop_back();
		}
		board[r][c] = SNAKE;
		snake.push_front({r, c});
		
		if(T == control.front().first) {
			if(control.front().second == 'L') {
				dir = (dir + 3) % 4;
			}
			else {
				dir = (dir + 1) % 4;
			}
			control.pop();
		}
	}
	cout << T;
	
	return 0;
}