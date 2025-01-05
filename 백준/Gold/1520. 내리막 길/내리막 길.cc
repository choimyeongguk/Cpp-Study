#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int R, C, nr, nc, i, j, k;
	int d[2][4] = {{ -1, 1, 0, 0 }, { 0, 0, -1, 1 }};
	int numCase[500][500] = { 0 };
	short board[500][500];
	char in_degree[500][500];
	queue<pair<int,int>> q;
	
	cin >> R >> C;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> board[i][j];
			in_degree[i][j] = -1;
		}
	}
			
	q.push({ 0, 0 });
	while(!q.empty()) {
		int& r = q.front().first;
		int& c = q.front().second;
		for(i = 0; i < 4; i++) {
			nr = r + d[0][i];
			nc = c + d[1][i];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C || board[nr][nc] >= board[r][c])
				continue;
			if(in_degree[nr][nc] == -1) {
				q.push({ nr, nc });
				in_degree[nr][nc] = 0;
			}
			in_degree[nr][nc]++;
		}
		q.pop();
	}
	
//	for(i = 0; i < R; i++) {
//		for(j = 0; j < C; j++) {
//			cout << (int)in_degree[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	numCase[0][0] = 1;
	q.push({ 0, 0 });
	while(!q.empty()) {
		int& r = q.front().first;
		int& c = q.front().second;
		if(r == R - 1 && c == C - 1) break;
		for(i = 0; i < 4; i++) {
			nr = r + d[0][i];
			nc = c + d[1][i];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C || board[nr][nc] >= board[r][c]) continue;
			numCase[nr][nc] += numCase[r][c];
			in_degree[nr][nc]--;
			if(!in_degree[nr][nc])
				q.push({ nr, nc });
		}
		q.pop();
	}
	cout << numCase[R - 1][C - 1];
	
	return 0;
}