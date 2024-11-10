#include <bits/stdc++.h>
using namespace std;

int N, ans = 0x3f3f3f3f;
int M[21][21];
vector<char> player;

void compare() {
	int i, j;
	int team[2] = { 0 };
	for(i = 0; i < N; i++) {
		for(j = i + 1; j < N; j++) {
			if(player[i] == player[j]) {
				team[player[i]] += M[i][j];
			}
		}
	}
	ans = min(ans, abs(team[0] - team[1]));
}

void comb(int start, int depth) {
	if(depth == N / 2) {
		compare();
		return;
	}
	for(int i = start; i < N; i++) {
		player[i] = 1;
		comb(i + 1, depth + 1);
		player[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i, j;
	
	cin >> N;
	
	player.resize(N, 0);
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			cin >> M[i][j];
	for(i = 0; i < N; i++)
		for(j = i + 1; j < N; j++)
			M[i][j] += M[j][i];
	
	comb(0, 0);
	cout << ans;
	
	return 0;
}