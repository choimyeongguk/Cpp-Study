#include <bits/stdc++.h>
using namespace std;

bool row[9][10] = { false };	// row[i][j]=true/false : i번째 행에는 j가 있다/없다 
bool col[9][10] = { false };
bool box[9][10] = { false };
char table[9][9];
vector<pair<int,int>> blank;

bool back_track(int depth) {
	if(depth == blank.size()) {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				cout << table[i][j];
			}
			cout << "\n";
		}
		return true;
	}
	
	int r = blank[depth].first;
	int c = blank[depth].second;
	for(int i = 1; i < 10; i++) {
		if(row[r][i] || col[c][i] || box[(r / 3) * 3 + (c / 3)][i])
			continue;
			
		table[r][c] = i + '0';
		row[r][i] = true;
		col[c][i] = true;
		box[(r / 3) * 3 + (c / 3)][i] = true;
		
		bool chk = back_track(depth + 1);
		
		if(chk) return true;	// 스도쿠 완성 시 탐색 종료 
		
		row[r][i] = false;
		col[c][i] = false;
		box[(r / 3) * 3 + (c / 3)][i] = false;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			cin >> table[i][j];
			if(table[i][j] != '0') {
				row[i][table[i][j] - '0'] = true;
				col[j][table[i][j] - '0'] = true;
				box[(i / 3) * 3 + (j / 3)][table[i][j] - '0'] = true;
			}
			else {
				blank.push_back({i, j});
			}
		}
	}
	
	back_track(0);
	
	return 0;
}