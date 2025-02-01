#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int R, C, roomNum, nr, nc, sum, i, j, k, l;
	char d[2][4] = {{ -1, 1, 0, 0 }, { 0, 0, -1, 1 }};
	char M[1000][1000];
	int num[1000][1000] = { 0 };	// 방 번호 
	int size[1000000] = { 0 };		// 각 방번호 별 크기 
	bool visited[1000][1000];
	queue<pair<int,int>> q;
	unordered_set<int> nearbyroom;
	
	cin >> R >> C;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> M[i][j];
			M[i][j] -= '0';
		}
	}
	
	roomNum = 1;
	for(i = 0; i < R; i++) {
		for(j= 0; j < C; j++) {
			if(M[i][j] || num[i][j]) continue;
			
			while(!q.empty()) q.pop();
			for(k = 0; k < R; k++) {
				for(l = 0; l < C; l++) {
					visited[k][l] = false;
				}
			}
			
			q.push({ i, j });
			visited[i][j] = true;
			while(!q.empty()) {
				int& r = q.front().first;
				int& c = q.front().second;
				num[r][c] = roomNum;
				size[roomNum]++;
				for(k = 0; k < 4; k++) {
					nr = r + d[0][k];
					nc = c + d[1][k];
					if(nr < 0 || nr == R || nc < 0 || nc == C || visited[nr][nc]) continue;
					if(M[nr][nc] || num[nr][nc]) continue;
					q.push({ nr, nc });
					visited[nr][nc] = true;
				}
				q.pop();
			}
			
			roomNum++;
		}
	}
	
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(!M[i][j]) continue;
			nearbyroom.clear();
			for(k = 0; k < 4; k++) {
				nr = i + d[0][k];
				nc = j + d[1][k];
				if(nr < 0 || nr == R || nc < 0 || nc == C) continue;
				nearbyroom.insert(num[nr][nc]);
			}
			sum = 0;
			for(const auto& e : nearbyroom) {
				sum += size[e];
			}
			M[i][j] = (1 + sum) % 10;
		}
	}
	
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cout << (int)M[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}