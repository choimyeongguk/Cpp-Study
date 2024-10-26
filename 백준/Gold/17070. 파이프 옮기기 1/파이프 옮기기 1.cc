#include <bits/stdc++.h>
using namespace std;

struct Pipe {
	int r, c, status;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans = 0;
	vector<vector<int>> pipe;
	queue<Pipe> bfs;
	
	cin >> N;
	pipe.resize(N, vector<int>(N));
	for(auto& r : pipe) {
		for(auto& c : r) {
			cin >> c;
			if(c) c -=2;
		}
	}
	bfs.push({0, 1, 0});
	while(!bfs.empty()) {
		int& r = bfs.front().r;
		int& c = bfs.front().c;
		int& s = bfs.front().status;
		if(r == N - 1 && c == N - 1) {
			ans++;
			bfs.pop();
			continue;
		}
		if(s != 1 && c + 1 < N && pipe[r][c + 1] >= 0) {
			bfs.push({r, c + 1, 0});
		}
		if(s != 0 && r + 1 < N && pipe[r + 1][c] >= 0) {
			bfs.push({r + 1, c, 1});
		}
		if(c + 1 < N && r + 1 < N && pipe[r + 1][c + 1] >= 0 && pipe[r + 1][c] >= 0 && pipe[r][c + 1] >= 0) {
			bfs.push({r + 1, c + 1, 2});
		}
		bfs.pop();
	}
	cout << ans;
	
	return 0;
}
