#include <bits/stdc++.h>
using namespace std;

char d[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
int city[50][50];
int N, M, ans = 0x3f3f3f3f;
vector<pair<int,int>> chicken;
vector<int> idx;

void bfs() {
	int dist = 0, nr, nc, i;
	queue<pair<int,pair<int,int>>> q;
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	
	for(auto& e : idx) {
		q.push({0, chicken[e]});
		visited[chicken[e].first][chicken[e].second] = true;
	}
	
	while(!q.empty()) {
		int& w = q.front().first;
		int& r = q.front().second.first;
		int& c = q.front().second.second;
		
		if(city[r][c] == 1) dist += w;
		if(dist >= ans) break;
		
		for(i = 0; i < 4; i++) {
			nr = r + d[0][i];
			nc = c + d[1][i];
			if(0 <= nr&&nr < N && 0 <= nc&&nc < N && !visited[nr][nc]) {
				visited[nr][nc] = true;
				q.push({w + 1, {nr, nc}});
			}
		}
		q.pop();
	}
	
	ans = min(ans, dist);
}

void choose(int start, int depth) {
	if(depth == M) {
		bfs();
		return;
	}
	for(int i = start; i < chicken.size(); i++) {
		idx.push_back(i);
		choose(i + 1, depth + 1);
		idx.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> city[i][j];
			if(city[i][j] == 2)
				chicken.push_back({i, j});
		}
	}

	choose(0, 0);
	cout << ans;
	
	return 0;
}