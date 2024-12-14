#include <bits/stdc++.h>
using namespace std;

int R, C;
char dirMap[1000][1000];
bool visited[1000][1000] = { false };

void dfs(int r, int c) {
	visited[r][c] = true;
	if(r > 0 && !visited[r - 1][c] && dirMap[r - 1][c] == 'D') dfs(r - 1, c);
	if(r < R - 1 && !visited[r + 1][c] && dirMap[r + 1][c] == 'U') dfs(r + 1, c);
	if(c > 0 && !visited[r][c - 1] && dirMap[r][c - 1] == 'R') dfs(r, c - 1);
	if(c < C - 1 && !visited[r][c + 1] && dirMap[r][c + 1] == 'L') dfs(r, c + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int ans = 0, r, c, dr, dc, i, j;
	map<char,pair<int,int>> dir = { {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
	
	cin >> R >> C;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> dirMap[i][j];
		}
	}
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(visited[i][j]) continue;
			ans++;
			r = i, c = j;
			while(!visited[r][c]) {
				visited[r][c] = true;
				dfs(r, c);
				dr = dir[dirMap[r][c]].first;
				dc = dir[dirMap[r][c]].second;
				r += dr, c += dc;
			}
		}
	}
	cout << ans;
	
	return 0;
}