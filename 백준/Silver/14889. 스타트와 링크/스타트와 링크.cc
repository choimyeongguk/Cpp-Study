#include <bits/stdc++.h>
using namespace std;

int N, ans = 0x3f3f3f3f;
int M[21][21];
char player[21];

void compare() {
	vector<int> team0;
	vector<int> team1;
	int team[2] = { 0 };
	for(int i = 0; i < N; i++) {
		if(player[i]) team1.push_back(i);
		else team0.push_back(i);
	}
	for(int i = 0; i < team0.size(); i++) {
		for(int j = 0; j < team0.size(); j++) {
			team[0] += M[team0[i]][team0[j]];
			team[1] += M[team1[i]][team1[j]];
		}
	}
	ans = min(ans, abs(team[0] - team[1]));
}

void comb(int start, int depth) {
	if(depth++ == N >> 1) {
		compare();
		return;
	}
	for(int i = start; i < N; i++) {
		player[i] = 1;
		comb(i + 1, depth);
		player[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> M[i][j];
	comb(0, 0);
	cout << ans;
	
	return 0;
}