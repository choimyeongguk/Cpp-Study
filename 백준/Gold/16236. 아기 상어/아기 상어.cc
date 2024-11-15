#include <bits/stdc++.h>
using namespace std;

class BabyShark {
private:
	int size = 2;
	int numFish = 0;
	int nr, nc;
	int d[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
	
public:
	int r, c, N;
	int t = 0;
	int sea[20][20];
		
	void move_to(int d, int x, int y) {
		t += d;
		r = x, c = y;
		sea[r][c] = 0;
		numFish++;
		if(numFish == size) {
			size++;
			numFish = 0;
		}
	}
	
	bool scan() {
		bool visited[20][20] = { false };
		vector<pair<int,pair<int,int>>> fish;
		queue<pair<int,pair<int,int>>> q;
		
		q.push({ 0, { r, c } });
		visited[r][c] = true;
		while(!q.empty()) {
			int& cd = q.front().first;
			int& cr = q.front().second.first;
			int& cc = q.front().second.second;
			if(sea[cr][cc] && sea[cr][cc] < size)
				fish.push_back({ cd, { cr, cc } });
			for(int i = 0; i < 4; i++) {
				nr = cr + d[0][i];
				nc = cc + d[1][i];
				if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || sea[nr][nc] > size)
					continue;
				q.push({ cd + 1, { nr, nc } });
				visited[nr][nc] = true;
			}
			q.pop();
		}
		
		if(fish.empty())
			return false;	
		sort(fish.begin(), fish.end());
		move_to(fish[0].first, fish[0].second.first, fish[0].second.second);
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i, j;
	pair<int,int> fish;
	BabyShark shark;
	
	cin >> shark.N;
	for(i = 0; i < shark.N; i++) {
		for(j = 0; j < shark.N; j++) {
			cin >> shark.sea[i][j];
			if(shark.sea[i][j] == 9) {
				shark.r = i;
				shark.c = j;
				shark.sea[i][j] = 0;
			}
		}
	}
	
	while(shark.scan());
	cout << shark.t;
	
	return 0;
}