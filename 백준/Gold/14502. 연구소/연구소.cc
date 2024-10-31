#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char d[2][4] = {{ -1, 1, 0, 0 }, { 0, 0, -1, 1 }};
	int R, C, numSafe, infected, min, tmp, nr, nc, i, j, k, l;
	char lab[8][8];
	bool visited[8][8];
	vector<pair<int,int>> start;
	
	cin >> R >> C;
	
	for(numSafe = 0, i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> tmp;
			lab[i][j] = tmp;
			if(tmp == 2) {
				start.push_back({ i, j });
			} else if(tmp == 0) numSafe++;
		}
	}
	
	for(min = R * C, i = 0; i < R * C; i++) {
		if(lab[i / C][i % C]) continue;
		lab[i / C][i % C] = 1;
		for(j = i + 1; j < R * C; j++) {
			if(lab[j / C][j % C]) continue;
			lab[j / C][j % C] = 1;
			for(k = j + 1; k < R * C; k++) {
				if(lab[k / C][k % C]) continue;
				lab[k / C][k % C] = 1;
				
				for(auto& r : visited) for(auto& c : r) c = false;
				queue<pair<int,int>> bfs;
				for(auto& e : start) {
					bfs.push(e);
					visited[e.first][e.second] = true;
				}
				infected = 0;
				while(!bfs.empty()) {
					int& r = bfs.front().first;
					int& c = bfs.front().second;
					for(l = 0; l < 4; l++) {
						nr = r + d[0][l];
						nc = c + d[1][l];
						if(0 <= nr&&nr < R && 0 <= nc&&nc < C && !lab[nr][nc] && !visited[nr][nc]) {
							bfs.push({nr, nc});
							visited[nr][nc] = true;
							infected++;
						}
					}
					if(infected > min) break;
					bfs.pop();
				}
				min = min < infected ? min : infected;
				
				lab[k / C][k % C] = 0;
			}
			lab[j / C][j % C] = 0;
		}
		lab[i / C][i % C] = 0;
	}
	cout << numSafe - min - 3;
	
	return 0;
}