#include <bits/stdc++.h>
using namespace std;

void solve() {
	int l, sr, sc, er, ec, nxtR, nxtC, i;
	int dr[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int dc[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	vector<vector<bool>> visited;
	queue<pair<int,pair<int,int>>> q;
	
	cin >> l >> sr >> sc >> er >> ec;
	
	visited.assign(l, vector<bool>(l, false));
	visited[sr][sc] = true;
	q.push({ 0, { sr, sc } });
	while(true) {
		int& curM = q.front().first;
		int& curR = q.front().second.first;
		int& curC = q.front().second.second;
		if(curR == er && curC == ec)
			break;
		for(i = 0; i < 8; i++) {
			nxtR = curR + dr[i];
			nxtC = curC + dc[i];
			if(nxtR < 0 || nxtR >= l || nxtC < 0 || nxtC >= l)
				continue;
			if(!visited[nxtR][nxtC]) {
				visited[nxtR][nxtC] = true;
				q.push({ curM + 1, { nxtR, nxtC } });
			}
		}
		q.pop();
	}
	cout << q.front().first << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--)
		solve();
	
	return 0;
}