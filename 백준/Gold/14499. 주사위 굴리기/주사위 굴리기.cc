#include <bits/stdc++.h>
using namespace std;

class Dice {
public:
	int r, c;
	int N, E, S, W, U, D;
	vector<vector<int>> board;
	
	void init(int R, int C, int x, int y) {
		board.resize(R, vector<int>(C));
		for(auto& i : board)
			for(auto& j : i)
				cin >> j;
		r = x, c = y;
		N = 0, E = 0, S = 0, W = 0, U = 0, D = 0;
	}
	
	void check() {
		if(board[r][c] == 0) {
			board[r][c] = D;
		}
		else {
			D = board[r][c];
			board[r][c] = 0;
		}
		cout << U << "\n";
	}
	
	void east() {
		if(c == board[0].size() - 1) return;
		int tmp = D; D = E; E = U; U = W; W = tmp;
		c++;
		check();
	}
	
	void west() {
		if(c == 0) return;
		int tmp = D; D = W; W = U; U = E; E = tmp;
		c--;
		check();
	}
	
	void north() {
		if(r == 0) return;
		int tmp = D; D = N; N = U; U = S; S = tmp;
		r--;
		check();
	}
	
	void south() {
		if(r == board.size() - 1) return;
		int tmp = D; D = S; S = U; U = N; N = tmp;
		r++;
		check();
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, x, y, K, op, i;
	Dice dice;
	
	cin >> N >> M >> x >> y >> K;
	dice.init(N, M, x, y);
	for(i = 0; i < K; i++) {
		cin >> op;
		switch(op) {
			case 1:
				dice.east();
				break;
			case 2:
				dice.west();
				break;
			case 3:
				dice.north();
				break;
			case 4:
				dice.south();
				break;
		}
	}
	
	return 0;
}