#include <bits/stdc++.h>
using namespace std;

struct CCTV {
	int type, r, c;
};

int R, C;
int safe = 0, maxSafe = 0;
int input[8][8], room[8][8] = { 0 };
deque<CCTV> cctv;

// 0:N, 1:E, 2:S, 3:W
void mark(int dir, int r, int c) {
	int d = (dir == 0 || dir == 3 ? -1 : 1);
	if(dir == 0 || dir == 2) {
		while(0 <= r && r < R && 0 <= c && c < C) {
			if(input[r][c] == 6) break;
			else if(input[r][c] > 0) r += d;
			else {
				if(!room[r][c]) safe++;
				room[r][c]++;
				r += d;
			}
		}
	}
	else {
		while(0 <= r && r < R && 0 <= c && c < C) {
			if(input[r][c] == 6) break;
			else if(input[r][c] > 0) c += d;
			else {
				if(!room[r][c]) safe++;
				room[r][c]++;
				c += d;
			}
		}
	}
}

void erase(int dir, int r, int c) {
	int d = (dir == 0 || dir == 3 ? -1 : 1);
	if(dir == 0 || dir == 2) {
		while(0 <= r && r < R && 0 <= c && c < C) {
			if(input[r][c] == 6) break;
			else if(input[r][c] > 0) r += d;
			else {
				room[r][c]--;
				if(!room[r][c]) safe--;
				r += d;
			}
		}
	}
	else {
		while(0 <= r && r < R && 0 <= c && c < C) {
			if(input[r][c] == 6) break;
			else if(input[r][c] > 0) c += d;
			else {
				room[r][c]--;
				if(!room[r][c]) safe--;
				c += d;
			}
		}
	}
}

void back_track(int depth) {
	if(depth == cctv.size()) {
		maxSafe = maxSafe > safe ? maxSafe : safe;
		return;
	}
	
	int type = cctv[depth].type;
	int r = cctv[depth].r;
	int c = cctv[depth].c;
	int i, j;
	depth++;
	
	if(type == 1) {
		for(i = 0; i < 4; i++) {
			mark(i, r, c);
			back_track(depth);
			erase(i, r, c);
		}
	}
	else if(type == 2) {
		mark(0, r, c); mark(2, r, c);
		back_track(depth);
		erase(0, r, c); erase(2, r, c);
		mark(1, r, c); mark(3, r, c);
		back_track(depth);
		erase(1, r, c); erase(3, r, c);
	}
	else if(type == 3) {
		for(i = 0; i < 4; i++) {
			mark(i, r, c); mark((i + 1) % 4, r, c);
			back_track(depth);
			erase(i, r, c); erase((i + 1) % 4, r, c);
		}
	}
	else {
		for(i = 0; i < 4; i++) {
			for(j = 1; j < 4; j++) {
				mark((i + j) % 4, r, c);
			}
			back_track(depth);
			for(j = 1; j < 4; j++) {
				erase((i + j) % 4, r, c);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i, j, blindSpot = 0;
	
	cin >> R >> C;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			cin >> input[i][j];
			if(!input[i][j]) blindSpot++;
			if(0 < input[i][j] && input[i][j] < 6) {
				cctv.push_back({input[i][j], i, j});
			}
		}
	}
	
	sort(cctv.begin(), cctv.end(), [](CCTV& a, CCTV& b){
		return a.type > b.type;
	});
	while(cctv.front().type == 5) {
		int& r = cctv.front().r;
		int& c = cctv.front().c;
		for(i = 0; i < 4; i++) {
			mark(i, r, c);
		}
		cctv.pop_front();
	}
	
	back_track(0);
	cout << blindSpot - maxSafe;
	
	return 0;
}