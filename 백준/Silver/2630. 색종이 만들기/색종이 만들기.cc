#include <bits/stdc++.h>
using namespace std;

int N;
int num[2] = { 0, 0 };
vector<vector<short>> paper;

void dfs(int row, int col, int size) {
	if(size == 1) {
		num[paper[row][col]]++;
		return;
	}
	bool chk = true;
	for(int i = row; i < row + size; i++) {
		for(int j = col; j < col + size; j++) {
			if(paper[i][j] != paper[row][col]) {
				chk = false;
				break;
			}
		}
		if(!chk) break;
	}
	if(chk) num[paper[row][col]]++;
	else {
		size /= 2;
		dfs(row, col, size);
		dfs(row + size, col, size);
		dfs(row, col + size, size);
		dfs(row + size, col + size, size);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	
	cin >> N;
	paper.assign(N, vector<short>(N, 0));
	for(auto& r : paper) {
		for(auto& c : r) {
			cin >> c;
		}
	}
	dfs(0, 0, N);
	cout << num[0] << "\n" << num[1];
	
	return 0;
}