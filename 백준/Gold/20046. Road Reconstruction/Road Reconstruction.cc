#include <bits/stdc++.h>
using namespace std;

struct NODE {
	short r;
	short c;
	int cost;
};

struct compare {
	bool operator()(const NODE& a, const NODE& b) {
		return a.cost > b.cost;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int R, C, n, result = -1, cost, i, j;
	short r, c, tr, tc;
	char d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	vector<vector<char>> city;
	vector<vector<bool>> visited;
	priority_queue<NODE, vector<NODE>, compare> bfs;
	
	cin >> R >> C;
	city.assign(R, vector<char>(C, 0));
	visited.assign(R, vector<bool>(C, false));
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> n;
			city[i][j] = n;
		}
	}
	
	if(city[0][0] == -1) {
		cout << -1;
		return 0;
	}
	bfs.push({0, 0, city[0][0]});
	visited[0][0] = true;
	while(!bfs.empty()) {
		r = bfs.top().r;
		c = bfs.top().c;
		cost = bfs.top().cost;
		bfs.pop();
		
		if(r == R-1 && c == C-1) {
			result = cost;
			break;
		}
		
		for(i = 0; i < 4; i++) {
			tr = r + d[i][0];
			tc = c + d[i][1];
			if(0 <= tr && tr < R && 0 <= tc && tc < C && city[tr][tc] != -1 && !visited[tr][tc]) {
				bfs.push({tr, tc, cost + city[tr][tc]});
				visited[tr][tc] = true;
			}
		}
	}
	cout << result;
	
	return 0;
}