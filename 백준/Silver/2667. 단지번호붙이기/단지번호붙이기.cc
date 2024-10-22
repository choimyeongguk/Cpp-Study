#include <bits/stdc++.h>
using namespace std;

char d[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
int N, house;
vector<vector<int>> sqMap;
vector<int> num;

void dfs(int r, int c) {
	num[house]++;
	for(int i = 0; i < 4; i++) {
		int nr = r + d[i][0];
		int nc = c + d[i][1];
		if(0<=nr&&nr<N && 0<=nc&&nc<N && sqMap[nr][nc]) {
			sqMap[nr][nc] = 0;
			dfs(nr, nc);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char tmp;
	int i, j;
	
	cin >> N;
	sqMap.resize(N, vector<int>(N));
	for(auto& r : sqMap) {
		for(auto& c : r) {
			cin >> tmp;
			c = tmp - '0';
		}
	}
	
	house = 0;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(sqMap[i][j]) {
				num.push_back(0);
				sqMap[i][j] = 0;
				dfs(i, j);
				house++;
			}
		}
	}
	sort(num.begin(), num.end());
	cout << house << "\n";
	for(auto& e : num) {
		cout << e << "\n";
	}
	
	return 0;
}