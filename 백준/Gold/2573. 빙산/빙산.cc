#include <bits/stdc++.h>
using namespace std;

bool visited[300][300] = { 0 };
int M[300][300];
int d[2][4] = {{ -1, 1, 0, 0 }, { 0, 0, -1, 1 }};

int getIcebergSize(pair<int,int> x) {
	int ret = 1, nr, nc, i;
	visited[x.first][x.second] = true;
	for(i = 0; i < 4; i++) {
		nr = x.first + d[0][i];
		nc = x.second + d[1][i];
		if(M[nr][nc] && !visited[nr][nc])
			ret += getIcebergSize({ nr, nc });
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int R, C, ans, cnt, i, j;
	deque<pair<int,pair<int,int>>> iceberg;
	
	cin >> R >> C;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> M[i][j];
			if(M[i][j])
				iceberg.push_back({ M[i][j], { i, j }});
		}
	}
	
	ans = 0;
	while(getIcebergSize(iceberg.front().second) == iceberg.size()) {
		for(i = 0; i < R; i++)
			for(j = 0; j < C; j++)
				visited[i][j] = false;
		ans++;
		for(auto& e : iceberg) {
			int& r = e.second.first;
			int& c = e.second.second;
			for(cnt = 0, i = 0; i < 4; i++) {
				if(!M[r + d[0][i]][c + d[1][i]])
					cnt++;
			}
			e.first -= cnt;
		}
		for(i = 0; i < iceberg.size(); i++) {
			int& h = iceberg[i].first;
			int& r = iceberg[i].second.first;
			int& c = iceberg[i].second.second;
			if(h > 0)
				M[r][c] = h;
			else {
				M[r][c] = 0;
				iceberg.erase(iceberg.begin() + i--);
			}
		}
	}
	cout << (!iceberg.size() ? 0 : ans);
	
	return 0;
}